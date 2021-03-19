#pragma once
#include "NonStatic.h"
#include "Board.h"

class Monster : public NonStatic
{
public:
	Monster(std::string name, sf::Vector2f pos);
	virtual ~Monster();
	virtual void move(const staticsV& m_statics, const std::unique_ptr<BomberMan>& bomber) = 0;
	virtual void undoMovement();
	virtual void recoverCollision(const sf::FloatRect& bounds);
	virtual int getDyingScore() const;

protected:
	bool m_moveStupid;
	int random;
};