#include "ZombieHero.h"
#include <string>
#include "SFML\System\Vector2.hpp"

using namespace std;

ZombieHero::ZombieHero(Tile& tile):
mName("Tam"),mMorale(100), mCurrentTile(tile)
{
	mPos= mCurrentTile.getPos();
}
ZombieHero::~ZombieHero()
{
}
int ZombieHero::getMorale()
{
	return mMorale;
}
string ZombieHero::getName()
{
	return mName;
}
sf::Vector2f ZombieHero::getPos()
{
	return mPos;
}
void ZombieHero::setPos(sf::Vector2f pos)
{

}
bool ZombieHero::getActive()
{
	return active;
}
void ZombieHero::setActive()
{
	active = true;
}
void ZombieHero::setDeactive()
{
	active = false;
}
void ZombieHero::update(sf::RenderWindow &window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Yellow);
	cirkel.setPosition(mPos);
	cirkel.setRadius(30);
	cirkel.setOrigin(30,30);
	window.draw(cirkel);
}
void ZombieHero::useAbility()
{
}