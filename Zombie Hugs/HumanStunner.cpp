#include "HumanStunner.h"
#include <string>
#include "SFML\System\Vector2.hpp"

using namespace std;

HumanStunner::HumanStunner(Tile& tile):
mName("Liz"),mMorale(100), mCurrentTile(tile)
{
	mPos= mCurrentTile.getPos();
}
HumanStunner::~HumanStunner()
{
}
int HumanStunner::getMorale()
{
	return mMorale;
}
string HumanStunner::getName()
{
	return mName;
}
sf::Vector2f HumanStunner::getPos()
{
	return mPos;
}
void HumanStunner::setPos(sf::Vector2f pos)
{

}
bool HumanStunner::getActive()
{
	return active;
}
void HumanStunner::setActive()
{
	active = true;
}
void HumanStunner::setDeactive()
{
	active = false;
}
void HumanStunner::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Black);
	cirkel.setPosition(mPos);
	cirkel.setRadius(30);
	cirkel.setOrigin(30,30);
	window.draw(cirkel);
}
void HumanStunner::useAbility()
{
}