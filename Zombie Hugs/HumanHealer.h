#ifndef INCLUDED_HUMANHEALER
#define INCLUDED_HUMANHEALER

#include "GameObject.h"
#include "Tile.h"
#include <string>
#include "SFML\System.hpp"

class HumanHealer : public GameObject
{
public:
	HumanHealer(Tile& tile);
	virtual ~HumanHealer();
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