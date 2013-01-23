#include "ImageManager.h"
#include "Enviroment.h"

#include "HumanHero.h";
#include "HumanCatcher.h";
#include "HumanHealer.h";
#include "HumanStunner.h";

#include "ZombieHero.h";
#include "ZombieCatcher.h";
#include "ZombieHealer.h";
#include "ZombieStunner.h";

#include "Tile.h"

ImageManager& i_instance = ImageManager::getInstance();

Enviroment * Enviroment::e_instance = 0;

Enviroment::Enviroment()
{
	addTile();
	HumanHero* humanHero = new HumanHero(*mTiles[115]);
	HumanStunner* humanStunner = new HumanStunner(*mTiles[129]);
	HumanCatcher* humanCatcher = new HumanCatcher(*mTiles[128]);
	HumanHealer* humanHealer = new HumanHealer(*mTiles[114]);
	mHumans.push_back(humanHero);
	mHumans.push_back(humanStunner);
	mHumans.push_back(humanCatcher);
	mHumans.push_back(humanHealer);

	ZombieHero* zombieHero = new ZombieHero(*mTiles[0]);
	ZombieStunner* zombieStunner = new ZombieStunner(*mTiles[1]);
	ZombieCatcher* zombieCatcher = new ZombieCatcher(*mTiles[15]);
	ZombieHealer* zombieHealer = new ZombieHealer(*mTiles[14]);
	mZombies.push_back(zombieHero);
	mZombies.push_back(zombieStunner);
	mZombies.push_back(zombieCatcher);
	mZombies.push_back(zombieHealer);
}

Enviroment::~Enviroment()
{
	delete e_instance;
}

Enviroment* Enviroment::getInstance()
{
    if (!e_instance)
    {
        e_instance = new Enviroment;
    }
    return e_instance;
}

void Enviroment::addTile()
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

Enviroment::TileVector& Enviroment::getTileVector()
{
	return mTiles;
}

void Enviroment::update(sf::RenderWindow& window)
{	
	//Draw background Lvl 1
	window.draw(i_instance.getGridSprite());

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

void Enviroment::setLvl01()
{
	//TILE 0
	mTiles[0]->getVector().push_back(mTiles[1]);
	mTiles[0]->getVector().push_back(mTiles[15]);
	mTiles[0]->getVector().push_back(mTiles[14]);
	//TILE 1
	mTiles[1]->getVector().push_back(mTiles[2]);
	mTiles[1]->getVector().push_back(mTiles[16]);
	mTiles[1]->getVector().push_back(mTiles[15]);
	mTiles[1]->getVector().push_back(mTiles[0]);
	//TILE 2
	mTiles[2]->getVector().push_back(mTiles[17]);
	mTiles[2]->getVector().push_back(mTiles[16]);
	mTiles[2]->getVector().push_back(mTiles[1]);
	//TILE 3
	mTiles[3]->getVector().push_back(mTiles[4]);
	mTiles[3]->getVector().push_back(mTiles[18]);
	mTiles[3]->getVector().push_back(mTiles[7]);
	//TILE 4
	mTiles[4]->getVector().push_back(mTiles[5]);
	mTiles[4]->getVector().push_back(mTiles[19]);
	mTiles[4]->getVector().push_back(mTiles[18]);
	mTiles[4]->getVector().push_back(mTiles[3]);
	//TILE 5
	mTiles[5]->getVector().push_back(mTiles[6]);
	mTiles[5]->getVector().push_back(mTiles[4]);
	//TILE 6
	mTiles[6]->getVector().push_back(mTiles[7]);
	mTiles[6]->getVector().push_back(mTiles[21]);
	mTiles[6]->getVector().push_back(mTiles[20]);
	mTiles[6]->getVector().push_back(mTiles[5]);
	//TILE 7
	mTiles[7]->getVector().push_back(mTiles[8]);
	mTiles[7]->getVector().push_back(mTiles[22]);
	mTiles[7]->getVector().push_back(mTiles[21]);
	mTiles[7]->getVector().push_back(mTiles[6]);
	//TILE 8
	mTiles[8]->getVector().push_back(mTiles[9]);
	mTiles[8]->getVector().push_back(mTiles[23]);
	mTiles[8]->getVector().push_back(mTiles[22]);
	mTiles[8]->getVector().push_back(mTiles[7]);
	//TILE 9
	mTiles[9]->getVector().push_back(mTiles[10]);
	mTiles[9]->getVector().push_back(mTiles[24]);
	mTiles[9]->getVector().push_back(mTiles[23]);
	mTiles[9]->getVector().push_back(mTiles[8]);
	//TILE 10
	mTiles[10]->getVector().push_back(mTiles[11]);
	mTiles[10]->getVector().push_back(mTiles[25]);
	mTiles[10]->getVector().push_back(mTiles[24]);
	mTiles[10]->getVector().push_back(mTiles[9]);
	//TILE 11
	mTiles[11]->getVector().push_back(mTiles[12]);
	mTiles[11]->getVector().push_back(mTiles[25]);
	mTiles[11]->getVector().push_back(mTiles[10]);
	//TILE 12
	mTiles[12]->getVector().push_back(mTiles[13]);
	mTiles[12]->getVector().push_back(mTiles[27]);
	mTiles[12]->getVector().push_back(mTiles[11]);
	//TILE 13
	mTiles[10]->getVector().push_back(mTiles[28]);
	mTiles[10]->getVector().push_back(mTiles[27]);
	mTiles[10]->getVector().push_back(mTiles[12]);
}
