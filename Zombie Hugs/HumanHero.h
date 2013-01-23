#ifndef INCLUDED_HUMANHERO
#define INCLUDED_HUMANHERO

#include "GameObject.h"
#include <string>
#include "SFML\System.hpp"

class Tile;

class HumanHero : public GameObject
{
public:
	HumanHero(Tile& tile);
	virtual ~HumanHero();
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
	int mMorale;
	std::string mName;
	sf::Vector2f mPos;
	bool active;
	Tile& mCurrentTile;
};
#endif