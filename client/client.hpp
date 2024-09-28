#include <string>

class Client
{
public:
	Client()
	{
	};

	void send_request(const std::string &host, const std::string &port, const std::string &request);
};