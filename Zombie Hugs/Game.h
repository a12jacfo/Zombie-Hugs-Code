#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class GameState;

class Game
{
public:
	Game();
	~Game();
	GameState* addGameState();
	void rightMouseClick(sf::RenderWindow& window);
	void leftMouseClick(sf::RenderWindow& window);
	void run(sf::RenderWindow &window);
	
private:
	GameState* mCurrentGameScreen;
	float gameScore;
	bool mFirstRun;
};

