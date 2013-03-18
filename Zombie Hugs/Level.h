#pragma once
#include "GameState.h"
#include "Level_One_Tiles.h"
#include "Level_Two_Tiles.h"

class Level : public GameState
{
public:
	Level(int levelnum);
	~Level();
	virtual void run(sf::RenderWindow& window);
	virtual void leftMouseClick(sf::RenderWindow& window);
	virtual void rightMouseClick(sf::RenderWindow& window);
	virtual GameState* switchState(GameState* state);

private:
	int level_id;

	void addTile();
	void addNeighbors();

	sf::Sprite background;
	sf::Music m_Music;
	
	GameObject* mActiveUnit;
	SideHUD* leftSide;
	SideHUD* rightSide;
};

