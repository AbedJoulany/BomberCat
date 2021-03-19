#pragma once
#include "BomberMan.h"
#include "BalloonMonster.h"
#include "SlimeMonster.h"
#include "SolidWall.h"
#include "RockWall.h"
#include "FireFlame.h"
#include "StageData.h"
#include "PowerUpSpeed.h"
#include "PoweUpBomb.h"
#include "PoweUpFlame.h"
#include "PowerUpTime.h"
#include "Door.h"
#include "Bomb.h"
#include <memory>

//
void coll_between_SM_B(GameObject*& Slime, GameObject*& Bomber);
//
void coll_between_BM_B(GameObject*& Balloon, GameObject*& Bomber);
//
void coll_between_SW_B(GameObject*& StoneWall, GameObject*& Bomber);
//
void coll_between_RW_B(GameObject*& RockWall, GameObject*& Bomber);
//
void coll_between_SW_BM(GameObject*& StoneWall, GameObject*& Ballon);
//
void coll_between_RW_BM(GameObject*& RockWall, GameObject*& Ballon);
//
void coll_between_SW_SM(GameObject*& StoneWall, GameObject*& Slime);
//
void coll_between_RW_SM(GameObject*& RockWall, GameObject*& Slime);
//
void coll_between_F_B(GameObject*& Flame, GameObject*& Bomber);
//
void coll_between_F_BM(GameObject*& Flame, GameObject*& Balloon);
//
void coll_between_BO_B(GameObject*& bomb, GameObject*& Bomber);
//
void coll_between_BO_BM(GameObject*& bomb, GameObject*& Balloon);
//
void coll_between_BO_SM(GameObject*& bomb, GameObject*& Slime);
//
void coll_between_F_SM(GameObject*& Flame, GameObject*& Slime);
//
void coll_between_F_RW(GameObject*& Flame, GameObject*& Rockwall);
//
void coll_between_F_SW(GameObject*& Flame, GameObject*& Stonewall);
//
void coll_between_PB_B(GameObject*& PoweBomb, GameObject*& Bomber);
//
void coll_between_PS_B(GameObject*& PowerSpeed, GameObject*& Bomber);
//
void coll_between_PF_B(GameObject*& PowerFlame, GameObject*& Bomber);
//
void coll_between_PT_B(GameObject*& PowerTime, GameObject*& Bomber);
//
void coll_between_D_B(GameObject*& Door, GameObject*& Bomber);
//-----------------------------------------------------------------//
//----------------------------------------------------------------//
//---------------------------------------------------------------//
void coll_between_B_SM(GameObject*& Bomber, GameObject*& Slime);
//
void coll_between_B_BM(GameObject*& Bomber, GameObject*& Balloon);
//
void coll_between_B_SW(GameObject*& Bomber, GameObject*& StoneWall);
//
void coll_between_B_RW(GameObject*& Bomber, GameObject*& RockWall);
//
void coll_between_BM_SW(GameObject*& Ballon, GameObject*& StoneWall);
//
void coll_between_BM_RW(GameObject*& Ballon, GameObject*& RockWall);
//
void coll_between_SM_SW(GameObject*& Slime, GameObject*& StoneWall);
//
void coll_between_SM_RW(GameObject*& Slime, GameObject*& RockWall);
//
void coll_between_B_F(GameObject*& bomber, GameObject*& flame);
//
void coll_between_BM_F(GameObject*& Ballon, GameObject*& flame);
//
void coll_between_SM_F(GameObject*& Slime, GameObject*& flame);
//
void coll_between_RW_F(GameObject*& RockWall, GameObject*& Flame);
//
void coll_between_SW_F(GameObject*& StoneWall, GameObject*& Flame);
//
void coll_between_B_BO(GameObject*& bomber, GameObject*& bomb);
//
void coll_between_BM_BO(GameObject*& ballon, GameObject*& bomb);
//
void coll_between_SM_BO(GameObject*& slime, GameObject*& bomb);
//----------------------------------------------------------------------------//
void setBomberColissions();
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------