#include "GameObject.h"
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
GameObject::GameObject(std::string spName, sf::Vector2f location)
{
	m_drawable = true;
	m_sprite = Resources::instance().get_img(spName);
	m_location = location;
	reScale();
	setPosition(location);
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
GameObject::~GameObject()
{
}
//-----------------------------------------------------------------------//
//------------------------- drawing the Object -------------------------//
//---------------------------------------------------------------------//
void GameObject::draw(Window& window)
{
		if (!isDrawable()) return;
		window << m_sprite;
}
//-----------------------------------------------------------------------//
//------------------ if objects is destroyed or not --------------------//
//---------------------------------------------------------------------//
bool GameObject::isDrawable() const
{
	return m_drawable;
}
//-----------------------------------------------------------------------//
//------------ rescaling after changing screen mode --------------------//
//---------------------------------------------------------------------//
void GameObject::reScale()
{
	float bounds = std::max(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
	m_sprite.setScale(m_boardScale.getScale().x / bounds, m_boardScale.getScale().y / bounds);
}
//-----------------------------------------------------------------------//
//--------- setting position after changing screen mode ----------------//
//---------------------------------------------------------------------//
void GameObject::resetPosition()
{
	sf::Vector2f pos = { (m_sprite.getPosition().y - m_prePos.y) / m_prePos.z,
		(m_sprite.getPosition().x - m_prePos.x) / m_prePos.z };

	setPosition(pos);
}
//-----------------------------------------------------------------------//
//------------ setting Object after margin and scaling -----------------//
//---------------------------------------------------------------------//
void GameObject::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos.y * m_boardScale.getcellWidth() + m_boardScale.getMarginX(),
		pos.x * m_boardScale.getcellWidth() + m_boardScale.getMarginY());
	m_prePos = { m_boardScale.getMarginX(), m_boardScale.getMarginY(),m_boardScale.getcellWidth() };
}
//-----------------------------------------------------------------------//
//----------------------- Draw Object or Not ---------------------------//
//---------------------------------------------------------------------//
void GameObject::setDwarable(const bool& status)
{
	m_drawable = status;
}
//-----------------------------------------------------------------------//
//----------------------- Get Sprite Position --------------------------//
//---------------------------------------------------------------------//
sf::Vector2f GameObject::getPosition() const
{
	return m_sprite.getPosition();
}
//-----------------------------------------------------------------------//
//------------------- get First Location by dataStruct -----------------//
//---------------------------------------------------------------------//
sf::Vector2f GameObject::getLocation() const
{
	return m_location;
}
//------------------------------------------------------------------------//
// ----------- getting sprite mid point for better collision ------------//
//----------------------------------------------------------------------//
sf::Vector2f GameObject::getMidPoint() const
{
	return sf::Vector2f{ (this->getRect().width / 2) + this->getRect().left,(this->getRect().height / 2) + this->getRect().top };
}
//-----------------------------------------------------------------------//
//------------------ Get Object GLobalBounds ---------------------------//
//---------------------------------------------------------------------//
sf::FloatRect GameObject::getRect() const
{
	return m_sprite.getGlobalBounds();
}
//-----------------------------------------------------------------------//
//--------- getting class name helps collisions class to work ----------//
//---------------------------------------------------------------------//
std::string GameObject::getName() const
{
	return std::string(typeid(*this).name());
}
//-----------------------------------------------------------------------//
//----------------------------------------------------------------------//
//---------------------------------------------------------------------//