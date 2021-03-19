#pragma once
#include "GameStatus.h"
#include "StageLoader.h"
#include <memory>


class Game
{
public:

	Game();
	~Game();
	GameState run();

private:

	StageLoader m_StageLoader;

	Window& m_window = Window::instance();
	GameState m_state = GameState::Playing;
	std::unique_ptr<Stage> m_stage;

};