#include "ImageManager.h"
#include <iostream>

ImageManager * ImageManager::i_instance = 0;

ImageManager::ImageManager()
{
	mL01GridTexture.loadFromFile("resources/lvl01_grid_grass_1.png"); 
	mL01GridSprite.setTexture(mL01GridTexture);

	mZombieHealerTexture.loadFromFile("resources/ZombieHealer.png"); 
	mZombieHealerSprite.setTexture(mZombieHealerTexture);
}


ImageManager::~ImageManager()
{
	delete i_instance;
}

ImageManager* ImageManager::getInstance()
{
    if (!i_instance)
    {
        i_instance = new ImageManager;
    }
    return i_instance;
}

const sf::Sprite& ImageManager::getGridSprite() const 
{
	return mL01GridSprite;
}

const sf::Sprite& ImageManager::getZombieHealerSprite() const 
{
	return mZombieHealerSprite;
}

