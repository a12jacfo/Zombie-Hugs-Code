#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <fstream>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Audio/Music.hpp>

#include "GameState.h"
#include "Stunn.h"
#include "SideHUD.h"

#include "Level_One_Tiles.h"
#include "ConfigFile.h"

#include "ImageManager.h"
#include "AbilityManager.h"
#include "AudioManager.h"
#include "HudManager.h"
#include "InputManager.h"

#include "HumanHero.h"
#include "HumanStunner.h"
#include "HumanHealer.h"
#include "HumanCatcher.h"

#include "ZombieHero.h"
#include "ZombieStunner.h"
#include "ZombieHealer.h"
#include "ZombieCatcher.h"

#include "Tile.h"

class GameState
{
public:
	typedef std::vector<GUIElement*> AbilityVector;
	typedef std::vector<Tile*> TileVector;
	typedef std::vector<GameObject*> HumanVector;
	typedef std::vector<GameObject*> ZombieVector;
	typedef std::vector<Stunn*> StunnVector;

	GameState();
	virtual ~GameState();
	virtual GameState* switchState(GameState* state) = 0;
	virtual void run(sf::RenderWindow& window) = 0;
	virtual void leftMouseClick(sf::RenderWindow& window) = 0;
	virtual void rightMouseClick(sf::RenderWindow& window) = 0;

	TileVector& getTileVector();
	HumanVector& getHumanVector();
	ZombieVector& getZombieVector();
	StunnVector& getStunnVector();
	int& get_Human_Action_Points();
	int& get_Zombie_Action_Points();
	int& getHumanIngameScore();
	int& getZombieIngameScore();
	bool& getHumanTurn();

protected:

	bool m_Human_Turn;
	bool m_Unit_is_Walking;

	TileVector mTiles;
	HumanVector mHumans;
	ZombieVector mZombies;
	StunnVector mStunns;

	int m_Human_Action_Points;
	int m_Zombie_Action_Points;
	int m_Human_InGame_Score;
	int m_Zombie_InGame_Score;
};

