#include "splash.h"
#include <iostream>
#include "ImageManager.h"
#include "MainMenu.h"

Splash::Splash()
{
//	splash.load("Resources/Movies/imagineright.wmv");
	mAnyKeyPressed = false;
	if (splash.hasError()) {
	  // Handle error
	  std::cout<<"Error: "<<splash.getError()<<"\n";
	}
}

Splash::~Splash()
{

}

void Splash::run(sf::RenderWindow & window)
{	
	splash.update(sf::seconds(1.0f / 60.0f));
}

void Splash::leftMouseClick(sf::RenderWindow & renderWindow)
{
	mAnyKeyPressed=true;
}

void Splash::rightMouseClick(sf::RenderWindow & renderWindow)
{
	mAnyKeyPressed=true;         

}
GameState* Splash::switchState(GameState* state)
{
	if(mAnyKeyPressed == true)
	{
		std::cout <<"hfrj"<<std::endl;
		delete state;
		state= new MainMenu(); 
	}
	return  state;
}

/*
bool Splash::anyKeyPressed(sf::RenderWindow & window)
{
	return true;
}*/
//delete current
//switch () mcurrent=new 

