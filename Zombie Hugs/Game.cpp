#include "Game.h"
#include "Enviroment.h"

#include <iostream>

Enviroment* e_instance = Enviroment::getInstance();

Game::Game() :
	gameScore(0.0)
{
	e_instance->setLvl01();
}

Game::~Game()
{
}

void Game::update(sf::RenderWindow &window)
{
	e_instance->update(window);
}
