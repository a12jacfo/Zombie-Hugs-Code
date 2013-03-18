 #include "MainMenu.h"
#include "ImageManager.h"
#include <iostream>
#include "Level.h"

MainMenu::MainMenu()
{
	mExit=false;
	MenuItem items;
	mMainMenuScreen.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/Mainmenu.png"));


	items.menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/story.png"));
	items.menuButton.setPosition(1024/2-97,720/12-35);
	items.action=StoryPlay;
	mMenuItems.push_back(items);

	items.menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/conquest.png"));
	items.menuButton.setPosition(1024/2-105,720/12*2+40);
	items.action=Conquest;
	mMenuItems.push_back(items);

	items.menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/free.png"));
	items.menuButton.setPosition(1024/2-110,720/12*3+90);
	items.action=FreePlay;
	mMenuItems.push_back(items);

	items.menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/tutorial.png"));
	items.menuButton.setPosition(1024/2-110,720/12*4+170);
	items.action=Tutorial;
	mMenuItems.push_back(items);
	
	items.menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/exit.png"));
	items.menuButton.setPosition(1024/2-110,720/12*5+230);
	items.action=Quit;
	mMenuItems.push_back(items);
}
	void MainMenu:: run(sf::RenderWindow& window) 
	{
		window.draw(mMainMenuScreen);		
		float mouse_x=sf::Mouse::getPosition(window).x;
		float mouse_y=sf::Mouse::getPosition(window).y;
		for(int i=0; i < mMenuItems.size(); i++)
		{
			
			if(mMenuItems[i].menuButton.getGlobalBounds().contains(mouse_x,mouse_y))
			{
				
				MainMenu::MenuResult result= mMenuItems[i].action;
				switch(result)
				{

					case MainMenu::StoryPlay:
					   mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/story_hover.png"));
					   break;
				    case MainMenu::FreePlay:		
					   mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/free_hover.png"));
					   break;

					case MainMenu::Conquest:		
					   mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/conquest_hover.png"));
					   break;	


					case MainMenu::Tutorial:		
					   mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/tutorial_hover.png"));
					   break;	
					   
					case MainMenu::Quit:
					   mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/exit_hover.png"));
					   break;
				}
					window.draw(mMenuItems[i].menuButton);
			}	
			else
			{
				MainMenu::MenuResult result= mMenuItems[i].action;
				switch(result)
				{

					case MainMenu::StoryPlay:
					   mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/story.png"));
					   break;
				    case MainMenu::FreePlay:		
					    mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/free.png"));
					   break;	
					case MainMenu::Conquest:		
					   mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/conquest.png"));
					   break;
					case MainMenu::Tutorial:		
					  mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/tutorial.png"));
					  break;	
					case MainMenu::Quit:
					    mMenuItems[i].menuButton.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Menu/exit.png"));
					   break;
				}
					window.draw(mMenuItems[i].menuButton);
			}
		}

		

	}
	void MainMenu:: leftMouseClick(sf::RenderWindow& window) 
	{
		MainMenu mainMenu;
		int mouse_x=sf::Mouse::getPosition(window).x;
		int mouse_y=sf::Mouse::getPosition(window).y;
	   MainMenu::MenuResult result = mainMenu.Show(window,mouse_x,mouse_y);
	   switch(result)
	   {
			case MainMenu::Quit:
				window.close();
				   mMenuState = Quit;
				   break;
				
			case MainMenu::StoryPlay:
				   mMenuState = StoryPlay;
				   break;
	
		    case MainMenu::FreePlay:
				   mMenuState = FreePlay;
				   break;
    }
	};
	void MainMenu:: rightMouseClick(sf::RenderWindow& window) 
	{
	};

	GameState* MainMenu:: switchState(GameState* state)
	{	   
	   switch(mMenuState)
	   {
			case MainMenu::Quit:
				   break;
				
			case MainMenu::StoryPlay:
				   delete state;
				   state = new Level(1);
				   break;
	
		   case MainMenu::FreePlay:
				//Eventuell FreePlay
			      //state = new FreePlayMenu();
				   break;

	   }
		return state;
	};


 MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window,int mouse_x,int mouse_y)
 {
	for(int i=0; i < mMenuItems.size(); i++)
	{
		if(mMenuItems[i].menuButton.getGlobalBounds().contains(mouse_x,mouse_y))
		{
			return mMenuItems[i].action;
		}
	}
   return Nothing;
 }