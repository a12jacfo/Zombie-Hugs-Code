#include "ImageManager.h"
#include <iostream>

ImageManager * ImageManager::i_instance = 0;

ImageManager::ImageManager()
{
	mL01GridTexture.loadFromFile("resources/lvl01_grid.png"); 
	mL01GridSprite.setTexture(mL01GridTexture);
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


