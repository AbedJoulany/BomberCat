#pragma once
#include "Static.h"

class PowerUp :public Static
{
public:
	PowerUp(std::string name, sf::Vector2f pos);
	virtual ~PowerUp();

protected:
};
//-----------------------------------------------------------------------//
//---------------------------- constructor -----------------------------//
//---------------------------------------------------------------------//
inline PowerUp::PowerUp(std::string name, sf::Vector2f pos)
	:Static(name,pos)
{
}
//-----------------------------------------------------------------------//
//---------------------------- destructor ------------------------------//
//---------------------------------------------------------------------//
inline PowerUp::~PowerUp()
{
}
