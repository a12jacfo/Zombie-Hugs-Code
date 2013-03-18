#pragma once
#include "gamestate.h"

class GameMenu :public GameState
{
public:
	GameMenu();
	~GameMenu();
	virtual void run(sf::RenderWindow& window);
	virtual void leftMouseClick(sf::RenderWindow& window);
	virtual void rightMouseClick(sf::RenderWindow& window);
};

