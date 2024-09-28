#include <iostream>
#include "client.hpp"

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		cerr << "Usage: client <host> <port>" << endl;
		exit(1);
	}

	string read = R"({"request": "read", "key": "some_key"})";
	string write = R"({"request": "write", "key": "some_key", "value": "some_value"})";

	string invalid_key = R"({"request": "read", "key": "invalid_key"})";
	string invalid_op = R"({"request": "invalid_op", "key": "some_key", "value": "some_value"})";

	string invalid_request = R"({"invalid_request"})";

	Client client;

	string host = argv[1];
	string port = argv[2];
	
	client.send_request(host, port, write);
	client.send_request(host, port, read);
	
	client.send_request(host, port, invalid_key);
	client.send_request(host, port, invalid_op);

	client.send_request(host, port, invalid_request);
}