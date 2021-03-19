#pragma once
#include "MenuOptions.h"
//#include "mutex"
#include "GameStatus.h"
#include <iostream>
#include <memory>

std::once_flag flag1;

template<typename Y>
class Play : public MenuOptions
{
public:
	Play();
	~Play();
	template<typename T>
	void set(T& menu);
private:
	std::unique_ptr<Y> m_game;
};

//------------------------------ c-tor ----------------------------------------
template<typename Y>
inline Play<Y>::Play()
{
}
//------------------------------ d-tor ----------------------------------------
template<typename Y>
inline Play<Y>::~Play() {}

//------------------------- register label into menu --------------------------
template<typename Y>
template<typename T>
inline void Play<Y>::set(T& menu)
{
	menu.set(NEW_GAME, [&menu, this]()->void
		{
			if (!menu.inMenu(CONTINUE)) {

				menu.setFront(CONTINUE, [&menu, this]()->void {

					GameState state = m_game->run();
					if (state == GameState::Game_OVER ||
						state == GameState::Accomplished)
					{
						menu.unSet(CONTINUE);
					}
					});
			}
			m_game = nullptr;
			m_game = std::make_unique<Y>();
			GameState state = m_game->run();
			if (state == GameState::Game_OVER ||
				state == GameState::Accomplished)
			{
				menu.unSet(CONTINUE);
			}
		});
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------