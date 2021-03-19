#pragma once
#include "MenuOptions.h"
#include "Window.h"

class Help :
	public MenuOptions
{
public:
	Help() {};//------------ c-tor --------------------------------------------
	~Help() {};//----------- d-tor --------------------------------------------
	template<typename T>
	void set(T& menu);
	void print();
private:
	Window& m_window = Window::instance();
};

//----------------------- register help label in the menu ---------------------
template<typename T>
inline void Help::set(T& menu)
{
	menu.set(HELP, [this] {this->print(); });
}

//----------------------- print help content ----------------------------------
inline void Help::print()
{
	while (m_window.isOpen()) {
		m_window.clear();
		m_window.setBackground(HELP_BACKKGROUND_SPRITE);

		while (m_window.pollEvent())
		{
			switch (m_window.eventType())
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				switch (m_window.eventKey().code)
				{
				case sf::Keyboard::BackSpace:
				case sf::Keyboard::Escape:
					return;
				}
				break;
			}
		}
		m_window.printFile(HELP_FILE);
		m_window.display();
	}
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------