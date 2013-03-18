#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "sfTheora\Video.h"

 class Splash:  public GameState
{
 public:
	Splash();
	~Splash();
	virtual void run(sf::RenderWindow& window);
	virtual void leftMouseClick(sf::RenderWindow& window);
	virtual void rightMouseClick(sf::RenderWindow& window);
	virtual GameState* switchState(GameState* state);
	
private:
	bool mAnyKeyPressed;
	sftheora::Video splash;
};	