#include "ZombieCatcher.h"
#include <string>
#include "SFML\System\Vector2.hpp"

using namespace std;

ZombieCatcher::ZombieCatcher(Tile& tile):
mName("Ted"),mMorale(100), mCurrentTile(tile)
{
	mPos= mCurrentTile.getPos();
}
ZombieCatcher::~ZombieCatcher()
{
}
int ZombieCatcher::getMorale()
{
	return mMorale;
}
void ZombieCatcher::setMorale(int i)
{
	mMorale = mMorale+i;
	if(mMorale>100)
	{
		mMorale = 100;
	}
}
string ZombieCatcher::getName()
{
	return mName;
}
ZombieCatcher::Typ ZombieCatcher::getTyp()
{
	return mTyp;
}
void ZombieCatcher::setTyp()
{
	if(mTyp == ZOMBIE)
	{
		mTyp = HUMANCAPTIVE;
	}
	else
	{
		mTyp = ZOMBIE;
	}
}
sf::Vector2f ZombieCatcher::getPos()
{
	return mPos;
}
void ZombieCatcher::setPos(sf::Vector2f pos)
{

}
bool ZombieCatcher::getActive()
{
	return active;
}
void ZombieCatcher::setActive()
{
	active = true;
}
void ZombieCatcher::setDeactive()
{
	active = false;
}
void ZombieCatcher::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Black);
	cirkel.setPosition(mPos);
	cirkel.setRadius(30);
	cirkel.setOrigin(30,30);
	window.draw(cirkel);
}
void ZombieCatcher::useAbility(GameObject *g)
{
}