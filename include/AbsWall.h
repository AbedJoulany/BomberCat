#pragma once
#include "Static.h"

class AbsWall : public Static
{
public:
	AbsWall(std::string name, sf::Vector2f pos);
	virtual ~AbsWall();
private:
};