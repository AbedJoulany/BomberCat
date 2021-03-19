#include "Menu.h"
#include "SoundPlayer.h"
#include <iostream>
//-----------------------------------------------------------------------//
//---------------------------- constructor -----------------------------//
//---------------------------------------------------------------------//
Menu::Menu(const bool& can_get_back)
	:can_g_back(can_get_back)
{
}
//-----------------------------------------------------------------------//
//---------------------------- destructor ------------------------------//
//---------------------------------------------------------------------//
Menu::~Menu()
{
}
//-----------------------------------------------------------------------//
//---------------------------- setMenu Options -------------------------//
//---------------------------------------------------------------------//
void Menu::set(const std::string str, std::function<void()> lambda)
{
	m_list.emplace_back(str, lambda);
}
//-----------------------------------------------------------------------//
//---------------------------- UnSet Menu Options ----------------------//
//---------------------------------------------------------------------//
void Menu::unSet(const std::string& str)
{
	menu_list::iterator it = std::move(this->getIterator(str));
	if (it == m_list.end())
	{
		return;
	}
	m_list.erase(it);
}
//-----------------------------------------------------------------------//
//---------------------- setting option in front -----------------------//
//---------------------------------------------------------------------//
void Menu::setFront(const std::string str, std::function<void()> lambda)
{
	m_list.emplace_front(str, lambda);
}
//-----------------------------------------------------------------------//
//--------------------- if Option is registered ------------------------//
//---------------------------------------------------------------------//
bool Menu::inMenu(const std::string& str)
{
	return (getIterator(str) != m_list.end());
}
//-----------------------------------------------------------------------//
//------------------- getTheOptionFunction -----------------------------//
//---------------------------------------------------------------------//
menu_list::iterator Menu::getIterator(const std::string& str)
{
	return std::find_if(m_list.begin(), m_list.end(),
		[&](auto& x) {return (x.first == str); });
}
//-----------------------------------------------------------------------//
//----------------------- Running the Menu -----------------------------//
//---------------------------------------------------------------------//
void Menu::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.setBackground(MENU_BACKKGROUND_SPRITE);
		drawOnScreen();
		m_window.display();
		if (go_back) { go_back = false;		return; }
		if (m_window.pollEvent())
			handleEvent();
	}
}
//-----------------------------------------------------------------------//
//----------------------- Drawing the Menu -----------------------------//
//---------------------------------------------------------------------//
void Menu::drawOnScreen()
{
	int j = 0;
	sf::Color m_color;
	for (auto& i : m_list) {
		auto txt = Resources::instance().getTxt(i.first, m_window.getWidth() / 2.f,
			(j + 1) * m_window.getHeight() / (2 * (m_list.size() + 1)) +
			((m_window.getHeight() / 2)) / 2, FONT_FILE, true);
		//-----------------
		j++;
	}j = 0;
	for (auto& i : m_list)
	{
		if (j == mOptionIndex)
			m_color = sf::Color::Blue;
		else
			m_color = sf::Color::White;
		m_window.draw(Resources::instance().getTxt(i.first, m_window.getWidth() / 2.f,
			(++j) * m_window.getHeight() / (2 * (m_list.size() + 1)) +
			(m_window.getHeight() - (m_window.getHeight() / 2)) / 2, FONT_FILE, true, m_color));
	}
}
//-----------------------------------------------------------------------//
//----------------------- handling Menu Events -------------------------//
//---------------------------------------------------------------------//
void Menu::handleEvent()
{
	switch (m_window.eventType())
	{
	case sf::Event::Closed:
		m_window.close();
		break;
	case sf::Event::KeyPressed:
		switch (m_window.eventKey().code)
		{
		case sf::Keyboard::Escape:
			if (can_g_back)
				go_back = true;
			break;
		case sf::Keyboard::Up:
			--mOptionIndex;
			mOptionIndex = (abs(mOptionIndex) * m_list.size() + mOptionIndex) % m_list.size();
			break;
		case sf::Keyboard::Down:
			++mOptionIndex;
			mOptionIndex = (abs(mOptionIndex) * m_list.size() + mOptionIndex) % m_list.size();
			break;
		case sf::Keyboard::Enter:
			m_list[mOptionIndex].second();
			break;
		}
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------------------//
//----------------------------------------------------------------------//
//---------------------------------------------------------------------//

