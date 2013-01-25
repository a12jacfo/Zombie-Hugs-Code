#include "HumanHero.h"
#include "Tile.h"

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;

HumanHero::HumanHero(Tile* tile) :
	mCurrentTile(tile),
	active(false)
{
	mPos = mCurrentTile->getPos();

}
HumanHero::~HumanHero()
{
}

sf::Vector2f HumanHero::getPos()
{
	mPos = mCurrentTile->getPos();
	return mPos;
}
void HumanHero::setPos(sf::Vector2f pos)
{
	mPos = pos;
}
bool HumanHero::getActive()
{
	return active;
}
void HumanHero::setActive()
{
	active = true;
	mCurrentTile->setActive();
}
void HumanHero::setDeactive()
{
	active = false;
	mCurrentTile->setDeactive();
	std::cout << "Spelare av" << std::endl;
}
void HumanHero::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Green);
	cirkel.setPosition(mPos);
	cirkel.setRadius(20);
	cirkel.setOrigin(20,20);
	window.draw(cirkel);
}


Tile* HumanHero::getCurrentTile()
{
	return mCurrentTile;
}

void HumanHero::setCurrentTile(Tile& newTile)
{
	mCurrentTile = &newTile;
}