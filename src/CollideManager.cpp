#include "CollideManager.h"

CollideManager::CollideManager()
{
}


CollideManager::~CollideManager()
{
	getMap().clear();
}

CollMap& CollideManager::getMap()
{
	static CollMap m_map;

	return m_map;
}


void CollideManager::set(std::pair<std::string, std::string> pair,
	std::function<void(GameObject*&, GameObject*&)> func)
{
	getMap()[pair] = func;
}

void CollideManager::unSet(const std::pair<std::string, std::string>& pair)
{
	if (getMap().find(pair) != getMap().end())
		getMap().erase(pair);
}

void CollideManager::clear()
{
	getMap().clear();
}

void CollideManager::handle_collision(GameObject*& first_c, GameObject*& second_c)
{
	auto func = getMap().find(std::make_pair(typeid(*first_c).name(),
	typeid(*second_c).name()));

	if (func != getMap().end()) {
		func->second(first_c, second_c);
	}
}

