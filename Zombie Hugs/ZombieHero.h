#ifndef INCLUDED_ZOMBIEHERO
#define INCLUDED_ZOMBIEHERO

#include "GameObject.h"
#include "Tile.h"
#include <string>
#include "SFML\System.hpp"

class ZombieHero : public GameObject
{
public:
	ZombieHero(Tile& tile);
	virtual ~ZombieHero();
	virtual int getMorale();
	virtual std::string getName();
	virtual sf::Vector2f getPos();
	virtual void setPos(sf::Vector2f pos);
	virtual bool getActive();
	virtual void setActive();
	virtual void setDeactive();
	virtual void update(sf::RenderWindow &window);
	virtual void useAbility();
private:
	std::string mName;
	int mMorale;
	sf::Vector2f mPos;
	bool active;
	Tile& mCurrentTile;
};
#endif