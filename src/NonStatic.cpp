#include "NonStatic.h"
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
NonStatic::NonStatic(std::string name, sf::Vector2f pos)
	:GameObject(name, pos)
{
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
NonStatic::~NonStatic()
{
}
//------------------------------------------------------------------------//
// ------------------------ Draw on Screen ------------------------------//
//----------------------------------------------------------------------//
void NonStatic::draw(Window& window)
{
	if (!isDrawable()) return;
	cropSprite();
	window << m_sprite;
}
//------------------------------------------------------------------------//
// ----------------- Croping Sprite For animation -----------------------//
//----------------------------------------------------------------------//
void NonStatic::cropSprite()
{
	if (m_movement != m_lastMovement)
	{ m_lastMovement = m_movement; sprite_num = 0; }

	std::string dir = (isDead()? "Dead" : keyToText(sf::Keyboard::Key(m_movement)))+ std::to_string(sprite_num);
	m_sprite.setTextureRect(SpriteMovement::getSprite(this->getName(), dir));
	m_sprite.setScale({ m_boardScale.getScale().x / std::max(SIZE.x,SIZE.y),  m_boardScale.getScale().y / std::max(SIZE.x,SIZE.y) });

	if (deltaTime.getElapsedTime().asMilliseconds() >= ANIM_TIME) {
		sprite_num = (sprite_num + 1) % m_frameEnd;
		deltaTime.restart();
	}
	if (sprite_num == m_frameDeadEnd)
	{m_drawable = false;}
		//Window::instance().draw(Resources::instance().getTxt(std::to_string(m_dyingScore), getPosition().x, getPosition().y,ARIAL,true,sf::Color::White,10,3));
}
//------------------------------------------------------------------------//
// ------------------------ If Object is dead ---------------------------//
//----------------------------------------------------------------------//
bool NonStatic::isDead() const
{
	return m_isDead;
}
//------------------------------------------------------------------------//
// ------------------------ Object is dead ------------------------------//
//----------------------------------------------------------------------//
void NonStatic::die(const bool& d)
{
	m_isDead = d;
	sprite_num = 0;
	m_frameEnd = m_frameDeadEnd + 1;
}
//------------------------------------------------------------------------//
// ------------------------ for moving the object -----------------------//
//----------------------------------------------------------------------//
void NonStatic::moveSprite(const sf::Vector2f& newPos)
{
	m_sprite.move((newPos*m_movementSpeed));
}
//------------------------------------------------------------------------//
// ---------------- transform key to cords for moving -------------------//
//----------------------------------------------------------------------//
sf::Vector2f NonStatic::keyToCoord(const sf::Keyboard::Key& k)
{
	int x = int(k) - 71;
	sf::Vector2f r(x >= 2 ? 0 : std::pow(-1, x + 1), x < 2 ? 0 : std::pow(-1, x + 1));
	return r;
}
//------------------------------------------------------------------------//
// ------------------ transform key to text for animation ---------------//
//----------------------------------------------------------------------//
sf::String NonStatic::keyToText(const sf::Keyboard::Key& k)
{
	switch (k)
	{
	case sf::Keyboard::Key::Right:
		return "Right";
		break;
	case sf::Keyboard::Key::Left:
		return "Left";
		break;
	case sf::Keyboard::Key::Down:
		return "Down";
		break;
	case sf::Keyboard::Key::Up:
		return "Up";
		break;
	}
}
//------------------------------------------------------------------------//
// ----------- getting sprite position acording to the board ------------//
//-------------------- for bfs and other functions ---------------------//
//---------------------------------------------------------------------//
sf::Vector2i NonStatic::getLocByDS() const
{
	return sf::Vector2i{int((this->getMidPoint().x - this->m_boardScale.getMarginX())/ this->m_boardScale.getcellWidth()),
		int((this->getMidPoint().y- this->m_boardScale.getMarginY()) / this->m_boardScale.getcellWidth()) };
}
//-----------------------------------------------------------------------//
//----------------------------------------------------------------------//
//---------------------------------------------------------------------//