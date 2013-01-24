#include "HumanHero.h"
#include "Tile.h"

#include <string>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"

using namespace std;

HumanHero::HumanHero(Tile& tile) :
	mName("Lou"),
	mMorale(100),
	mCurrentTile(tile)
{
	mPos = mCurrentTile.getPos();
	mCurrentTile.setActive();
}
HumanHero::~HumanHero()
{
}
int HumanHero::getMorale()
{
	return mMorale;
}
void HumanHero::setMorale(int i)
{
	mMorale = mMorale+i;
	if(mMorale>100)
	{
		mMorale = 100;
	}
}
string HumanHero::getName()
{
	return mName;
}
HumanHero::Typ HumanHero::getTyp()
{
	return mTyp;
}
void HumanHero::setTyp()
{
}
sf::Vector2f HumanHero::getPos()
{
	mPos = mCurrentTile.getPos();
	return mPos;
}
void HumanHero::setPos(sf::Vector2f pos)
{
}
bool HumanHero::getActive()
{
	return active;
}
void HumanHero::setActive()
{
	active = true;
}
void HumanHero::setDeactive()
{
	active = false;
}
void HumanHero::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Green);
	cirkel.setPosition(mPos);
	cirkel.setRadius(30);
	cirkel.setOrigin(30,30);
	window.draw(cirkel);
}
void HumanHero::useAbility(GameObject *g)
{
}