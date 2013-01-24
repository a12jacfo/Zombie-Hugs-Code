#include "ZombieStunner.h"
#include <string>
#include "SFML\System\Vector2.hpp"

using namespace std;

ZombieStunner::ZombieStunner(Tile& tile):
mName("Tim"),mMorale(100), mCurrentTile(tile)
{
	mPos= mCurrentTile.getPos();
}
ZombieStunner::~ZombieStunner()
{
}
int ZombieStunner::getMorale()
{
	return mMorale;
}
void ZombieStunner::setMorale(int i)
{
	mMorale = mMorale+i;
	if(mMorale>100)
	{
		mMorale = 100;
	}
}
string ZombieStunner::getName()
{
	return mName;
}
ZombieStunner::Typ ZombieStunner::getTyp()
{
	return mTyp;
}
void ZombieStunner::setTyp()
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
sf::Vector2f ZombieStunner::getPos()
{
	return mPos;
}
void ZombieStunner::setPos(sf::Vector2f pos)
{

}
bool ZombieStunner::getActive()
{
	return active;
}
void ZombieStunner::setActive()
{
	active = true;
}
void ZombieStunner::setDeactive()
{
	active = false;
}
void ZombieStunner::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Magenta);
	cirkel.setPosition(mPos);
	cirkel.setRadius(30);
	cirkel.setOrigin(30,30);
	window.draw(cirkel);
}
void ZombieStunner::useAbility(GameObject *g)
{
}