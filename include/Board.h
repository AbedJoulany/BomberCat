#pragma once
#include <queue>
#include <string>
#include <functional>
#include "Window.h"
#include "Static.h"
#include "BomberMan.h"
#include "BoardScale.h"
#include "AbsExplosion.h"
#include "Objects.h"
class Monster;

typedef std::pair<std::string, std::vector<std::vector<char>>> level_Board;
typedef std::vector<std::unique_ptr<Static>> staticsV;
typedef std::vector<std::unique_ptr<Static>> hiddenV;
typedef std::vector<std::unique_ptr<Monster>> monstersV;

class Board
{
public:

	Board();
	~Board();
	bool loadStage();
	void resetStage();
	//-----------------------------------//
	level_Board getLevel() const; 
	std::string getNextLevelName() const;
	staticsV& getStatics();
	staticsV& getHidden();
	monstersV& getMonsters();
	std::unique_ptr<BomberMan>& getBomberMan();

private:
	//--------------- Objects section -------------------
	std::deque<std::string> levels_List;
	level_Board m_board;
	Window& m_window = Window::instance();
	std::unique_ptr<BomberMan> Bomber_Man;
	staticsV m_statics;
	staticsV m_hidden;
	monstersV m_monsters;
	int mapSize;
	//--------------- functions section -------------------
	void setLevels();
	void setChar(const char&c , int i, int j);

public:

};