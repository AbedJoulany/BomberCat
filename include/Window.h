#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <algorithm>

using Height = unsigned int;
using Width = unsigned int;

const Width WIDTH = 800;
const Height HEIGHT = 900;

class Window : public sf::RenderWindow
{
public:

	Window();
	~Window();

	static Window& instance(const std::string winTitle = "None");
	const float& getWidth() const;
	const float& getHeight() const;
	sf::Vector2f getMousePosition()const;
	void resize();
	void setBackground(const std::string& path);
	bool pollEvent();//for checking events on the screen
	bool waitEvent();//for checking events on the screen
	void display(sf::Time duration = sf::seconds(0));
	void printFile(const char* fileName);
	const sf::Event::EventType& eventType();
	const sf::Event::KeyEvent& eventKey();

private:
	void initWindow(); // initializing the window
	Window(const std::string& title);
	void create(const std::string& title, bool isWindowed = true);
	sf::Event m_event;
	float m_width;
	float m_height;
	sf::Sprite m_sprite;
	std::string m_title;
};
Window& operator<<(Window& window, const sf::Sprite& sprite);
