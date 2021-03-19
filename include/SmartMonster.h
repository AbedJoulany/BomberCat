#pragma once
#include "Monster.h"


class SmartMonster : public Monster
{
public:
	SmartMonster(std::string name, sf::Vector2f pos);
	virtual ~SmartMonster();
	virtual void move(const staticsV& m_statics, const std::unique_ptr<BomberMan>& bomber);
	virtual void moveSmart();
	virtual void moveStupid();
	virtual void xAxisFix();
	virtual void yAxisFix();
	virtual void setRunFromBomb(const bool& b );
	virtual const sf::Vector2i BFS(const staticsV& m_statics, sf::Vector2i src, sf::Vector2i dst);

protected:
	sf::Vector2i direction;
	sf::Vector2f destination;
	bool m_CollWithBomb;
	sf::Clock runBomb;

};