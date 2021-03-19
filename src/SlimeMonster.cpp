#include "SlimeMonster.h"

//-----------------------------------------------------------------------//
//---------------------------- constructor -----------------------------//
//---------------------------------------------------------------------//
SlimeMonster::SlimeMonster(sf::Vector2f pos)
	:SmartMonster(SlimeSheet, pos)
{
	SIZE = sf::Vector2i{ 31,32 };
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Default", sf::IntRect{ 0,0,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Right0", sf::IntRect{ 0,0,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Right1", sf::IntRect{ 32,0,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Right2", sf::IntRect{ 64,0,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Left0", sf::IntRect{ 0,32,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Left1", sf::IntRect{ 32,32,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Left2", sf::IntRect{ 64,32,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Down0", sf::IntRect{ 0,0,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Down1", sf::IntRect{ 32,0,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Down2", sf::IntRect{ 64,0,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Up0", sf::IntRect{ 0,32,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Up1", sf::IntRect{ 32,32,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Up2", sf::IntRect{ 64,32,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Dead0", sf::IntRect{ 0,64,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Dead1", sf::IntRect{ 32,64,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Dead2", sf::IntRect{ 64,64,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Dead3", sf::IntRect{ 96,64,SIZE.x,SIZE.x });
	SpriteMovement::setSprite(typeid(SlimeMonster).name(), "Dead4", sf::IntRect{ 128,64,SIZE.x,SIZE.x });

	m_sprite.setTextureRect(SpriteMovement::getSprite(typeid(SlimeMonster).name(), "Default"));
	//m_sprite.setScale({  m_boardScale.getScale().x/32,  m_boardScale.getScale().y/32 });
	deltaTime.restart();
	m_frameEnd = 3;
	m_frameDeadEnd = 5;
	m_dyingScore = 200;
	m_movementSpeed = 0.5f;
}
//-----------------------------------------------------------------------//
//---------------------------- destructor ------------------------------//
//---------------------------------------------------------------------//
SlimeMonster::~SlimeMonster()
{
}
