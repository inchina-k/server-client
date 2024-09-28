#include <iostream>
#include "server.hpp"

using namespace std;

int main()
{
	try
	{
		boost::asio::io_context io_context;
		Server server(io_context, 8080);
		io_context.run();
	}
	catch (std::exception &e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
}