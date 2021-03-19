#pragma once
#include "MenuOptions.h"

class Exit: public MenuOptions
{
public:

	Exit() {};
	~Exit() {};
	template<typename T>
	void set(T& menu);
};
//------------------------------------------------------------------------//
// ------------------------ setting option ------------------------------//
//----------------------------------------------------------------------//
template<typename T>
inline void Exit::set(T& menu)
{
	menu.set(EXIT, [] {exit(EXIT_SUCCESS); });
}
