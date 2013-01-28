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

void Game::leftMouseClick(sf::RenderWindow& window)
{
	mCurrentGameScreen->leftMouseClick(window);
}

void Game::rightMouseClick(sf::RenderWindow& window)
{
	mCurrentGameScreen->rightMouseClick(window);
}


void Game::run(sf::RenderWindow &window)
{
	mCurrentGameScreen->run(window);
}
