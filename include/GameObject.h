#pragma once
#include "Definitions.h"
#include "Window.h"
#include "BoardScale.h"
#include "SoundPlayer.h"
#include "Anime_Base.h"
#include <iostream>
const float ANIM_TIME = 300.f;

class GameObject
{
public:

	GameObject(std::string spName, sf::Vector2f location);
	virtual ~GameObject();
	virtual void draw(Window& window);
	virtual bool isDrawable() const;
	// ------------ setFunctions -------------------//
	virtual void reScale();
	virtual void resetPosition();
	virtual void setPosition(sf::Vector2f pos);
	virtual void setDwarable(const bool& status);
	virtual void moveSprite(const sf::Vector2f& newpos) = 0;
	virtual void undoMovement() = 0;
	virtual void recoverCollision(const sf::FloatRect& bounds) = 0;
	// ------------ getFunctions -------------------//
	virtual sf::Vector2f getPosition() const;
	virtual sf::Vector2f getLocation() const;
	virtual sf::Vector2f getMidPoint() const;
	virtual sf::FloatRect getRect() const;
	virtual std::string getName() const;
	// ------------ Protected Section -------------------//
protected:
	BoardScale &m_boardScale = BoardScale::instance();
	sf::Sprite m_sprite;
	sf::Vector2f m_location;
	sf::Vector3f m_prePos;
	sf::Vector2f m_size;
	bool m_drawable;
	float m_speed;
};