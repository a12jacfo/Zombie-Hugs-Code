#include "Level_One.h"
#include "ImageManager.h"

#include "HumanHero.h"

#include "Tile.h"
#include <iostream>

Level_One::Level_One() :
	mTargetedUnit(false),
	mMove(false)
{
	addTile();
	addNeighbors();

	HumanHero* humanHero = new HumanHero(mTiles[103]);
	mHumans.push_back(humanHero);
	mTiles[103]->setOccupied(true);

	HumanHero* humanHero2 = new HumanHero(mTiles[47]);
	mHumans.push_back(humanHero2);
	mTiles[47]->setOccupied(true);

	HumanHero* humanHero3 = new HumanHero(mTiles[97]);
	mHumans.push_back(humanHero3);
	mTiles[97]->setOccupied(true);

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

void Level_One::update(sf::RenderWindow& window)
{
	int mPosX = sf::Mouse::getPosition(window).x;
	int mPosY = sf::Mouse::getPosition(window).y;

	if(mTargetedUnit == true)
	{
		for(TileVector::size_type h = 0; h < mActiveUnit->getCurrentTile()->getVector().size(); h++)
		{
			int r0 = 30;
			int r1 = 1;
			int dx = mActiveUnit->getCurrentTile()->getVector()[h]->getPos().x - mPosX;
			int dy = mActiveUnit->getCurrentTile()->getVector()[h]->getPos().y - mPosY;
			if(((dx * dx) + (dy * dy) < (r0 + r1)*(r0+r1)))
			{
				mActiveTile->setOccupied(false);
				mActiveTile->setDeactive();
				mActiveTile = mActiveUnit->getCurrentTile()->getVector()[h];
				mMove = true;
			}
		}		
	}

	if(mTargetedUnit == true && mMove == true && mActiveTile->getOccupied() == false)
	{
		std::cout << "Moving" << std::endl;
		mActiveTile->setOccupied(true);
		mActiveUnit->getCurrentTile()->setDeactive();
		mActiveUnit->setCurrentTile(*mActiveTile);
		mActiveTile = mActiveUnit->getCurrentTile();
		for(TileVector::size_type k = 0; k < mActiveTile->getVector().size(); k++)
		{
			mActiveTile->getVector()[k]->setActive();
		}		
	}


	for(HumanVector::size_type i = 0; i < mHumans.size(); i++)
	{
		mHumans[i]->getCurrentTile()->setOccupied(true);
		int r0 = 30;
		int r1 = 1;
		int dx = mHumans[i]->getPos().x - mPosX;
		int dy = mHumans[i]->getPos().y - mPosY;
		if(((dx * dx) + (dy * dy) < (r0 + r1)*(r0+r1)))
		{
			if(mHumans[i] != mActiveUnit && mHumans[i]->getActive() == false)
			{
				if(mActiveUnit != 0) 
				{
					mActiveUnit->setDeactive();
				}
				mActiveUnit = mHumans[i];
				mActiveUnit->setActive();
				std::cout << "New Target" << std::endl;
				mTargetedUnit = true;
				mActiveTile = mActiveUnit->getCurrentTile();
				mActiveTile->setOccupied(true);

				for(TileVector::size_type k = 0; k < mActiveTile->getVector().size(); k++)
				{
					mActiveTile->getVector()[k]->setActive();
				}		
			}
		}
	}

	//Finns det en aktiv enhet, move = sant

	//Om man klickar på en annan enhet aktivera den

	//Flytta den aktiva enheten till den klickade Tilen.

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
	//TILE 0
	int x = 0;
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	x++;

	//TILE 1
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 2
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 3
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 4
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 5
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 6
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 7
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 8
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 9
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 10
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 11
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 12
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 13
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 14
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	x++;

	//TILE 15
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 16
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 17
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 18
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 19
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 20
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 21
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 22
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 23
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 24
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 25
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 26
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 27
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 28	
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 29
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 30
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 31
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 32
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 33
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 34
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 35
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 36
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 37
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 38
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 39
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 40
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 41
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 42
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 43
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	x++;

	//TILE 44
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 45
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 46
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 47
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 48
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 49
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 50
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 51
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 52
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 53
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 54
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 55
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 56
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 57
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 58
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 59
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 60
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 61
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 62
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 63
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 64
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 65
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 66
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 67
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 68
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 69
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 71
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 72
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	x++;

	//TILE 73
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 74
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 75
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 76
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 77
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 78
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 79
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 80
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 81
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 82
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 83
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 84
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 85
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 86
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 87
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 88
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 89
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 90
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 91
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 92
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 93
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 94
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 95
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 96
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 97
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 98
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 99
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 100
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 101
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	x++;

	//TILE 102
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 103
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 104
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 105
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 106
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 107
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 108
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 109
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 110
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 111
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 112
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 113
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 114
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 115
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 116
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 117
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 118
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 119
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 120
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 121
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 122
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 123
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 124
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 125
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 126
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 127
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 128
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 129
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

}