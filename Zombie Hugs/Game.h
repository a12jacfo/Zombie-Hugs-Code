#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Game
{
public:
	Game();
	~Game();
	void update(sf::RenderWindow &window);
private:
	float gameScore;
};

