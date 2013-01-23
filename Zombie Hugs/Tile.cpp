#include "Tile.h"

Tile::Tile(sf::Vector2f position) :
	mPos(position),
	mActive(false)
{
}

Tile::~Tile()
{
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

void Tile::update(sf::RenderWindow& window) 
{
	mTileLineColor = sf::Color(236,236,236);

	sf::ConvexShape hex;
	hex.setPointCount(6);
	hex.setPoint(0, sf::Vector2f(0, -35));
	hex.setPoint(1, sf::Vector2f(35, -17.5));
	hex.setPoint(2, sf::Vector2f(35, 17.5));
	hex.setPoint(3, sf::Vector2f(0, 35));
	hex.setPoint(4, sf::Vector2f(-35, 17.5));
	hex.setPoint(5, sf::Vector2f(-35, -17.5));

	hex.setOutlineColor(mTileLineColor);
	hex.setOutlineThickness(2.0f);
	if(mActive == false)
		hex.setFillColor(sf::Color::Transparent);
	if(mActive == true)
		hex.setFillColor(sf::Color(133,250,121,50));

	hex.setPosition(mPos);

	window.draw(hex);
}