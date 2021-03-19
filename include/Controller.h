#pragma once
#include "Window.h"
#include "Game.h"
#include "Settings.h"

class Controller
{
public:

	Controller();
	~Controller();

	void runGame();
	void upateMenu();

private:

	Window& m_window = Window::instance();
	Menu m_mainMenu;

};