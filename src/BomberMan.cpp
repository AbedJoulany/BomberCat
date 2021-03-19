#include "BomberMan.h"
#include <iostream>
#include "Board.h"
#include "StageData.h"
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
BomberMan::BomberMan(sf::Vector2f pos)
	:NonStatic(playerSheet, pos)
{
	SIZE = { 28, 46 };
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Default",sf::IntRect{ SIZE.x,SIZE.y * 3,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Down0",  sf::IntRect{ SIZE.x,SIZE.y * 3,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Down1",  sf::IntRect{ 0,SIZE.y * 3,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Down2",  sf::IntRect{ SIZE.x * 2,SIZE.y * 3,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Up0",    sf::IntRect{ SIZE.x,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Up1",    sf::IntRect{ 0,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Up2",    sf::IntRect{ SIZE.x * 2,0,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Right0", sf::IntRect{ SIZE.x,SIZE.y * 2,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Right2", sf::IntRect{ 0,SIZE.y * 2,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Right1", sf::IntRect{ SIZE.x * 2,SIZE.y * 2,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Left0",  sf::IntRect{ SIZE.x,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Left2",  sf::IntRect{ 0,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Left1",  sf::IntRect{ SIZE.x * 2,SIZE.y,SIZE.x,SIZE.y });
	SpriteMovement::setSprite(typeid(BomberMan).name(), "Dead",   sf::IntRect{ SIZE.x * 2,SIZE.y,SIZE.x,SIZE.y });         
	SIZE.y += 2;

	m_sprite.setTextureRect(SpriteMovement::getSprite(typeid(BomberMan).name(), "Default"));
	m_sprite.setScale({ this->m_boardScale.getScale().x / std::max(SIZE.x,SIZE.y), this->m_boardScale.getScale().y / std::max(SIZE.x,SIZE.y) });
	deltaTime.restart();
	s_deltaTime.restart();
	m_frameEnd = 3;
	m_frameDeadEnd = 5;


	//m_sprite.setTextureRect(SpriteMovement::getSprite(typeid(BomberMan).name(), "Default"));
	//m_sprite.setScale({ this->m_boardScale.getScale().x / SIZE.x, this->m_boardScale.getScale().y / SIZE.y });
	//deltaTime.restart();
	//s_deltaTime.restart();
	//m_frameEnd = 3;
	//m_frameDeadEnd = 5;
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
BomberMan::~BomberMan()
{
}
//------------------------------------------------------------------------//
// ------------------------ move Sprite ---------------------------------//
//----------------------------------------------------------------------//
void BomberMan::move(const sf::Keyboard::Key& k)
{
	if (isDead()) return;
	cropSprite();
	setSound(k);
	handleMove(k);
	m_movement = int(k);
}
//------------------------------------------------------------------------//
// ------------------- undoMovement if collided -------------------------//
//----------------------------------------------------------------------//
void BomberMan::undoMovement()
{
	auto v = keyToCoord(sf::Keyboard::Key(m_lastMovement));
	m_sprite.move(-v * StageData::instance().getSpeedMovement());
}
//------------------------------------------------------------------------//
// ------------------ recover from collision ----------------------------//
//----------------------------------------------------------------------//
void BomberMan::recoverCollision(const sf::FloatRect& bounds)
{
	switch (Window::instance().eventKey().code)
	{
	case sf::Keyboard::Up:
	case sf::Keyboard::Down:
		if (bounds.left + bounds.width - this->getPosition().x <= CORNER_COLL)
			this->handleMove(sf::Keyboard::Right);
		else if (this->getPosition().x + this->getRect().width - bounds.left <= CORNER_COLL)
			this->handleMove(sf::Keyboard::Left);
		break;
	case sf::Keyboard::Right:
	case sf::Keyboard::Left:
		if (bounds.top + bounds.height - this->getPosition().y <= CORNER_COLL)
			this->handleMove(sf::Keyboard::Down);
		else if (this->getPosition().y + this->getRect().height - bounds.top <= CORNER_COLL)
			this->handleMove(sf::Keyboard::Up);
		break;
	}
}
//------------------------------------------------------------------------//
// ------------------------ handle theMovement --------------------------//
//----------------------------------------------------------------------//
void BomberMan::handleMove(const sf::Keyboard::Key& k)
{
	sf::Vector2f v = keyToCoord(sf::Keyboard::Key(k));
	m_sprite.move(v * StageData::instance().getSpeedMovement());
}
//------------------------------------------------------------------------//
// --------------------- set Moving sound -------------------------------//
//----------------------------------------------------------------------//
void BomberMan::setSound(const sf::Keyboard::Key& k)
{
	if (s_deltaTime.getElapsedTime().asMilliseconds() >= 250)
	{
		if (k == sf::Keyboard::Key::Right || k == sf::Keyboard::Key::Left)
			SoundPlayer::play("Walk.ogg");
		else if (k == sf::Keyboard::Key::Up || k == sf::Keyboard::Key::Down)
			SoundPlayer::play("WalkUpDown.ogg");
		s_deltaTime.restart();
	}
}
//------------------------------------------------------------------------//
// ------------------------ if enterd the door --------------------------//
//----------------------------------------------------------------------//
void BomberMan::setdoorEntered(const bool& d)
{
	m_enterd = d;
}
//------------------------------------------------------------------------//
// ------------------------ get if enterd -------------------------------//
//----------------------------------------------------------------------//
bool BomberMan::getDoorEntered() const
{
	return m_enterd;
}

