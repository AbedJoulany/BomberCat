#include "Bomb.h"
#include "StageData.h"

//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
Bomb::Bomb(sf::Vector2f pos)
	:AbsExplosion(BombSheet, pos)
{
	SpriteMovement::setSprite(typeid(Bomb).name(), "Bomb0", sf::IntRect{ 0,0,SIZE,SIZE });
	SpriteMovement::setSprite(typeid(Bomb).name(), "Bomb1", sf::IntRect{ 32,0,SIZE,SIZE });
	SpriteMovement::setSprite(typeid(Bomb).name(), "Bomb2", sf::IntRect{ 64,0,SIZE,SIZE });

	m_sprite.setTextureRect(SpriteMovement::getSprite(typeid(Bomb).name(), "Default"));
	m_sprite.setScale({  m_boardScale.getScale().x / SIZE,  m_boardScale.getScale().y / SIZE });
	deltaTime.restart();
	ExplosionDT.restart();
}
//------------------------------------------------------------------------//
// ------------------------- destructor ---------------------------------//
//----------------------------------------------------------------------//
Bomb::~Bomb()
{
}
//------------------------------------------------------------------------//
// ------------------------- draw the bomb ------------------------------//
//----------------------------------------------------------------------//
void Bomb::draw(Window& m_window)
{

	std::string dir = "Bomb" + std::to_string(sprite_num);
	//TODO:: put in function
	if (deltaTime.getElapsedTime().asMilliseconds() >= ANIM_TIME) {
		sprite_num = (sprite_num + 1) % 3;
		deltaTime.restart();
	}
	m_sprite.setTextureRect(SpriteMovement::getSprite(typeid(Bomb).name(), dir));
	m_sprite.setScale({  m_boardScale.getScale().x / SIZE,  m_boardScale.getScale().y / SIZE });

	m_window << m_sprite;
}
//------------------------------------------------------------------------//
// ----------------------- if bombe can explode -------------------------//
//----------------------------------------------------------------------//
bool Bomb::canExplode()
{
	if (ExplosionDT.getElapsedTime().asSeconds() >= EXPLOSIONE_TIME)
	{
		remove = true;
		return true;
	}
	return false;
}
//------------------------------------------------------------------------//
// ------ function to allow the bomber to get away from the bomber ------//
//--------------------- and not pass it again --------------------------//
//---------------------------------------------------------------------//
void Bomb::setInMe(const bool& status)
{
	m_inMe = status;
}
//-----------------------------------------------------------------------//
//----------------------- setting the satatus --------------------------//
//---------------------------------------------------------------------//
bool Bomb::inMe() const
{
	return m_inMe;
}
//-----------------------------------------------------------------------//
//----------------------------------------------------------------------//
//---------------------------------------------------------------------//