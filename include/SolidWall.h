#pragma once
#include "AbsWall.h"

class SolidWall : public AbsWall
{
public:
	SolidWall(sf::Vector2f pos);
	~SolidWall();
private:
};