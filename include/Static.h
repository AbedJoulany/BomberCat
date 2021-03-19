#pragma once
#include "GameObject.h"

class Static : public GameObject
{
public:
	Static(std::string name, sf::Vector2f pos);
	virtual ~Static();
	virtual void draw(Window &window);
	virtual void moveSprite(const sf::Vector2f& newpos) {};
	virtual void undoMovement() {};
	virtual void recoverCollision(const sf::FloatRect& bounds) {};


private:
};
//-----------------------------------------------------------------------//
//---------------------------- constructor -----------------------------//
//---------------------------------------------------------------------//
inline Static::Static(std::string name, sf::Vector2f pos)
	:GameObject(name, pos)
{}
//-----------------------------------------------------------------------//
//---------------------------- destructor ------------------------------//
//---------------------------------------------------------------------//
inline Static::~Static()
{}
//-----------------------------------------------------------------------//
//---------------------------- drawStatics -----------------------------//
//---------------------------------------------------------------------//
inline void Static::draw(Window& window)
{
	if (!isDrawable()) return;
	window << m_sprite;
}
