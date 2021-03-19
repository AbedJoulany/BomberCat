#include "BalloonMonster.h"
#include <iostream>

//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
BalloonMonster::BalloonMonster(sf::Vector2f pos)
	:StupidMonster(BalloonSheet, pos)
{
	SIZE = sf::Vector2i{ 32,32 };
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Default", sf::IntRect{ 0,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Right0", sf::IntRect{ 0,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Right1", sf::IntRect{ SIZE.x,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Right2", sf::IntRect{ SIZE.x*2,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Left0", sf::IntRect{ 0,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Left1", sf::IntRect{ SIZE.x,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Left2", sf::IntRect{ SIZE.x*2,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Down0", sf::IntRect{ 0,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Down1", sf::IntRect{ SIZE.x,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Down2", sf::IntRect{ SIZE.x*2,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Up0", sf::IntRect{ 0,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Up1", sf::IntRect{ SIZE.x,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Up2", sf::IntRect{ SIZE.x*2,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Dead0", sf::IntRect{ 0,SIZE.y*2,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Dead1", sf::IntRect{ SIZE.x,SIZE.y*2,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Dead2", sf::IntRect{ SIZE.x*2,SIZE.y*2,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Dead3", sf::IntRect{ SIZE.x*3,SIZE.y*2,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BalloonMonster).name(), "Dead4", sf::IntRect{ SIZE.x*4,SIZE.y * 2,SIZE.x,SIZE.y });            

	m_sprite.setTextureRect(SpriteMovement::getSprite(typeid(BalloonMonster).name(), "Default"));
	m_sprite.setScale({ m_boardScale.getScale().x / std::max(SIZE.x,SIZE.y),  m_boardScale.getScale().y / std::max(SIZE.x,SIZE.y) });
	deltaTime.restart();
	m_frameEnd = 3;
	m_frameDeadEnd = 5;
	random = 73;
	m_dyingScore = 100;
	m_movementSpeed = 1.f;
}
//------------------------------------------------------------------------//
// ------------------------- destructor ---------------------------------//
//----------------------------------------------------------------------//
BalloonMonster::~BalloonMonster()
{
}
//-----------------------------------------------------------------------//
//----------------------------------------------------------------------//
//---------------------------------------------------------------------//