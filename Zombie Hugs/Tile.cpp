#include "Tile.h"
#include <iostream>

Tile::Tile(sf::Vector2f position, sf::Vector2f coordinate, sf::String home) :
	mPos(position),
	mCoordinate(coordinate),
	mActive(false),
	mOccupied(false)
{
	if(home == "hh")
	{
		mHumanHome = true;
		mZombieHome = false;
	}
	else if(home == "zh")
	{
		mHumanHome = false;
		mZombieHome = true;
	}
	else
	{
		mHumanHome = false;
		mZombieHome = false;
	}
}

Tile::~Tile()
{
}

bool Tile::getOccupied()
{
	return mOccupied;
}

void Tile::setOccupied(bool occupied)
{
	if(occupied == true)
	{
		mOccupied = true;
	}
	if(occupied == false)
	{
		mOccupied = false;
	}
}

bool Tile::getActive()
{
	return mActive;
}

void Tile::setActive()
{
	mActive = true;
}

void Tile::setDeactive()
{
	mActive = false;
}

bool Tile::getHomeBaseHuman()
{
	return mHumanHome;
}
bool Tile::getHomeBaseZombie()
{
	return mZombieHome;
}

void Tile::setActiveWalls()
{
	for(Walls::size_type t = 0; t < mWalls.size(); t++)
	{
		if(mWalls[t]->getOccupied() == false)
		{
				mWalls[t]->setActive();
		}
	}
}


void Tile::setDeactiveWalls()
{
	for(Walls::size_type i = 0; i < mWalls.size(); i++)
	{
		if(mWalls[i]->getActive() == true)
		{
			mWalls[i]->setDeactive();
		}
	}
}

sf::Vector2f Tile::getCoordinate()
{
	return mCoordinate;
}

sf::Vector2f Tile::getPos()
{
	return mPos;
}

sf::Color Tile::changeColor(sf::Color color)
{
	mTileColor = color;
	return mTileColor;
}

Tile::Walls& Tile::getVector()
{
	return mWalls;
}

sf::ConvexShape Tile::getHex()
{
	return hex;
}

void Tile::update(sf::RenderWindow& window) 
{
	hex.setPointCount(6);
	hex.setPoint(0, sf::Vector2f(0, -35));
	hex.setPoint(1, sf::Vector2f(35, -17.5));
	hex.setPoint(2, sf::Vector2f(35, 17.5));
	hex.setPoint(3, sf::Vector2f(0, 35));
	hex.setPoint(4, sf::Vector2f(-35, 17.5));
	hex.setPoint(5, sf::Vector2f(-35, -17.5));

	hex.setOutlineColor(sf::Color::Transparent);
	if(mActive == false)
		hex.setFillColor(sf::Color::Transparent);
	if(mActive == true)
		hex.setFillColor(sf::Color(0,0,255,130));

	hex.setPosition(mPos);

	window.draw(hex);
}