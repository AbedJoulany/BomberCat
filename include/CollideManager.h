#pragma once
#include "CollisionData.h"
#include <functional>
#include <iostream>

typedef std::map < std::pair<std::string, std::string>,
	std::function<void(GameObject*&, GameObject*&)>> CollMap;
//-----------------------------------------------------------------------------
class CollideManager
{
public:
	static void set(std::pair<std::string, std::string>pair,
		std::function<void(GameObject*&, GameObject*&)>foo);

	static void unSet(const std::pair<std::string, std::string>& pair);

	static void clear();
	static void handle_collision(GameObject*& first_c, GameObject*& second_c);
	template<typename T, typename Y>
	static void handle_collision(std::unique_ptr<T>& first_c,
		std::unique_ptr<Y>& second_c);
private:
	CollideManager();
	~CollideManager();
	static CollMap& getMap();
};
//--------------handle_collision function--------------------------------------
template<typename T, typename Y>
inline void CollideManager::handle_collision(std::unique_ptr<T>& first_c,
	std::unique_ptr<Y>& second_c)
{
	if (!first_c || !second_c)
		return;
	T* s = first_c.release();
	Y* t = second_c.release();

	GameObject* first = dynamic_cast<GameObject*>(s);
	GameObject* second = dynamic_cast<GameObject*>(t);
	CollideManager::handle_collision(first, second);

	first_c.reset(s);
	second_c.reset(t);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------