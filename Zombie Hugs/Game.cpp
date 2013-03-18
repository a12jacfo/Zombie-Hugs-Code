#include "Game.h"
#include "Level.h"
#include "splash.h"
#include <iostream>

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
	GameState* gameState;
	gameState= new Splash();
	return gameState;
}


void Game::leftMouseClick(sf::RenderWindow& window)
{
	mCurrentGameScreen->leftMouseClick(window);
	mCurrentGameScreen = mCurrentGameScreen->switchState(mCurrentGameScreen);
}

void Game::rightMouseClick(sf::RenderWindow& window)
{
	mCurrentGameScreen->rightMouseClick(window);
	mCurrentGameScreen=mCurrentGameScreen->switchState(mCurrentGameScreen);
}


void Game::run(sf::RenderWindow &window)
{
	if(window.isOpen())
	{
		mCurrentGameScreen->run(window);
	}
	else
	{

	}
}

