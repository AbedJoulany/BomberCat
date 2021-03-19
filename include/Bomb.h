#pragma once
#include "AbsExplosion.h"
#include "FireFlame.h"

const float EXPLOSIONE_TIME = 3;

class Bomb : public AbsExplosion
{
public:
	Bomb(sf::Vector2f pos);
	void draw(Window & m_window) override;
	~Bomb();
	bool canExplode();
	void setInMe(const bool &status);
	bool inMe() const;


private:
	int SIZE = 32;
	bool m_inMe = true;
	sf::Clock deltaTime;
	sf::Clock ExplosionDT;
};
