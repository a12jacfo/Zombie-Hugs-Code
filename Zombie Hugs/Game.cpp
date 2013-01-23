#include "Game.h"
#include "Level_One.h"

Game::Game() :
	gameScore(0.0)
{	 
	mCurrentGameScreen = addGameState();
}

Game::~Game()
{
	delete mCurrentGameScreen;
}

GameState* Game::addGameState()
{
	GameState* gamestate = new Level_One();
	return gamestate;
}

void Game::run(sf::RenderWindow &window)
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mCurrentGameScreen->update();
	}
	mCurrentGameScreen->run(window);
}
