#include "Board.h"
#include "Definitions.h"
#include "LogFile.h"
#include "BalloonMonster.h"
#include "SlimeMonster.h"
#include "SolidWall.h"
#include "RockWall.h"
#include "Door.h"
#include "Bomb.h"
#include "FireFlame.h"
#include "PowerUpTime.h"
#include "PoweUpFlame.h"
#include "PowerUpSpeed.h"
#include "PoweUpBomb.h"
#include <fstream>
#include <iostream>
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
Board::Board()
{
	setLevels();
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
Board::~Board()
{
	levels_List.clear();
}
//------------------------------------------------------------------------//
// ------------------------ setting levels ------------------------------//
//----------------------------------------------------------------------//
void Board::setLevels()
{
	std::ifstream levels(LEVELS_FILE);
	std::string str;
	try {
		if (!levels.is_open())
			throw std::runtime_error("Can't open Levels File\n");
	}
	catch (std::exception & e)
	{
		e.what();
		LogFile::instance().write(e.what());
		exit(EXIT_FAILURE);
	}

	while (!levels.eof())
	{
		levels >> str;
		levels_List.push_back(str);
	}
}
//------------------------------------------------------------------------//
// ------------------------ loading the stage ---------------------------//
//----------------------------------------------------------------------//
bool Board::loadStage()
{
	char c;
	// --------------- reading board from file ------------------------//
	if (levels_List.front() == EXIT)
	{
		m_board.first = levels_List.front();
		m_board.second.clear();
		return false;
	}
	std::ifstream level(levels_List.front());

	if (!level.is_open())
		throw std::runtime_error("Can't open Level File :" + levels_List.front() + "\n");

	m_board.first = levels_List.front();

	level >> mapSize;
	if(level.fail())
		throw std::runtime_error("failed to read board size:" + levels_List.front() + "\n");

	m_statics.clear();
	m_monsters.clear();
	m_hidden.clear();
	m_board.second.resize(mapSize);
	BoardScale::instance().setBoardScale(mapSize);

	for (int i = 0; i < mapSize; i++)
	{
		m_board.second[i].resize(mapSize);

		for (int j = 0; j < mapSize; j++)
		{
			level >> std::noskipws >> c;

			if (c == '\n')
				level >> c;

			setChar(c, i, j);
			m_board.second.at(i).at(j) = c;
		}
	}
	levels_List.pop_front();

	return true;
}
//------------------------------------------------------------------------//
// ------------------------ reseting stage if lost ----------------------//
//----------------------------------------------------------------------//
void Board::resetStage()
{
	getMonsters().clear();
	getStatics().clear();
	getHidden().clear();
	for (int i = 0; i < m_board.second.size(); i++)
	{
		for (int j = 0; j < m_board.second.at(i).size(); j++)
		{
			setChar(m_board.second.at(i).at(j), i, j);
		}
	}
}
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
level_Board Board::getLevel() const
{
	return m_board;
}
//------------------------------------------------------------------------//
// -------------------- checking if all levels are done -----------------//
//----------------------------------------------------------------------//
std::string Board::getNextLevelName() const
{
	return this->levels_List.front();
}
//------------------------------------------------------------------------//
// --------------- getting the statics dataStruct -----------------------//
//----------------------------------------------------------------------//
staticsV& Board::getStatics()
{

	return m_statics;
}
//------------------------------------------------------------------------//
// --------------- getting the hidden statics dataStruct ----------------//
//----------------------------------------------------------------------//
staticsV& Board::getHidden()
{
	return m_hidden;
}
//------------------------------------------------------------------------//
// --------------- getting the monsters dataStruct ----------------------//
//----------------------------------------------------------------------//
monstersV& Board::getMonsters()
{
	return m_monsters;
}
//------------------------------------------------------------------------//
// --------------- getting the player -----------------------------------//
//----------------------------------------------------------------------//
std::unique_ptr<BomberMan>& Board::getBomberMan()
{
	return Bomber_Man;
}
//------------------------------------------------------------------------//
// --------------- setting the objects in dataStruct --------------------//
//----------------------------------------------------------------------//
void Board::setChar(const char& c, int i, int j)
{
	switch (Objects(c))
	{
	case Objects::BomberMan:
		if (Bomber_Man == nullptr)
		Bomber_Man = std::make_unique<BomberMan>(sf::Vector2f(i, j));
		break;
	case Objects::BallonMonster:
		getMonsters().emplace_back(std::make_unique<BalloonMonster>(sf::Vector2f(i, j)));
		break;
	case Objects::SlimeMonster:
		getMonsters().emplace_back(std::make_unique<SlimeMonster>(sf::Vector2f(i, j)));
		break;
	case Objects::SolidWALL:
		getStatics().emplace_back(std::make_unique<SolidWall>(sf::Vector2f(i, j)));
		break;
	case Objects::RockWall:
		getStatics().emplace_back(std::make_unique<RockWall>(sf::Vector2f(i, j)));
		break;
	case Objects::Door:
		m_hidden.emplace_back(std::make_unique<Door>(sf::Vector2f(i, j)));
		getStatics().emplace_back(std::make_unique<RockWall>(sf::Vector2f(i, j)));
		break;
	case Objects::PowerUpBomb:
		m_hidden.emplace_back(std::make_unique<PowerUpBomb>(sf::Vector2f(i, j)));
		getStatics().emplace_back(std::make_unique<RockWall>(sf::Vector2f(i, j)));
		break;
	case Objects::PowerUpFlame:
		m_hidden.emplace_back(std::make_unique<PowerUpFlame>(sf::Vector2f(i, j)));
		getStatics().emplace_back(std::make_unique<RockWall>(sf::Vector2f(i, j)));
		break;
	case Objects::PowerUpSpeed:
		m_hidden.emplace_back(std::make_unique<PowerUpSpeed>(sf::Vector2f(i, j)));
		getStatics().emplace_back(std::make_unique<RockWall>(sf::Vector2f(i, j)));
		break;
	case Objects::PowerUpTime:
		m_hidden.emplace_back(std::make_unique<PowerUpTime>(sf::Vector2f(i, j)));
		getStatics().emplace_back(std::make_unique<RockWall>(sf::Vector2f(i, j)));
		break;
	case Objects::Empty:
		break;
	default:
		std::string err = "in " + std::string(__FILE__) +
			" :" + std::to_string(__LINE__) + c + "is invalid Object\n";
		throw std::runtime_error(err);
		break;
	}
}
//------------------------------------------------------------------------//
// ----------------------------------------------------------------------//
//----------------------------------------------------------------------//
