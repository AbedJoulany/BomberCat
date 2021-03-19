#pragma once
#include "Window.h"
#include "Stage.h"
#include "Board.h"
#include "StageData.h"


class StageLoader
{
public:

	StageLoader();
	~StageLoader();
	std::unique_ptr<Stage> loadNewStage(const bool& NewStage);
	operator bool();

	void drawStageNum();
	void drawInMid(const std::string& st, const float& sec = 1);
	void drawStatus(const GameState& state);


private:
	int stageCount = 1;
	int m_lives;
	Window& m_window = Window::instance();
	std::shared_ptr<Board> m_board;
	level_Board m_level;
	// function to load stage from board
	bool lSFBoard();
};