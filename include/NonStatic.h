#pragma once
#include "GameObject.h"

const float HOP = 5.f;
using Frame = unsigned int;

class NonStatic : public GameObject
{
public:
	NonStatic(std::string name, sf::Vector2f pos);
	virtual ~NonStatic();

	virtual void draw(Window& window);
	virtual void cropSprite();
	virtual bool isDead() const;
	virtual void die(const bool& d);
	virtual void moveSprite(const sf::Vector2f& newpos);
	virtual void undoMovement() = 0;
	virtual sf::Vector2f keyToCoord(const sf::Keyboard::Key& k);
	virtual sf::String keyToText(const sf::Keyboard::Key& k);
	virtual sf::Vector2i getLocByDS() const;

protected:
	sf::Clock deltaTime;
	bool m_isDead = false;
	sf::Vector2i SIZE;
	Frame m_frameEnd;
	Frame m_frameDeadEnd;
	int m_dyingScore = 0;
	float m_movementSpeed = 0;
	int sprite_num = 0;
	int m_movement = 72;
	int m_lastMovement = 0;
};

