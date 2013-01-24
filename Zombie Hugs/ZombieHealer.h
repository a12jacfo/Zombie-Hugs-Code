#ifndef INCLUDED_ZOMBIEHEALER
#define INCLUDED_ZOMBIEHEALER

#include "GameObject.h"
#include "Tile.h"
#include <string>
#include "SFML\System.hpp"

class ZombieHealer : public GameObject
{
public:
	ZombieHealer(Tile& tile);
	virtual ~ZombieHealer();
	virtual int getMorale();
	virtual void setMorale(int i);
	virtual std::string getName();
	virtual Typ getTyp();
	virtual void setTyp();
	virtual sf::Vector2f getPos();
	virtual void setPos(sf::Vector2f pos);
	virtual bool getActive();
	virtual void setActive();
	virtual void setDeactive();
	virtual void update(sf::RenderWindow &window);
	virtual void useAbility(GameObject *g);
private:
	std::string mName;
	int mMorale;
	sf::Vector2f mPos;
	bool active;
	Tile& mCurrentTile;
	Typ mTyp;
};
#endif