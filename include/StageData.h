#pragma once
#include "SFML/Graphics.hpp"

const int TIME_BONUS = 60;
class StageData
{
public:
	//-------- singlton ---------//
	static StageData& instance();
	//-------- Stage section -----------//
	void resetStageStatus();
	void resetLive();
	void resetScore();
	void resetTimer();
	void setMonstersToKill(const int & num);
	void decreaseMonstersToKill();
	void decreaseLife();
	void increaseScore(const int& earned);
	void updateTimer(sf::Clock &dt);
	const int& getScore();
	const int& getLives();
	const int& getTimer();
	const int& getMonstersLeft();
	//------- powerUps section ---------//
	void PowerBombIncrease();
	void PowerSpeedIncrease();
	void PowerFlameIncrease();
	void PowerTimeIncrease();
	bool BombSetAllowed() const;
	void BombSetted();
	void BombExploded();
	void resetPowers();
	const int& getBombNum();
	const float& getSpeedMovement();
	const int& getFlameSize();

	//-------- Private section ----------//
private:
	StageData();
	~StageData() {};
	int m_monsterleft;
	int m_lives;
	int m_score;
	int m_timerCountDown;
	int m_flameSize;
	int m_bombNum;
	int m_settedBomb;
	float m_speedMovement;

};