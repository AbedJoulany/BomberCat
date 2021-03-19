#pragma once
#include "CollisionData.h"
#include "CollideManager.h"
#include <iostream>


//-------------------------------------------------------------------//
//-------- collission between bomberMan and slime Monster ----------//
//-----------------------------------------------------------------//
void coll_between_B_SM(GameObject*& Bomber, GameObject*& Slime)
{
	if (Slime->isDrawable() && Slime->getRect().contains(Bomber->getMidPoint()))
	{
		dynamic_cast<BomberMan*>(Bomber)->die(true);
		SoundPlayer::play("Dead.wav");
	}
}
//---------------------------------------------------------------------//
//-------- collission between bomberMan and balloon Monster ----------//
//-------------------------------------------------------------------//
void coll_between_B_BM(GameObject*& Bomber, GameObject*& Balloon)
{
	if (Balloon->isDrawable() && Balloon->getRect().contains(Bomber->getMidPoint()))
	{
		dynamic_cast<BomberMan*>(Bomber)->die(true);
		SoundPlayer::play("Dead.wav");
	}
}
//--------------------------------------------------------------------//
//-------- collission between bomberMan and the SolidWall -----------//
//------------------------------------------------------------------//
void coll_between_B_SW(GameObject*& Bomber, GameObject*& StoneWall)
{
	if (StoneWall->isDrawable() && StoneWall->getRect().intersects(Bomber->getRect()))
	{
		// recovering the collission because in some times the player stuck on a corner or between to walls
		// so thats is not good for playing and controlling the player
		Bomber->recoverCollision(StoneWall->getRect());
		Bomber->undoMovement();
		return;
	}
}
//--------------------------------------------------------------------//
//-------- collission between bomberMan and the RockWall ------------//
//------------------------------------------------------------------//
inline void coll_between_B_RW(GameObject*& Bomber, GameObject*& RockWall)
{
	if (RockWall->isDrawable() && RockWall->getRect().intersects(Bomber->getRect()))
	{
		// recovering the collission because in some times the player stuck on a corner or between to walls
		// so thats is not good for playing and controlling the player
		Bomber->recoverCollision(RockWall->getRect());
		Bomber->undoMovement();
		return;
	}
}
//--------------------------------------------------------------------//
//-------- collission between BalloonMonster and solidWall ----------//
//------------------------------------------------------------------//
inline void coll_between_SW_BM(GameObject*& StoneWall, GameObject*& Ballon)
{
	if (StoneWall->isDrawable() && StoneWall->getRect().intersects(Ballon->getRect()))
	{
		Ballon->undoMovement();
		Ballon->recoverCollision(StoneWall->getRect());
	}
}
//--------------------------------------------------------------------//
//-------- collission between BalloonMonster and RockWall -----------//
//------------------------------------------------------------------//
inline void coll_between_RW_BM(GameObject*& RockWall, GameObject*& Ballon)
{
	if (RockWall->isDrawable() && RockWall->getRect().intersects(Ballon->getRect()))
	{
		Ballon->undoMovement();
		Ballon->recoverCollision(RockWall->getRect());
	}
}
//--------------------------------------------------------------------//
//--------- collission between SlimeMonster and StoneWall -----------//
//------------------------------------------------------------------//
inline void coll_between_SW_SM(GameObject*& StoneWall, GameObject*& Slime)
{
	if (StoneWall->isDrawable() && StoneWall->getRect().intersects(Slime->getRect()))
	{
		Slime->undoMovement();
		Slime->recoverCollision(StoneWall->getRect());
	}
}
//--------------------------------------------------------------------//
//--------- collission between SlimeMonster and RockWall ------------//
//------------------------------------------------------------------//
inline void coll_between_RW_SM(GameObject*& RockWall, GameObject*& Slime)
{
	if (RockWall->isDrawable() && RockWall->getRect().intersects(Slime->getRect()))
	{
		Slime->undoMovement();
		Slime->recoverCollision(RockWall->getRect());
	}
}
//--------------------------------------------------------------------//
//--------- collission between bomberMan and Fire -------------------//
//------------------------------------------------------------------//
inline void coll_between_F_B(GameObject*& Fire, GameObject*& Bomber)
{
	auto bomber = dynamic_cast<BomberMan*>(Bomber);
	if (Fire->getRect().contains(bomber->getMidPoint()))
	{
		bomber->die(true);
		SoundPlayer::play("Dead.wav");
	}
}
//--------------------------------------------------------------------//
//--------- collission between Ballon Monster and Fire --------------//
//------------------------------------------------------------------//
inline void coll_between_F_BM(GameObject*& Fire, GameObject*& Balloon)
{
	auto ballon = dynamic_cast<BalloonMonster*>(Balloon);
	if (Fire->getRect().contains(ballon->getMidPoint()) && !ballon->isDead())
	{
		StageData::instance().decreaseMonstersToKill();
		StageData::instance().increaseScore(ballon->getDyingScore());
		ballon->die(true);
	}
}
//--------------------------------------------------------------------//
//---------- collission between bomb and bomberMan ------------------//
//------------------------------------------------------------------//
inline void coll_between_BO_B(GameObject*& bomb, GameObject*& Bomber)
{
	if (bomb->isDrawable() && bomb->getRect().intersects(Bomber->getRect()))
	{
		if (dynamic_cast<Bomb*>(bomb)->inMe())
			return;
		Bomber->undoMovement();
		Bomber->recoverCollision(bomb->getRect());
	}
	else
		dynamic_cast<Bomb*>(bomb)->setInMe(false);
}
//--------------------------------------------------------------------//
//---------- collission between bomb and ballon Monster -------------//
//------------------------------------------------------------------//
inline void coll_between_BO_BM(GameObject*& bomb, GameObject*& Balloon)
{
	if (bomb->isDrawable() && bomb->getRect().intersects(Balloon->getRect()))
	{
		Balloon->undoMovement();
		Balloon->recoverCollision(bomb->getRect());
	}
}
//--------------------------------------------------------------------//
//---------- collission between bomb and slime Monster --------------//
//------------------------------------------------------------------//
inline void coll_between_BO_SM(GameObject*& bomb, GameObject*& Slime)
{
	if (bomb->isDrawable() && bomb->getRect().intersects(Slime->getRect()))
	{
		dynamic_cast<SlimeMonster*>(Slime)->setRunFromBomb(true);
		Slime->undoMovement();
		Slime->recoverCollision(bomb->getRect());
	}
}
//--------------------------------------------------------------------//
//--------- collission between SlimeMonster and Flame ---------------//
//------------------------------------------------------------------//
inline void coll_between_F_SM(GameObject*& Flame, GameObject*& Slime)
{
	auto slime = dynamic_cast<SlimeMonster*>(Slime);
	if (Flame->getRect().contains(Slime->getMidPoint()) && !slime->isDead())
	{
		StageData::instance().decreaseMonstersToKill();
		StageData::instance().increaseScore(slime->getDyingScore());
		slime->die(true);
	}
}
//--------------------------------------------------------------------//
//--------- collission between RockWall and Flame -------------------//
//------------------------------------------------------------------//
inline void coll_between_F_RW(GameObject*& Flame, GameObject*& Rockwall)
{
	if (Rockwall->isDrawable() && Rockwall->getRect().contains(Flame->getMidPoint()))
	{
			Rockwall->setDwarable(false);
		dynamic_cast<FireFlame*>(Flame)->setCollided(true);
	}
}
//--------------------------------------------------------------------//
//--------- collission between StoneWall and Flame ------------------//
//------------------------------------------------------------------//
inline void coll_between_F_SW(GameObject*& Flame, GameObject*& Stonewall)
{
	if (Stonewall->isDrawable() && Stonewall->getRect().contains(Flame->getMidPoint()))
	{
		Flame->setDwarable(false);
		dynamic_cast<FireFlame*>(Flame)->setCollided(true);
	}
}
//--------------------------------------------------------------------//
//--------- collission between bomberMan and BombPowerUp ------------//
//------------------------------------------------------------------//
inline void coll_between_PB_B(GameObject*& PowerBomb, GameObject*& Bomber)
{
	if (PowerBomb->isDrawable() && PowerBomb->getRect().contains(Bomber->getMidPoint()))
	{
		StageData::instance().PowerBombIncrease();
		PowerBomb->setDwarable(false);
		SoundPlayer::play(BONUS_SOUND);
	}
}
//--------------------------------------------------------------------//
//--------- collission between bomberMan and SpeedPowerUp------------//
//------------------------------------------------------------------//
inline void coll_between_PS_B(GameObject*& PowerSpeed, GameObject*& Bomber)
{
	if (PowerSpeed->isDrawable() && PowerSpeed->getRect().contains(Bomber->getMidPoint()))
	{
		StageData::instance().PowerSpeedIncrease();
		PowerSpeed->setDwarable(false);
		SoundPlayer::play(BONUS_SOUND);
	}
}
//--------------------------------------------------------------------//
//--------- collission between bomberMan and FlamePowerUp -----------//
//------------------------------------------------------------------//
inline void coll_between_PF_B(GameObject*& PowerFlame, GameObject*& Bomber)
{
	if (PowerFlame->isDrawable() && PowerFlame->getRect().contains(Bomber->getMidPoint()))
	{
		StageData::instance().PowerFlameIncrease();
		PowerFlame->setDwarable(false);
		SoundPlayer::play(BONUS_SOUND);
	}
}
//--------------------------------------------------------------------//
//--------- collission between bomberMan and Clock Bonus ------------//
//------------------------------------------------------------------//
inline void coll_between_PT_B(GameObject*& PowerTime, GameObject*& Bomber)
{
	if (PowerTime->isDrawable() && PowerTime->getRect().contains(Bomber->getMidPoint()))
	{
		StageData::instance().PowerTimeIncrease();
		PowerTime->setDwarable(false);
		SoundPlayer::play(BONUS_SOUND);
	}
}
//--------------------------------------------------------------------//
//--------- collission between bomberMan and Door -------------------//
//------------------------------------------------------------------//
inline void coll_between_D_B(GameObject*& Door, GameObject*& Bomber)
{
	if (Door->getRect().contains(Bomber->getMidPoint()))
	{
		if (!StageData::instance().getMonstersLeft())
		{
			dynamic_cast<BomberMan*>(Bomber)->setdoorEntered(true);
			SoundPlayer::addMusic(ACCOMPLISHED);
		}
	}
}
//--------------------------------------------------------------/
//--------------------------------------------------------------/
//--------------------------------------------------------------/

void coll_between_SM_B(GameObject*& Slime, GameObject*& Bomber)
{
	coll_between_B_SM(Bomber, Slime);
}
//---------------------------------------------------------
void coll_between_BM_B(GameObject*& Balloon, GameObject*& Bomber)
{
	coll_between_B_BM(Bomber, Balloon);
}
//---------------------------------------------------------
void coll_between_SW_B(GameObject*& StoneWall, GameObject*& Bomber)
{
	coll_between_B_SW(Bomber, StoneWall);
}
inline void coll_between_RW_B(GameObject*& RockWall, GameObject*& Bomber)
{
	coll_between_B_RW(Bomber, RockWall);
}
//---------------------------------------------------------
inline void coll_between_BM_SW(GameObject*& Ballon, GameObject*& StoneWall)
{
	coll_between_SW_BM(StoneWall, Ballon);
}
//---------------------------------------------------------
inline void coll_between_BM_RW(GameObject*& Ballon, GameObject*& RockWall)
{
	coll_between_RW_BM(RockWall, Ballon);
}
//---------------------------------------------------------
inline void coll_between_SM_SW(GameObject*& Slime, GameObject*& StoneWall)
{
	coll_between_SW_SM(StoneWall, Slime);
}
//---------------------------------------------------------
inline void coll_between_SM_RW(GameObject*& Slime, GameObject*& RockWall)
{
	coll_between_RW_SM(RockWall, Slime);
}
//---------------------------------------------------------
inline void coll_between_B_F(GameObject*& Bomber, GameObject*& Fire)
{
	coll_between_F_B(Fire, Bomber);
}
//---------------------------------------------------------
inline void coll_between_BM_F(GameObject*& Ballon, GameObject*& flame)
{
	coll_between_F_BM(flame, Ballon);
}
//---------------------------------------------------------
inline void coll_between_SM_F(GameObject*& Slime, GameObject*& flame)
{
	coll_between_F_SM(flame, Slime);
}
//---------------------------------------------------------
inline void coll_between_RW_F(GameObject*& Rockwall, GameObject*& Flame)
{
	coll_between_F_RW(Flame, Rockwall);
}
//---------------------------------------------------------
inline void coll_between_SW_F(GameObject*& Stonewall, GameObject*& Flame)
{
	coll_between_F_SW(Flame, Stonewall);
}
//---------------------------------------------------------
inline void coll_between_B_BO(GameObject*& bomber, GameObject*& bomb)
{
	coll_between_BO_B(bomb, bomber);
}
//---------------------------------------------------------
inline void coll_between_BM_BO(GameObject*& ballon, GameObject*& bomb)
{
	coll_between_BO_BM(bomb, ballon);
}
//---------------------------------------------------------
inline void coll_between_SM_BO(GameObject*& slime, GameObject*& bomb)
{
	coll_between_BO_SM(bomb, slime);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void setBomberColissions()
{
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(BomberMan).name(),
		typeid(BalloonMonster).name()), &coll_between_B_BM);
	CollideManager::set(std::make_pair(typeid(BalloonMonster).name(),
		typeid(BomberMan).name()), &coll_between_BM_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(BomberMan).name(),
		typeid(SlimeMonster).name()), &coll_between_B_SM);
	CollideManager::set(std::make_pair(typeid(SlimeMonster).name(),
		typeid(BomberMan).name()), &coll_between_SM_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(BomberMan).name(),
		typeid(SolidWall).name()), &coll_between_B_SW);
	CollideManager::set(std::make_pair(typeid(SolidWall).name(),
		typeid(BomberMan).name()), &coll_between_SW_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(BomberMan).name(),
		typeid(RockWall).name()), &coll_between_B_RW);
	CollideManager::set(std::make_pair(typeid(RockWall).name(),
		typeid(BomberMan).name()), &coll_between_RW_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(BomberMan).name(),
		typeid(FireFlame).name()), &coll_between_B_F);
	CollideManager::set(std::make_pair(typeid(FireFlame).name(),
		typeid(BomberMan).name()), &coll_between_F_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(BalloonMonster).name(),
		typeid(SolidWall).name()), &coll_between_BM_SW);
	CollideManager::set(std::make_pair(typeid(SolidWall).name(),
		typeid(BalloonMonster).name()), &coll_between_SW_BM);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(BalloonMonster).name(),
		typeid(RockWall).name()), &coll_between_BM_RW);
	CollideManager::set(std::make_pair(typeid(RockWall).name(),
		typeid(BalloonMonster).name()), &coll_between_RW_BM);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(BalloonMonster).name(),
		typeid(FireFlame).name()), &coll_between_BM_F);
	CollideManager::set(std::make_pair(typeid(FireFlame).name(),
		typeid(BalloonMonster).name()), &coll_between_F_BM);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(SlimeMonster).name(),
		typeid(SolidWall).name()), &coll_between_SM_SW);
	CollideManager::set(std::make_pair(typeid(SolidWall).name(),
		typeid(SlimeMonster).name()), &coll_between_SW_SM);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(SlimeMonster).name(),
		typeid(RockWall).name()), &coll_between_SM_RW);
	CollideManager::set(std::make_pair(typeid(RockWall).name(),
		typeid(SlimeMonster).name()), &coll_between_RW_SM);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(SlimeMonster).name(),
		typeid(FireFlame).name()), &coll_between_SM_F);
	CollideManager::set(std::make_pair(typeid(FireFlame).name(),
		typeid(SlimeMonster).name()), &coll_between_F_SM);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(SolidWall).name(),
		typeid(FireFlame).name()), &coll_between_SW_F);
	CollideManager::set(std::make_pair(typeid(FireFlame).name(),
		typeid(SolidWall).name()), &coll_between_F_SW);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(RockWall).name(),
		typeid(FireFlame).name()), &coll_between_RW_F);
	CollideManager::set(std::make_pair(typeid(FireFlame).name(),
		typeid(RockWall).name()), &coll_between_F_RW);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(SlimeMonster).name(),
		typeid(FireFlame).name()), &coll_between_SM_F);
	CollideManager::set(std::make_pair(typeid(FireFlame).name(),
		typeid(SlimeMonster).name()), &coll_between_F_SM);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(Bomb).name(),
		typeid(BomberMan).name()), &coll_between_BO_B);
	CollideManager::set(std::make_pair(typeid(BomberMan).name(),
		typeid(Bomb).name()), &coll_between_B_BO);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(Bomb).name(),
		typeid(BalloonMonster).name()), &coll_between_BO_BM);
	CollideManager::set(std::make_pair(typeid(BalloonMonster).name(),
		typeid(Bomb).name()), &coll_between_BM_BO);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(Bomb).name(),
		typeid(SlimeMonster).name()), &coll_between_BO_SM);
	CollideManager::set(std::make_pair(typeid(SlimeMonster).name(),
		typeid(Bomb).name()), &coll_between_SM_BO);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(Door).name(),
		typeid(BomberMan).name()), &coll_between_D_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(PowerUpFlame).name(),
		typeid(BomberMan).name()), &coll_between_PF_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(PowerUpSpeed).name(),
		typeid(BomberMan).name()), &coll_between_PS_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(PowerUpBomb).name(),
		typeid(BomberMan).name()), &coll_between_PB_B);
	//--------------------------------------------------------------//
	CollideManager::set(std::make_pair(typeid(PowerUpTime).name(),
		typeid(BomberMan).name()), &coll_between_PT_B);
}