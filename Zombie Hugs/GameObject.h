#ifndef INCLUDED_GAMEOBJECT
#define INCLUDED_GAMEOBJECT

#include <string>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class GameObject
{
public:
	enum Typ{ZOMBIE, HUMAN, HUMANCAPTIVE, ZOMBIECAPTIVE};
	virtual ~GameObject(){};
	virtual int getMorale() = 0;
	virtual void setMorale(int i) = 0;
	virtual std::string getName() = 0;
	virtual Typ getTyp() = 0;
	virtual void setTyp() = 0;
	virtual sf::Vector2f getPos()=0;
	virtual void setPos(sf::Vector2f pos) = 0;
	virtual bool getActive() = 0;
	virtual void setActive() = 0;
	virtual void setDeactive() = 0;
	virtual void update(sf::RenderWindow &window) = 0;
	virtual void useAbility(GameObject *g) = 0;
};
#endif