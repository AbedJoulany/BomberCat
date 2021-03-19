#pragma once
#include "MainMenu.h"

class MenuOptions :public MainMenu
{
public:
	MenuOptions();
	~MenuOptions();
	template<typename T>
	void set(T& menu) {};
};
//------------------- c-tor ---------------------------------------------------
inline MenuOptions::MenuOptions() {}

//------------------- d-tor ---------------------------------------------------
inline MenuOptions::~MenuOptions() {}
