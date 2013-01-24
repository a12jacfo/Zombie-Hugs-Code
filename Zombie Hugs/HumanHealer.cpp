#include "HumanHealer.h"
#include <string>
#include "SFML\System\Vector2.hpp"

using namespace std;

HumanHealer::HumanHealer(Tile& tile):
mName("Lyn"),mMorale(100),mCurrentTile(tile), mTyp(HUMAN)
{
	mPos= mCurrentTile.getPos();
}
HumanHealer::~HumanHealer()
{
}
int HumanHealer::getMorale()
{
	return mMorale;
}
void HumanHealer::setMorale(int i)
{
	mMorale= mMorale+i;
	if(mMorale>100)
	{
		mMorale=100;
	}
}
string HumanHealer::getName()
{
	return mName;
}
sf::Vector2f HumanHealer::getPos()
{
	return mPos;
}
HumanHealer::Typ HumanHealer::getTyp()
{
	return mTyp;
}
void HumanHealer::setTyp()
{
	if(mTyp == HUMAN)
	{
		mTyp = ZOMBIECAPTIVE;
	}
	else
	{
		mTyp = HUMAN;
	}
}
void HumanHealer::setPos(sf::Vector2f pos)
{

}
bool HumanHealer::getActive()
{
	return active;
}
void HumanHealer::setActive()
{
	active = true;
}
void HumanHealer::setDeactive()
{
	active = false;
}
void HumanHealer::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Blue);
	cirkel.setPosition(mPos);
	cirkel.setRadius(30);
	cirkel.setOrigin(30,30);
	window.draw(cirkel);
}
void HumanHealer::useAbility(GameObject *g)
{
	if(mTyp == HUMAN)
	{
		if(g->getTyp() == HUMAN||g->getTyp() == HUMANCAPTIVE)
		{
			g->setMorale(25);
		}
		if(g->getTyp() == ZOMBIE)
		{
			g->setMorale(-10);
		}
	}
}