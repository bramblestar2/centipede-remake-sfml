#pragma once
#include <map>
#include <iostream>
template<typename T, typename U>
class Handler
{
public:
	static U* get(T key);
	static bool free(T key);
	static void freeAll();
protected:
	static std::map<T, U*> m_loaded;
};

template<typename T, typename U>
std::map<T, U*> Handler<T, U>::m_loaded;

template<typename T, typename U>
inline U* Handler<T, U>::get(T key)
{
	auto find = m_loaded.find(key);
	if (find != m_loaded.end())
		return m_loaded[key];
	else
		return nullptr;
}

template<typename T, typename U>
inline bool Handler<T, U>::free(T key)
{
	auto find = m_loaded.find(T);
	if (find != m_loaded.end())
	{
		delete m_loaded[T];
		m_loaded.erase(find);
		return true;
	}
	else
		return false;
}

template<typename T, typename U>
inline void Handler<T, U>::freeAll()
{
	for (auto loaded : m_loaded)
		delete loaded.second;

	m_loaded.clear();

	std::cout << "Handler pointers have been cleared.\n";
}
