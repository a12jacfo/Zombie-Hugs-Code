#include "Level_One.h"
#include "Level_One_Tiles.h"
#include "ImageManager.h"

#include "HumanHero.h"

#include "Tile.h"
#include <iostream>

Level_One::Level_One() :
	mTargetedUnit(false),
	mMoveAbility(false)
{
	addTile();
	addNeighbors();

	HumanHero* humanHero = new HumanHero(*mTiles[25], "Hero1");
	mHumans.push_back(humanHero);
	mTiles[25]->setOccupied(true);

	HumanHero* humanHero2 = new HumanHero(*mTiles[40], "Hero2");
	mZombies.push_back(humanHero2);
	mTiles[40]->setOccupied(true);

	mActiveUnit = 0;
	mActiveTile = 0;
}

Level_One::~Level_One()
{
	mZombies.clear();
	mHumans.clear();
	mTiles.clear();
}

void Level_One::addTile()
{
	sf::Vector2f pos(170,175);
	for(int i = 0; i < 130; i++)
	{
		if(i == 14){ pos.x = 134; pos.y = 229;} // RAD 2
		if(i == 29){ pos.x = 170; pos.y = 283;} // RAD 3
		if(i == 43){ pos.x = 134; pos.y = 337;} // RAD 4
		if(i == 58){ pos.x = 170; pos.y = 391;} // RAD 5
		if(i == 72){ pos.x = 134; pos.y = 445;} // RAD 6
		if(i == 87){ pos.x = 170; pos.y = 499;} // RAD 7
		if(i == 101){ pos.x = 134; pos.y = 553;} // RAD 8
		if(i == 116){ pos.x = 170; pos.y = 607;} // RAD 9
		if(i == 130){ pos.x = 134; pos.y = 661;} // RAD 10
		if(i == 145){ pos.x = 170; pos.y = 715;} // RAD 11
	
		Tile *tile = new Tile(pos);
		mTiles.push_back(tile);
		pos.x = pos.x + 72;
	}
}


void Level_One::rightMouseClick(sf::RenderWindow& window)
{
	// SHOW SKILL HUD
	if(mActiveUnit != 0)
	{
		if(mActiveUnit->getShowAbilityHud() == false)
		{
			mActiveUnit->showAbilityHud();
			mMoveAbility = false;
			mHealAbility = false;
			mDamageAbility = false;
			mCatchAbility = false;
			mStunnAbility = false;
			for(TileVector::size_type k = 0; k < mActiveTile->getVector().size(); k++)
			{
				mActiveTile->getVector()[k]->setDeactive();
			}
		}
		else
		{
			mActiveUnit->hideAbilityHud();
		}
	}
}

void Level_One::leftMouseClick(sf::RenderWindow& window)
{
	int mPosX = sf::Mouse::getPosition(window).x;
	int mPosY = sf::Mouse::getPosition(window).y;

	if(mActiveUnit != 0 && mActiveUnit->getShowAbilityHud() == true)
	{
		// MOVE ABILITY
		if(mActiveUnit->getAbility("move").getGlobalBounds().contains(mPosX,mPosY)) 
		{
			mActiveUnit->hideAbilityHud();
			mMoveAbility = true;
			for(TileVector::size_type t = 0; t < mActiveUnit->getCurrentTile().getVector().size(); t++)
			{
				mActiveUnit->getCurrentTile().getVector()[t]->setActive();
			}
		}//if move
		// HEAL ABILITY
		if(mActiveUnit->getAbility("heal").getGlobalBounds().contains(mPosX,mPosY))
		{
			mActiveUnit->hideAbilityHud();
			mHealAbility = true;
			for(TileVector::size_type i = 0; i< mActiveUnit->getCurrentTile().getVector().size(); i++)
			{
				if(mActiveTile->getVector()[i]->getOccupied() == true)
				{
					for(HumanVector::size_type q = 0; q < mHumans.size(); q++)
					{
						if(mHumans[q]->getPos() == mActiveUnit->getCurrentTile().getVector()[i]->getPos())
						{
							mActiveUnit->getCurrentTile().getVector()[i]->setActive();
						}
					}
				}
			}
		}//if heal
		//DAMAGE ABILITY
		if(mActiveUnit->getAbility("damage").getGlobalBounds().contains(mPosX,mPosY))
		{
			mActiveUnit->hideAbilityHud();
			mDamageAbility = true;
			for(TileVector::size_type i = 0; i< mActiveUnit->getCurrentTile().getVector().size(); i++)
			{
				if(mActiveTile->getVector()[i]->getOccupied() == true)
				{
					for(ZombieVector::size_type q = 0; q < mZombies.size(); q++)
					{
						if(mZombies[q]->getPos() == mActiveUnit->getCurrentTile().getVector()[i]->getPos())
						{
							mActiveUnit->getCurrentTile().getVector()[i]->setActive();
						}
					}
				}
			}

		}//if damage
		//CATCH ABILITY
		if(mActiveUnit->getAbility("catch").getGlobalBounds().contains(mPosX,mPosY))
		{
			mActiveUnit->hideAbilityHud();
			mCatchAbility = true;
			for(TileVector::size_type i = 0; i< mActiveUnit->getCurrentTile().getVector().size(); i++)
			{
				if(mActiveTile->getVector()[i]->getOccupied() == true)
				{
					for(ZombieVector::size_type q = 0; q < mZombies.size(); q++)
					{
						if(mZombies[q]->getPos() == mActiveUnit->getCurrentTile().getVector()[i]->getPos())
						{
							mActiveUnit->getCurrentTile().getVector()[i]->setActive();
						}
					}
				}
			}
		}//if catch
		//STUNN ABILITY
		if(mActiveUnit->getAbility("stunn").getGlobalBounds().contains(mPosX,mPosY))
		{
			mActiveUnit->hideAbilityHud();
			mStunnAbility = true;
		}//if stunns
	}
	else if(mActiveUnit != 0 && mMoveAbility == true)
	{
		for(TileVector::size_type g = 0; g < mActiveUnit->getCurrentTile().getVector().size(); g++)
		{
			if(mActiveUnit->getCurrentTile().getVector()[g]->getHex().getGlobalBounds().contains(mPosX,mPosY) && mActiveTile->getVector()[g]->getOccupied() == false)
			{
				mActiveTile->setOccupied(false);
				for(TileVector::size_type k = 0; k < mActiveTile->getVector().size(); k++)
				{
					mActiveTile->getVector()[k]->setDeactive();
				}
				mActiveUnit->setPos(mActiveUnit->getCurrentTile().getVector()[g]->getPos());
				mActiveUnit->SetCurrentTile(*mActiveUnit->getCurrentTile().getVector()[g]);
				mActiveTile = &mActiveUnit->getCurrentTile();
				mActiveTile->setOccupied(true);
				for(TileVector::size_type k = 0; k < mActiveTile->getVector().size(); k++)
				{
					mActiveTile->getVector()[k]->setActive();
				}
			}
		}
	}
	else if(mActiveUnit != 0 && mHealAbility == true)
	{
		for(TileVector::size_type w = 0; w < mActiveUnit->getCurrentTile().getVector().size(); w++)
		{
			if(mActiveUnit->getCurrentTile().getVector()[w]->getHex().getGlobalBounds().contains(mPosX,mPosY) && mActiveUnit->getCurrentTile().getVector()[w]->getActive()==true)
			{
				for(HumanVector::size_type z = 0;z<mHumans.size();z++)
				{
					if(mActiveUnit->getCurrentTile().getVector()[w]->getPos() == mHumans[z]->getCurrentTile().getPos())
					{
						if(mActiveUnit->getMorale() > 75)
						{
							mHumans[z]->setMorale(25);
						}
						else if(mActiveUnit->getMorale() > 50)
						{
							mHumans[z]->setMorale(20);
						}
						else if(mActiveUnit->getMorale() > 25)
						{
							mHumans[z]->setMorale(13);
						}
						else
						{
							mHumans[z]->setMorale(7);
						}
					}//if correct unit
				}//for human vector
			}//unitclick
		}//for tilevector
	}//heal funktion
	else if(mActiveUnit != 0 && mDamageAbility == true)
	{
		for(TileVector::size_type w = 0; w < mActiveUnit->getCurrentTile().getVector().size(); w++)
		{
			if(mActiveUnit->getCurrentTile().getVector()[w]->getHex().getGlobalBounds().contains(mPosX,mPosY) && mActiveUnit->getCurrentTile().getVector()[w]->getActive()==true)
			{
				for(ZombieVector::size_type z = 0; z < mZombies.size(); z++)
				{
					if(mActiveUnit->getCurrentTile().getVector()[w]->getPos() == mZombies[z]->getCurrentTile().getPos())
					{
						std::cout<<"dmg"<<std::endl;
						if(mZombies[z]->getMorale() > 50)
						{
							mZombies[z]->setMorale(-10);
						}
						else
						{
							mZombies[z]->setMorale(-5);
						}
					}//if correct unit
				}//for zombie vector
			}//unitclick
		}//for tilevector
	}
	else if(mActiveUnit != 0 && mCatchAbility == true)
	{
		for(TileVector::size_type w = 0; w < mActiveUnit->getCurrentTile().getVector().size(); w++)
		{
			if(mActiveUnit->getCurrentTile().getVector()[w]->getHex().getGlobalBounds().contains(mPosX,mPosY) && mActiveUnit->getCurrentTile().getVector()[w]->getActive()==true)
			{
				for(ZombieVector::size_type z = 0; z < mZombies.size(); z++)
				{
					if(mActiveUnit->getCurrentTile().getVector()[w]->getPos() == mZombies[z]->getCurrentTile().getPos())
					{
						int catchChance = rand() % 100+1;
						if(catchChance > mZombies[z]->getMorale()-1)
						{
							mHumans.push_back(mZombies[z]);
							mZombies[z] = mZombies.back();
							mZombies.pop_back();
						}
						else
						{
							mZombies[z]->setMorale(-33);
						}
					}//if correct unit
				}//for zombie vector
			}//unitclick
		}
	}
	if(mHealAbility != true)
	{
		for(HumanVector::size_type h = 0; h < mHumans.size(); h++)
		{
			if(mHumans[h]->getBoundingBox().getGlobalBounds().contains(mPosX,mPosY))
			{
				if(mHumans[h] == mActiveUnit && mActiveUnit->getShowAbilityHud() == false)
				{
					std::cout << "samma" << std::endl;
					mActiveUnit = mHumans[h];
					mActiveTile = &mActiveUnit->getCurrentTile();
				}
				if(mActiveUnit != 0 && mActiveUnit->getShowAbilityHud() == true)
				{
					// HUD  IS OPEN
				}
				else if(mHumans[h] != mActiveUnit)
				{
					if(mActiveUnit != 0)
					{
						mActiveTile->setDeactive();
						mActiveUnit->setDeactive();
						mActiveUnit->hideAbilityHud();
					}
					mActiveUnit = mHumans[h];
					mActiveTile = &mActiveUnit->getCurrentTile();		
					mActiveTile->setActive();
					mActiveUnit->setActive();

					std::cout << "Bytt / New" << std::endl;
				}
			}

		} // HUMAN END
	}
			

}

void Level_One::run(sf::RenderWindow& window)
{
	window.draw(ImageManager::getInstance()->getGridSprite());

	for(TileVector::size_type i = 0; i < mTiles.size(); i++)
	{
		mTiles[i]->update(window);
	}

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++)
	{
		mHumans[i]->update(window);
	}
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++)
	{
		mZombies[i]->update(window);
	}
}

Level_One::TileVector& Level_One::getTileVector()
{
	return mTiles;
}

void Level_One::addNeighbors()
{
	Level_One_Tiles::insertTiles(getTileVector());
}