#include "HumanHero.h"
#include "Tile.h"

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;

HumanHero::HumanHero(Tile* tile) :
	mCurrentTile(tile),
	mActive(false),
	mShowAbilityHud(false)
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
	return mActive;
}
void HumanHero::setActive()
{
	mActive = true;
	mCurrentTile->setActive();
}
void HumanHero::setDeactive()
{
	mActive = false;
	mCurrentTile->setDeactive();
	std::cout << "Spelare av" << std::endl;
}
void HumanHero::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	if(mActive == true)
		cirkel.setFillColor(sf::Color::Green);
	if(mActive == false)
		cirkel.setFillColor(sf::Color::White);	
	cirkel.setPosition(mPos);
	cirkel.setRadius(20);
	cirkel.setOrigin(20,20);
	window.draw(cirkel);

	if(mShowAbilityHud == true)
	{
		viewAbilities(window);
	}
}


Tile* HumanHero::getCurrentTile()
{
	return mCurrentTile;
}

void HumanHero::setCurrentTile(Tile& newTile)
{
	mCurrentTile = &newTile;
}

bool HumanHero::getShowAbilityHud()
{
	return mShowAbilityHud;
}

void HumanHero::showAbilityHud()
{
	mShowAbilityHud = true;
}

void HumanHero::hideAbilityHud()
{
	mShowAbilityHud = false;
}

sf::CircleShape HumanHero::getAbility01()
{
	return ability01;
}

void HumanHero::viewAbilities(sf::RenderWindow& window)
{
	ability01.setPosition(mPos.x+40,mPos.y-45);
	ability01.setFillColor(sf::Color::Red);
	ability01.setRadius(25);
	ability01.setOrigin(25,25);

	ability02.setPosition(mPos.x-50,mPos.y+20);
	ability02.setFillColor(sf::Color::Green);
	ability02.setRadius(25);
	ability02.setOrigin(25,25);

	ability03.setPosition(mPos.x,mPos.y+55);
	ability03.setFillColor(sf::Color::Magenta);
	ability03.setRadius(25);
	ability03.setOrigin(25,25);

	ability04.setPosition(mPos.x+50,mPos.y+20);
	ability04.setFillColor(sf::Color::White);
	ability04.setRadius(25);
	ability04.setOrigin(25,25);

	ability05.setPosition(mPos.x-45,mPos.y-45);
	ability05.setFillColor(sf::Color::Yellow);
	ability05.setRadius(25);
	ability05.setOrigin(25,25);

	window.draw(ability01);
	window.draw(ability02);
	window.draw(ability03);
	window.draw(ability04);
	window.draw(ability05);
}