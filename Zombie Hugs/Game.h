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
	void update();
	void run(sf::RenderWindow &window);
private:
	GameState* mCurrentGameScreen;
	float gameScore;
};

