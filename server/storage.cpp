#include "storage.hpp"

using namespace std;

string Storage::read(const string &key)
{
	lock_guard<mutex> lock(m_mtx);

	auto it = m_storage.find(key);

	if (it != m_storage.end())
	{
		return json{{"status", "ok"}, {"value", it->second}}.dump();
	}
	else
	{
		return json{{"status", "error"}, {"description", "key not found"}}.dump();
	}
}

string Storage::write(const string &key, const string &val)
{
	lock_guard<mutex> lock(m_mtx);

	m_storage[key] = val;

	return json{ {"status", "ok"} }.dump();
}