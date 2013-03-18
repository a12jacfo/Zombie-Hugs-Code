#pragma once
#include "GameState.h"
 
class MainMenu: public GameState
{
public:
	MainMenu();
	void run(sf::RenderWindow& window);
	void leftMouseClick(sf::RenderWindow& window);
	void rightMouseClick(sf::RenderWindow& window);
	GameState* switchState(GameState* state);
private:
	enum MenuResult{Nothing,Quit,StoryPlay,FreePlay,Option,Credits,Conquest,Tutorial};     
	struct MenuItem
	{
	public:
		MenuResult action;
		sf::Sprite menuButton;
    };
	
	MenuResult mMenuState;
	std::vector<MenuItem> mMenuItems;
	bool mExit;

	//skapar menyn
	MenuResult Show(sf::RenderWindow& window,int mouse_x,int mouse_y);
	
	//Retunerar meny händelser
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	
	// returnerar ifall muspekaren är innanför "knapprutan"
	
	MenuResult HandleClick(int x, int y);
	//lista med menyknappar
   

	sf::Sprite mMainMenuScreen;
	sf::Event mMenuEvent;
};