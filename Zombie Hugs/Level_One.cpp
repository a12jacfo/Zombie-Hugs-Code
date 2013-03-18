#include "Level_One.h"
#include "Level_One_Tiles.h"
#include "ConfigFile.h"

#include "ImageManager.h"
#include "AbilityManager.h"
#include "AudioManager.h"
#include "HudManager.h"
#include "InputManager.h"

#include "HumanHero.h"
#include "HumanStunner.h"
#include "HumanHealer.h"
#include "HumanCatcher.h"

#include "ZombieHero.h"
#include "ZombieStunner.h"
#include "ZombieHealer.h"
#include "ZombieCatcher.h"

#include "Tile.h"

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

Level_One::Level_One() :
	m_Human_Turn(true),
	m_Unit_is_Walking(false)
{
	//m_soundSound.setBuffer(AudioManager::getInstance()->get_sound("Resources/Audio/music.ogg"));

	background.setTexture(ImageManager::getInstance()->get_image("Resources/Images/lvl01_grid.png"));
	background.setPosition(background.getPosition().x+1,background.getPosition().y);

	addTile();
	addNeighbors();

	HumanHero* humanHero = new HumanHero(*mTiles[93], "HHero");
	mHumans.push_back(humanHero);
	mTiles[93]->setOccupied(true);

	HumanStunner* humanStunner = new HumanStunner(*mTiles[100], "HStunner");
	mHumans.push_back(humanStunner);
	mTiles[100]->setOccupied(true);

	HumanCatcher* humanCatcher1 = new HumanCatcher(*mTiles[99], "HCatcher1");
	mHumans.push_back(humanCatcher1);
	mTiles[99]->setOccupied(true);

	HumanCatcher* humanCatcher2 = new HumanCatcher(*mTiles[113], "HCatcher2");
	mHumans.push_back(humanCatcher2);
	mTiles[113]->setOccupied(true);

	HumanHealer* humanHealer = new HumanHealer(*mTiles[128], "HHealer");
	mHumans.push_back(humanHealer);
	mTiles[128]->setOccupied(true);

	ZombieHero* zombieHero = new ZombieHero(*mTiles[77], "ZHero");
	mZombies.push_back(zombieHero);
	mTiles[77]->setOccupied(true);

	ZombieStunner* zombieStunner = new ZombieStunner(*mTiles[2], "ZStunner");
	mZombies.push_back(zombieStunner);
	mTiles[2]->setOccupied(true);


	ZombieCatcher* zombieCatcher1 = new ZombieCatcher(*mTiles[92], "ZCatcher1");
	mZombies.push_back(zombieCatcher1);
	mTiles[92]->setOccupied(true);

	ZombieCatcher* zombieCatcher2 = new ZombieCatcher(*mTiles[30], "ZCatcher2");
	mZombies.push_back(zombieCatcher2);
	mTiles[30]->setOccupied(true);

	ZombieHealer* zombieHealer = new ZombieHealer(*mTiles[29], "ZHealer");
	mZombies.push_back(zombieHealer);
	mTiles[29]->setOccupied(true);

	sf::Vector2f lpos(0,0);
	sf::Vector2f rpos(1185,0);
	leftSide = new SideHUD(lpos, "Zombie");
	rightSide = new SideHUD(rpos, "Human");

	mActiveUnit = 0;

	ConfigFile cfg("config.txt");

	m_Human_Action_Points = cfg.getValueOfKey<int>("m_Action_Points");
	std::cout << "m_Human_Action_Points: " << m_Human_Action_Points << "\n\n";
	m_Zombie_Action_Points = cfg.getValueOfKey<int>("m_Action_Points");
	std::cout << "m_Zombie_Action_Points: " << m_Zombie_Action_Points<< "\n\n";

	m_Move_Cost = cfg.getValueOfKey<int>("m_Move_Cost");
	m_Heal_Cost = cfg.getValueOfKey<int>("m_Heal_Cost");
	m_Catch_Cost = cfg.getValueOfKey<int>("m_Catch_Cost");
	m_Stunn_Cost_Unit = cfg.getValueOfKey<int>("m_Stunn_Cost_Unit");
	m_Stunn_Cost_Ground = cfg.getValueOfKey<int>("m_Stunn_Cost_Ground");
	m_Damage_Const = cfg.getValueOfKey<int>("m_Damage_Const");
	m_Call_In_Hero_Cost = cfg.getValueOfKey<int>("m_Call_In_Hero_Cost");
	m_Stunn_Duration_Unit = cfg.getValueOfKey<int>("m_Stunn_Duration_Unit");
	m_Stunn_Duration_Ground = cfg.getValueOfKey<int>("m_Stunn_Duration_Ground");
	m_Stunn_SuccessRate_Unit = cfg.getValueOfKey<int>("m_Stunn_SuccessRate_Unit");
	m_Stunns_Per_Stunner_Per_Round = cfg.getValueOfKey<int>("m_Stunns_Per_Stunner_Per_Round");
	m_Stunners_Total_Active_Stunns = cfg.getValueOfKey<int>("m_Stunners_Total_Active_Stunns");
	m_Heals_Per_Healer_Per_Round = cfg.getValueOfKey<int>("m_Heals_Per_Healer_Per_Round");
	m_Damages_Per_Healer_Per_Round = cfg.getValueOfKey<int>("m_Damages_Per_Healer_Per_Round");

}

Level_One::~Level_One()
{
	while(!mZombies.empty())
	{
		delete mZombies.back();
		mZombies.pop_back();
	}
	while(!mHumans.empty())
	{
		delete mHumans.back();
		mHumans.pop_back();
	}
	while(!mTiles.empty())
	{
		delete mTiles.back();
		mTiles.pop_back();
	}
}

void Level_One::addTile()
{
	sf::Vector2f pos(171,175);
	sf::Vector2f cord(0,0);
	for(int i = 0; i < 130; i++)
	{
		if(i == 14){ pos.x = 134; pos.y = 229; cord.x = 0; cord.y = 1;} // RAD 2
		if(i == 29){ pos.x = 170; pos.y = 283; cord.x = 0; cord.y = 2;} // RAD 3
		if(i == 43){ pos.x = 134; pos.y = 337; cord.x = 0; cord.y = 3;} // RAD 4
		if(i == 58){ pos.x = 170; pos.y = 391; cord.x = 0; cord.y = 4;} // RAD 5
		if(i == 72){ pos.x = 134; pos.y = 445; cord.x = 0; cord.y = 5;} // RAD 6
		if(i == 87){ pos.x = 170; pos.y = 499; cord.x = 0; cord.y = 6;} // RAD 7
		if(i == 101){ pos.x = 134; pos.y = 553; cord.x = 0; cord.y = 7;} // RAD 8
		if(i == 116){ pos.x = 170; pos.y = 607; cord.x = 0; cord.y = 8;} // RAD 9
		if(i == 130){ pos.x = 134; pos.y = 661; cord.x = 0; cord.y = 9;} // RAD 10
		if(i == 145){ pos.x = 170; pos.y = 715; cord.x = 0; cord.y = 10;} // RAD 11
	
		Tile *tile = new Tile(pos,cord);
		mTiles.push_back(tile);
		pos.x = pos.x + 72;
		cord.x = cord.x + 1;
	}
}
GameState* Level_One:: switchState(GameState* state)
{
	return state;
}

void Level_One::rightMouseClick(sf::RenderWindow& window)
{
	AbilityManager::setAllAbilityToFalse();
	HudManager::getInstance()->HideAbilityHud();

	if(mActiveUnit != 0)
	{
		mActiveUnit->setDeactive();
		mActiveUnit->getCurrentTile().setDeactive();
		mActiveUnit->getCurrentTile().setDeactiveWalls();
	}
	mActiveUnit = 0;
}

void Level_One::leftMouseClick(sf::RenderWindow& window)
{
	float mPosX = sf::Mouse::getPosition(window).x;
	float mPosY = sf::Mouse::getPosition(window).y;

	if(m_Unit_is_Walking == false)
	{
 		InputManager::update(mActiveUnit,mPosX,mPosY, getHumanVector(), getZombieVector(), getStunnVector(), getHumanTurn(), get_Human_Action_Points(), get_Zombie_Action_Points());
	}
	if(m_Human_Turn == true)
	{
		if(AbilityManager::isAnyAbilityActive() == false)
		{
			for(HumanVector::size_type h = 0; h < mHumans.size(); h++)
			{	
				if(mHumans[h]->getBoundingBox().getGlobalBounds().contains(mPosX,mPosY))
				{
					if(mHumans[h] == mActiveUnit)
					{
						mActiveUnit = mHumans[h];
						HudManager::getInstance()->ShowAbilityHud(*mActiveUnit);
						mActiveUnit->setActive();
						break;
					}
					else if(mHumans[h] != mActiveUnit)
					{
						if(mActiveUnit != 0)
						{
							mActiveUnit->setDeactive();
							mActiveUnit->getCurrentTile().setDeactive();
							mActiveUnit->getCurrentTile().setDeactiveWalls();
							HudManager::getInstance()->getAbilityVector().clear();
							mActiveUnit->SetActiveSound(false);
						}

						mActiveUnit = mHumans[h];
						HudManager::getInstance()->ShowAbilityHud(*mActiveUnit);
						mActiveUnit->getCurrentTile().setActive();
						mActiveUnit->setActive();
						mActiveUnit->SetActiveSound(true);
						break;
					}
				}
			}
		} // HUMAN END
	}
	if(m_Human_Turn == false)
	{
		if(AbilityManager::isAnyAbilityActive() == false)
		{
			for(ZombieVector::size_type h = 0; h < mZombies.size(); h++)
			{
				if(mZombies[h]->getBoundingBox().getGlobalBounds().contains(mPosX,mPosY))
				{
					if(mZombies[h] == mActiveUnit)
					{
						mActiveUnit = mZombies[h];
						HudManager::getInstance()->ShowAbilityHud(*mActiveUnit);
						mActiveUnit->setActive();
						break;
					}
					else if(mZombies[h] != mActiveUnit)
					{
						if(mActiveUnit != 0)
						{
							mActiveUnit->setDeactive();
							mActiveUnit->getCurrentTile().setDeactive();
							mActiveUnit->getCurrentTile().setDeactiveWalls();
							HudManager::getInstance()->getAbilityVector().clear();
							mActiveUnit->SetActiveSound(false);
						}
						mActiveUnit = mZombies[h];
						HudManager::getInstance()->ShowAbilityHud(*mActiveUnit);
						mActiveUnit->getCurrentTile().setActive();
						mActiveUnit->setActive();
						mActiveUnit->SetActiveSound(true);
						break;
					}
				}

			}
		}
	}
}


void Level_One::run(sf::RenderWindow& window)
{
	window.draw(background);

	rightSide->update(window, m_Human_Action_Points, mHumans, mZombies);
	leftSide->update(window, m_Zombie_Action_Points, mHumans, mZombies);

	for(TileVector::size_type i = 0; i < mTiles.size(); i++)
	{
		mTiles[i]->update(window);
	}

	for(StunnVector::size_type i = 0; i < mStunns.size(); i++)
	{
		mStunns[i]->update(window);
	}

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[0]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[0]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[14]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[14]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } } 

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[29]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[29]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[43]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[43]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[58]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[58]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[72]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[72]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[87]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[87]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[101]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[101]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[116]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[116]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking);} }

	HudManager::getInstance()->update(window);
}

Level_One::TileVector& Level_One::getTileVector()
{
	return mTiles;
}
Level_One::HumanVector& Level_One::getHumanVector()
{
	return mHumans;
}
Level_One::ZombieVector& Level_One::getZombieVector()
{
	return mZombies;
}
Level_One::StunnVector& Level_One::getStunnVector()
{
	return mStunns;
}
bool& Level_One::getHumanTurn()
{
	return m_Human_Turn;
}
int& Level_One::get_Human_Action_Points()
{
	return m_Human_Action_Points;
}
int& Level_One::get_Zombie_Action_Points()
{
	return m_Zombie_Action_Points;
}
void Level_One::addNeighbors()
{
	Level_One_Tiles::insertTiles(getTileVector());
}