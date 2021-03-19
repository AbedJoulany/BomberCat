#pragma once
#include "GameStatus.h"
#include "Window.h"
#include "Board.h"
#include "Bomb.h"

class Stage
{
public:
	// --------- Constrctors ---------- // 
	Stage();
	Stage(std::shared_ptr<Board> board);
	~Stage();
	// ------ setting Functions ----- // 
	void setStatics(staticsV& sV);
	void setHidden(hiddenV& hV);
	void setMonsters(monstersV& mV);
	void setPlayer(std::unique_ptr<BomberMan>&bM);
	void setBomb();
	void makeExplosions(const sf::Vector2i& pos);
	// ------ getting Functions ----- // 
	GameState getGameState()const;
	// ------ drawing Functions ----- // 
	void drawObjects();
	void reScaleObjects();
	void drawStatusList();
	void run();
	// ------ handling Functions ----- // 
	void handle_movement();
	void handle_collisions();
	void handle_bombs();
	// -------collision Functions ------ //
	void collisionFiretoPlayer();
	void collisionFiretoMonster();
	void collisionPlayerToMonster();
	void collisionPlayerToWall();
	void collisionPlayerToBomb();
	// ------ functions section ----- // 
private:
	void updateStage();
	void updateTime();
	// ------ variables section ----- // 
private:

	Window& m_window = Window::instance();
	std::shared_ptr<Board> m_board;
	staticsV m_statics;
	monstersV m_monsters;
	hiddenV m_hidden;
	std::unique_ptr<BomberMan> m_BombMan;
	std::vector<std::unique_ptr<Bomb>>BombsVec;
	std::vector<std::unique_ptr<FireFlame>> fireVec;
	sf::Clock m_deltaTime;
	bool scaled = false;
	GameState m_state = GameState::Playing;
};