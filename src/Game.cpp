#include "Game.h"
#include <iostream>
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
Game::Game()
{
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
Game::~Game()
{
}
//------------------------------------------------------------------------//
// ------------------------ running the game ----------------------------//
//----------------------------------------------------------------------//
GameState Game::run()
{
	bool loadStage = true;
	StageData::instance().resetPowers();
	while (m_StageLoader)
	{	
		loadStage = true;
		if ((m_stage && m_stage->getGameState() == GameState::Win) ||
			!m_stage || m_stage->getGameState() == GameState::Lose) 
		{
			if (m_stage && m_stage->getGameState() == GameState::Lose)
				loadStage = false;

				m_stage = nullptr;
				m_stage = m_StageLoader.loadNewStage(loadStage);
		}
		else {
			m_stage->run();
			m_StageLoader.drawStatus(m_stage->getGameState());
			if (m_stage->getGameState() == GameState::Win || m_stage->getGameState() == GameState::Lose)
				continue;
			SoundPlayer::addMusic(TITLE_MUSIC);
			return m_stage->getGameState();
		}
	}
	m_StageLoader.drawStatus(GameState::Accomplished);
	return GameState::Accomplished;
}
