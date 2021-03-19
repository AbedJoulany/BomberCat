#pragma once
#include "Menu.h"
#include <iostream>
template<typename Menu_Type>
class Settings : public Menu_Type
{
public:
	Settings();
	~Settings();
	using Menu_Type::set;
	void run();
	using Menu_Type::drawOnScreen;
	void set(Menu_Type& menu, const std::string& subMenu_name);
private:
};
//------------------------ c-tor ----------------------------------------------
template<typename Menu_Type>
inline Settings<Menu_Type>::Settings()
	:Menu_Type(true) {}
//------------------------ d-tor ----------------------------------------------
template<typename Menu_Type>
inline Settings<Menu_Type>::~Settings() {}
//------------------------- run sub menu function -----------------------------
template<typename Menu_Type>
inline void Settings<Menu_Type>::run()
{
	static bool init = true;
	if (init) {
		this->set(BACK, [this] {this->Menu_Type::go_back = true; });
		init = false;
	}
	Menu_Type::run();
}
//--------------------- register sub-menu into another menu -------------------
template<typename Menu_Type>
inline void Settings<Menu_Type>::set(Menu_Type& menu,
	const std::string& subMenu_name)
{
	menu.set(subMenu_name, [this] {this->run(); });
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------