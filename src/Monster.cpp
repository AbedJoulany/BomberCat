#include "Monster.h"
#include <iostream>
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
Monster::Monster(std::string name, sf::Vector2f pos)
	:NonStatic(name,pos)
{
	random = 73;
}
//------------------------------------------------------------------------//
// ------------------------- destructor ---------------------------------//
//----------------------------------------------------------------------//
Monster::~Monster()
{
}
//-----------------------------------------------------------------------//
//---------------------- undo movement if collidied --------------------//
//---------------------------------------------------------------------//
void Monster::undoMovement()
{
	if (!m_moveStupid)
		 return;
	sf::Vector2f v = keyToCoord(sf::Keyboard::Key(random));
	moveSprite(-v);
	random = (rand() % 4 + 71);
}
//----------------------------------------------------------------------//
// recovering the collission because in some times when going full screen
// monster get stuck in the walls edges.
//----------------------------------------------------------------------//
void Monster::recoverCollision(const sf::FloatRect& bounds)
{
	if (bounds.intersects(this->getRect())) {
		// Monster collided to the right side of the wall
		if (bounds.left + bounds.width > this->getPosition().x)
			this->moveSprite({ 0.1,0 });
		if (this->getPosition().x + this->getRect().width > bounds.left)
			this->moveSprite({ -0.1,0 });
		if (bounds.top + bounds.height > this->getPosition().y)
			this->moveSprite({ 0,0.1 });
		if (this->getPosition().y + this->getRect().height > bounds.top)
			this->moveSprite({ 0,-0.1 });
	}
}
//-----------------------------------------------------------------------//
//----------------------- dying score for monsters ---------------------//
//---------------------------------------------------------------------//
int Monster::getDyingScore() const
{
	return m_dyingScore;
}
