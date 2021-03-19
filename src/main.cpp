#include <SFML/Graphics.hpp>
#include <iostream>
#include "Controller.h"

int main()
{
	srand(NULL);
	Window::instance(WINDOW_NAME);
	Controller Bomber;
	Bomber.runGame();
}