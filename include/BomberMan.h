#pragma once
#include "NonStatic.h"

const float CORNER_COLL = 15;
class Board;
class BomberMan : public NonStatic
{
public:
	BomberMan(sf::Vector2f pos);
	~BomberMan();

	void move(const sf::Keyboard::Key& k);
	void undoMovement();
	void recoverCollision(const sf::FloatRect& bounds);
	void handleMove(const sf::Keyboard::Key& k);
	void setSound(const sf::Keyboard::Key& k);
	void setdoorEntered(const bool& d);
	bool getDoorEntered() const;
	void draw(Window& window) {window << m_sprite; }
private:
	sf::Clock s_deltaTime;
	bool m_enterd = false;
};