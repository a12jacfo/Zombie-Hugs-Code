#ifndef INCLUDED_GAMEOBJECT
#define INCLUDED_GAMEOBJECT

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Tile;

class GameObject
{
public:
	virtual ~GameObject(){};
	virtual sf::Vector2f getPos() = 0;
	virtual void setPos(sf::Vector2f pos) = 0;
	virtual bool getActive() = 0;
	virtual void setActive() = 0;
	virtual void setDeactive() = 0;
	virtual Tile* getCurrentTile() = 0;
	virtual void setCurrentTile(Tile& newTile) = 0;
	virtual void update(sf::RenderWindow &window) = 0;
};
#endif