#pragma once
#include "Monster.h"
#include "CollideManager.h"

class StupidMonster : public Monster
{
public:
	StupidMonster(std::string name, sf::Vector2f pos);
	virtual ~StupidMonster();
	virtual void move(const staticsV& m_statics, const std::unique_ptr<BomberMan>& bomber);
protected:

};
//-----------------------------------------------------------------------//
//---------------------------- constructor -----------------------------//
//---------------------------------------------------------------------//
inline StupidMonster::StupidMonster(std::string name, sf::Vector2f pos)
	:Monster(name, pos)
{
	m_moveStupid = true;
}
//-----------------------------------------------------------------------//
//---------------------------- destructor ------------------------------//
//---------------------------------------------------------------------//
inline StupidMonster::~StupidMonster()
{
}
//-----------------------------------------------------------------------//
//---------------------------- moving stupid ---------------------------//
//---------------------------------------------------------------------//
inline void StupidMonster::move(const staticsV& m_statics, const std::unique_ptr<BomberMan>& bomber)
{
	if (isDead()) return;

	m_movement = sf::Keyboard::Key(random);
	sf::Vector2f v = keyToCoord(sf::Keyboard::Key(random));
	m_sprite.move(v*m_movementSpeed);
}