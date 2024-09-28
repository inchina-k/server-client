#include <nlohmann/json.hpp>
#include <unordered_map>
#include <mutex>

using json = nlohmann::json;

class Storage
{
	std::mutex m_mtx;
	std::unordered_map<std::string, std::string> m_storage;

public:
	std::string read(const std::string &key);
	std::string write(const std::string &key, const std::string &val);
};