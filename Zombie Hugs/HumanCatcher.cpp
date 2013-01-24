#include "HumanCatcher.h"
#include <string>
#include "SFML\System\Vector2.hpp"

using namespace std;

HumanCatcher::HumanCatcher(Tile& tile):
mName("Leo"), mMorale(100), mCurrentTile(tile), mTyp(HUMAN)
{
	mPos= mCurrentTile.getPos();
}
HumanCatcher::~HumanCatcher()
{
}
int HumanCatcher::getMorale()
{
	return mMorale;
}
void HumanCatcher::setMorale(int i)
{
	mMorale= mMorale+i;
	if(mMorale>100)
	{
		mMorale=100;
	}
}
string HumanCatcher::getName()
{
	return mName;
}
HumanCatcher::Typ HumanCatcher::getTyp()
{
	return mTyp;
}
void HumanCatcher::setTyp()
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
sf::Vector2f HumanCatcher::getPos()
{
	return mPos;
}
void HumanCatcher::setPos(sf::Vector2f pos)
{

}
bool HumanCatcher::getActive()
{
	return active;
}
void HumanCatcher::setActive()
{
	active = true;
}
void HumanCatcher::setDeactive()
{
	active = false;
}
void HumanCatcher::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::White);
	cirkel.setPosition(mPos);
	cirkel.setRadius(30);
	cirkel.setOrigin(30,30);
	window.draw(cirkel);
}
void HumanCatcher::useAbility(GameObject *g)
{
	if(mTyp == HUMAN)
	{
		if(g->getTyp() == ZOMBIE)
		{
			int catchChance = rand() % 100+1;
			if(catchChance > g->getMorale()-1)
			{
				g->setTyp();
			}
		}
	}
}