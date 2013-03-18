#include "GameState.h"
#include "Level_One.h"

GameState::GameState()
{	 
}

GameState::~GameState()
{
}

GameState::TileVector& GameState::getTileVector()
{
	return mTiles;
}
GameState::HumanVector& GameState::getHumanVector()
{
	return mHumans;
}
GameState::ZombieVector& GameState::getZombieVector()
{
	return mZombies;
}
GameState::StunnVector& GameState::getStunnVector()
{
	return mStunns;
}
bool& GameState::getHumanTurn()
{
	return m_Human_Turn;
}
int& GameState::get_Human_Action_Points()
{
	return m_Human_Action_Points;
}
int& GameState::get_Zombie_Action_Points()
{
	return m_Zombie_Action_Points;
}
int& GameState::getHumanIngameScore()
{
	return m_Human_InGame_Score;
}
int& GameState::getZombieIngameScore()
{
	return m_Zombie_InGame_Score;
}