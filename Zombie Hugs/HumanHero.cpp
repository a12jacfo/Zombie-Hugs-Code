#include "HumanHero.h"
#include "Tile.h"

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;

HumanHero::HumanHero(Tile& tile, std::string name) :
	mCurrentTile(&tile),
	mActive(false),
	mShowAbilityHud(false),
	mMorale(50)
{
	mName = name;
	mPos = mCurrentTile->getPos();
}

HumanHero::~HumanHero()
{
}

HumanHero::Category HumanHero::getCategory()
{
	return HUMAN;
}

void HumanHero::setCategory()
{
}

std::string HumanHero::getName()
{
	return mName;
}

Tile& HumanHero::getCurrentTile() const
{
	return *mCurrentTile;
}
void HumanHero::SetCurrentTile(Tile& newTile)
{
	mCurrentTile = &newTile;
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
}
void HumanHero::setDeactive()
{
	mActive = false;
	std::cout << "Spelare av" << std::endl;
}
int HumanHero::getMorale()
{
	return mMorale;
}
void HumanHero::setMorale(int i)
{
	mMorale = mMorale+=i;
	if(mMorale>100)
	{
		mMorale=100;
	}
}
sf::CircleShape HumanHero::getBoundingBox()
{
	return cirkel;
}

void HumanHero::update(sf::RenderWindow &window)
{
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

sf::CircleShape HumanHero::getAbility(std::string abilityName)
{
	if(abilityName == "move")
	{
		return mAbilityMove;
	}		
	else if(abilityName == "heal")
	{
		return mAbilityHeal;
	}
	else if(abilityName == "stunn")
	{
		return mAbilityStunn;
	}
	else if(abilityName == "catch")
	{
		return mAbilityCatch;
	}
	else if(abilityName == "damage")
	{
		return mAbilityDamage;
	}
	else
	{
		return mAbilityMove;
	}
}


void HumanHero::viewAbilities(sf::RenderWindow& window)
{
	mAbilityMove.setPosition(mPos.x+40,mPos.y-45);
	mAbilityMove.setFillColor(sf::Color::Red);
	mAbilityMove.setRadius(25);
	mAbilityMove.setOrigin(25,25);

	mAbilityHeal.setPosition(mPos.x-50,mPos.y+20);
	mAbilityHeal.setFillColor(sf::Color::Green);
	mAbilityHeal.setRadius(25);
	mAbilityHeal.setOrigin(25,25);

	mAbilityStunn.setPosition(mPos.x,mPos.y+55);
	mAbilityStunn.setFillColor(sf::Color::Magenta);
	mAbilityStunn.setRadius(25);
	mAbilityStunn.setOrigin(25,25);

	mAbilityCatch.setPosition(mPos.x+50,mPos.y+20);
	mAbilityCatch.setFillColor(sf::Color::White);
	mAbilityCatch.setRadius(25);
	mAbilityCatch.setOrigin(25,25);

	mAbilityDamage.setPosition(mPos.x-45,mPos.y-45);
	mAbilityDamage.setFillColor(sf::Color::Yellow);
	mAbilityDamage.setRadius(25);
	mAbilityDamage.setOrigin(25,25);

	window.draw(mAbilityMove);
	window.draw(mAbilityHeal);
	window.draw(mAbilityStunn);
	window.draw(mAbilityCatch);
	window.draw(mAbilityDamage);
}