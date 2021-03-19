#pragma once
#include "Static.h"

class AbsExplosion : public Static
{
public:
	AbsExplosion(std::string name, sf::Vector2f pos);
	virtual ~AbsExplosion();
	virtual bool canRemove() const;
	virtual void setRemove(const bool &r);
protected:
	bool remove;
	int sprite_num;

};
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
inline AbsExplosion::AbsExplosion(std::string name, sf::Vector2f pos)
	:Static(name, pos)
{
	remove = false; 
	sprite_num = 0;
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
inline AbsExplosion::~AbsExplosion()
{
}
//------------------------------------------------------------------------//
// ------------------------ if can remove -------------------------------//
//----------------------------------------------------------------------//
inline bool AbsExplosion::canRemove() const
{
	return remove;
}
//------------------------------------------------------------------------//
// ------------------------ set to remove -------------------------------//
//----------------------------------------------------------------------//
inline void AbsExplosion::setRemove(const bool& r)
{
	remove = r;
}
