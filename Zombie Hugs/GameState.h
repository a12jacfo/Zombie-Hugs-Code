#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class GameState
{
public:
	GameState();
	virtual ~GameState();
	virtual void run(sf::RenderWindow& window) = 0;
	virtual void update() = 0;
};

