#include "ZombieHealer.h"
#include <string>
#include "SFML\System\Vector2.hpp"

using namespace std;

ZombieHealer::ZombieHealer(Tile& tile):
mName("Tom"),mMorale(100), mCurrentTile(tile)
{
	mPos= mCurrentTile.getPos();
}
ZombieHealer::~ZombieHealer()
{
}
int ZombieHealer::getMorale()
{
	return mMorale;
}
void ZombieHealer::setMorale(int i)
{
	mMorale = mMorale+i;
	if(mMorale>100)
	{
		mMorale = 100;
	}
}
string ZombieHealer::getName()
{
	return mName;
}
ZombieHealer::Typ ZombieHealer::getTyp()
{
	return mTyp;
}
void ZombieHealer::setTyp()
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
sf::Vector2f ZombieHealer::getPos()
{
	return mPos;
}
void ZombieHealer::setPos(sf::Vector2f pos)
{

}
bool ZombieHealer::getActive()
{
	return active;
}
void ZombieHealer::setActive()
{
	active = true;
}
void ZombieHealer::setDeactive()
{
	active = false;
}
void ZombieHealer::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Cyan);
	cirkel.setPosition(mPos);
	cirkel.setRadius(30);
	cirkel.setOrigin(30,30);
	window.draw(cirkel);
}
void ZombieHealer::useAbility(GameObject *g)
{
}