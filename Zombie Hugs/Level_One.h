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
	virtual void run(sf::RenderWindow& window);
	virtual void leftMouseClick(sf::RenderWindow& window);
	virtual void rightMouseClick(sf::RenderWindow& window);
	TileVector& getTileVector();
private:	
	void addTile();
	void addNeighbors();

	TileVector mTiles;
	HumanVector mHumans;
	ZombieVector mZombies;
	
	GameObject* mActiveUnit;
	Tile* mActiveTile;

	bool mTargetedUnit;
	bool mMoveAbility;
};

