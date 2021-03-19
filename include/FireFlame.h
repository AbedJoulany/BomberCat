#pragma once
#include "AbsExplosion.h"

class FireFlame : public AbsExplosion
{
public:
	FireFlame(sf::Vector2f pos);
	~FireFlame();
	void draw(Window& m_window) override;
	void setCollided(const bool& collided);
	bool getCollided() const;
private:
	bool collided = false;
	int SIZE = 48;
	int m_frameEnd;
	sf::Clock deltaTime;
	
};
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
inline FireFlame::FireFlame(sf::Vector2f pos)
	:AbsExplosion(FlameSheet, pos)
{
	SpriteMovement::setSprite(typeid(FireFlame).name(), "Flame0", sf::IntRect{ 0,0,SIZE,SIZE });
	SpriteMovement::setSprite(typeid(FireFlame).name(), "Flame1", sf::IntRect{ SIZE*1,0,SIZE,SIZE });
	SpriteMovement::setSprite(typeid(FireFlame).name(), "Flame2", sf::IntRect{ SIZE*2,0,SIZE,SIZE });
	SpriteMovement::setSprite(typeid(FireFlame).name(), "Flame3", sf::IntRect{SIZE*3,0,SIZE,SIZE });
	SpriteMovement::setSprite(typeid(FireFlame).name(), "Flame4", sf::IntRect{SIZE*4,0,SIZE,SIZE });

	m_sprite.setTextureRect(SpriteMovement::getSprite(typeid(FireFlame).name(), "Flame0"));
	m_sprite.setScale({  m_boardScale.getScale().x / SIZE,  m_boardScale.getScale().y / SIZE });
	deltaTime.restart();
	m_frameEnd = 5;
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
inline FireFlame::~FireFlame() 
{
}
//------------------------------------------------------------------------//
// ------------------------ drawing the fire ----------------------------//
//----------------------------------------------------------------------//
inline void FireFlame::draw(Window& m_window)
{
	if (sprite_num == m_frameEnd)
	{
		this->remove = true;
		return;
	}
	if (!this->isDrawable())
		return;
	std::string dir = "Flame" + std::to_string(sprite_num);
	//TODO:: put in function
	if (deltaTime.getElapsedTime().asMilliseconds() >= 200) {
		sprite_num = (sprite_num + 1);
		deltaTime.restart();
	}

	m_sprite.setTextureRect(SpriteMovement::getSprite(typeid(FireFlame).name(), dir));
	m_sprite.setScale({  m_boardScale.getScale().x / SIZE,  m_boardScale.getScale().y / SIZE });

	m_window << m_sprite;
}

inline void FireFlame::setCollided(const bool& status)
{
	collided = status;
}

inline bool FireFlame::getCollided() const
{
	return collided;
}
