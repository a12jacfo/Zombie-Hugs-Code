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
	void update(sf::RenderWindow& window);
	void run(sf::RenderWindow &window);
private:
	GameState* mCurrentGameScreen;
	float gameScore;
};

