#include "ImageManager.h"
#include <iostream>

ImageManager::ImageManager()
{
	mL01GridTexture.loadFromFile("resources/lvl01_grid_grass_1.png"); 
	mL01GridSprite.setTexture(mL01GridTexture);

	mZombieHealerTexture.loadFromFile("resources/ZombieHealer.png"); 
	mZombieHealerSprite.setTexture(mZombieHealerTexture);

}


ImageManager::~ImageManager()
{
}

ImageManager& ImageManager::getInstance()
{
	static ImageManager imagemanager;
	return imagemanager;
}

const sf::Sprite& ImageManager::getGridSprite() const 
{
	return mL01GridSprite;
}

const sf::Sprite& ImageManager::getZombieHealerSprite() const 
{
	return mZombieHealerSprite;
}

