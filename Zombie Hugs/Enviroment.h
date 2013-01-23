#pragma once
#include <vector>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Tile;
class GameObject;

class Enviroment
{
public:
	typedef std::vector<Tile*> TileVector;
	typedef std::vector<GameObject*> HumanVector;
	typedef std::vector<GameObject*> ZombieVector;

	virtual ~Enviroment();
	static Enviroment* getInstance();
	void update(sf::RenderWindow& window);
	TileVector& getTileVector();
	void setLvl01();

private:
	static Enviroment* e_instance;	
	void addTile();
	Enviroment();
	Enviroment(const Enviroment &em);
	Enviroment& operator=(const Enviroment &em);

	TileVector mTiles;
	HumanVector mHumans;
	ZombieVector mZombies;

	int xPos;
	int yPos;
};

