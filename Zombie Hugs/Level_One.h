#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "GameState.h"

class Tile;
class GameObject;

class Level_One : public GameState
{
public:
	typedef std::vector<Tile*> TileVector;
	typedef std::vector<GameObject*> HumanVector;
	typedef std::vector<GameObject*> ZombieVector;
	Level_One();
	~Level_One();
	void run(sf::RenderWindow& window);
	void update();
	TileVector& getTileVector();
private:	
	void addTile();
	TileVector mTiles;
	HumanVector mHumans;
	ZombieVector mZombies;
};

