#include "Level_One.h"
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
	mHumans.push_back(humanHero2);
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
	int x = 0;
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
	
		Tile *tile = new Tile(pos, x);
		mTiles.push_back(tile);
		pos.x = pos.x + 72;
		x++;
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
		}
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
		std::cout << mHumans[0]->getCurrentTile().getNR() << std::endl;
	}

	for(HumanVector::size_type i = 0; i < mZombies.size(); i++)
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
	#include "Level_One_Tiles.txt"
}