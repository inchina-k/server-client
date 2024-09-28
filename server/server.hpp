#include <boost/asio.hpp>
#include <string>
#include <iostream>

#include "storage.hpp"

using boost::asio::ip::tcp;

class Server
{
	tcp::acceptor m_acceptor;
	Storage m_storage;

	void accept();

	class Session : public std::enable_shared_from_this<Session>
	{
		tcp::socket m_socket;
		Storage &m_storage;
		std::array<char, 1024> m_buffer;

		void read_request();
		void handle_request(const std::string &request);
		void send_response(const std::string &response);

	public:
		Session(tcp::socket socket, Storage &storage)
			: m_socket(std::move(socket)), m_storage(storage)
		{
		}

		void start()
		{
			read_request();
		}
	};

public:
	Server(boost::asio::io_context &io_context, short port)
		: m_acceptor(io_context, tcp::endpoint(tcp::v4(), port)), m_storage()
	{
		std::cout << "Server is running on port: " << std::to_string(port) << std::endl;
		accept();
	}
};