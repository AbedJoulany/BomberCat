#include "MainMenu.h"
#include <deque>
#include <map>
#include <functional>
#include <string>
#include <memory>

#include "Definitions.h"
#include "Window.h"
#include "SFML/Graphics.hpp"

typedef std::deque< std::pair<std::string, std::function< void() >>> menu_list;

class Menu : public MainMenu
{
public:
	Menu(const bool& can_get_back = false);
	~Menu();

	void set(const std::string str, std::function< void() > lambda);
	void unSet(const std::string& str);
	void setFront(const std::string str, std::function< void() > lambda);
	bool inMenu(const std::string& str);
	void run();

	inline void setInMenu(bool m)
	{in_Menu = m;}
	explicit operator bool()const 
	{return in_Menu;}

protected:
	menu_list::iterator getIterator(const std::string& str);
	void handleEvent();
	void drawOnScreen();
	bool in_Menu = true;
	bool can_g_back;
	bool go_back = false;
	int mOptionIndex = 0;
	menu_list m_list;
	Window &m_window = Window::instance();

};
