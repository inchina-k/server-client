#include <boost/asio.hpp>
#include <iostream>

#include "client.hpp"

using namespace std;
using boost::asio::ip::tcp;

void Client::send_request(const std::string& host, const std::string& port, const string &request)
{
	try
	{
		boost::asio::io_context io_context;

		tcp::resolver resolver(io_context);
		tcp::resolver::results_type endpoints = resolver.resolve(host, port);

		tcp::socket socket(io_context);
		boost::asio::connect(socket, endpoints);

		boost::asio::write(socket, boost::asio::buffer(request));

		array<char, 1024> buff;
		boost::system::error_code err;

		size_t len = socket.read_some(boost::asio::buffer(buff), err);
		
		if (err && err != boost::asio::error::eof)
		{
			throw boost::system::system_error(err);
		}

		string response(buff.data(), len);
		cout << response << endl;
	}
	catch (exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
}