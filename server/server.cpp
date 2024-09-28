#include <nlohmann/json.hpp>
#include <memory>

#include "server.hpp"

using namespace std;
using json = nlohmann::json;

void Server::accept()
{
	m_acceptor.async_accept([this](boost::system::error_code err, tcp::socket socket) {
		if (!err)
		{
			make_shared<Session>(move(socket), m_storage)->start();
		}
		accept();
	});
}

void Server::Session::read_request()
{
	auto self(shared_from_this());
	m_socket.async_read_some(boost::asio::buffer(m_buffer),
		[this, self](boost::system::error_code err, size_t len) {
			if (!err)
			{
				string request(m_buffer.data(), len);
				handle_request(request);
			}
		});
}

void Server::Session::handle_request(const string &request)
{
	try
	{
		auto j_request = json::parse(request);
		string r_type = j_request.at("request").get<string>();
		string response;

		if (r_type == "read")
		{
			string key = j_request.at("key").get<string>();
			response = m_storage.read(key);
		}
		else if (r_type == "write")
		{
			string key = j_request.at("key").get<string>();
			string val = j_request.at("value").get<string>();
			response = m_storage.write(key, val);
		}
		else
		{
			response = json{{"status", "error"}, {"description", "invalid request type"}}.dump();
		}

		send_response(response);
	}
	catch (const json::exception& e)
	{
		string response = json{{"status", "error"}, {"description", e.what()}}.dump();
		send_response(response);
	}
	catch (...)
	{
		string response = json{{"status", "error"}, {"description", "unknown error"}}.dump();
		send_response(response);
	}
}

void Server::Session::send_response(const string &response)
{
	auto self(shared_from_this());
	auto response_ptr = make_shared<string>(response);
	boost::asio::async_write(m_socket, boost::asio::buffer(*response_ptr),
		[this, self, response_ptr](boost::system::error_code ec, size_t) {
			m_socket.close();
		});
}