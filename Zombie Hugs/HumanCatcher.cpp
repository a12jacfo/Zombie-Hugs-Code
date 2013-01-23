#include "HumanCatcher.h"
#include <string>
#include "SFML\System\Vector2.hpp"

using namespace std;

HumanCatcher::HumanCatcher(Tile& tile):
mName("Leo"), mMorale(100), mCurrentTile(tile)
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
string HumanCatcher::getName()
{
	return mName;
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
void HumanCatcher::useAbility()
{
}