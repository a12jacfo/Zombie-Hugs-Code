#ifndef INCLUDED_ZOMBIECATCHER
#define INCLUDED_ZOMBIECATCHER

#include "GameObject.h"
#include "Tile.h"
#include <string>
#include "SFML\System.hpp"

class ZombieCatcher : public GameObject
{
public:
	ZombieCatcher(Tile& tile);
	virtual ~ZombieCatcher();
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