#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#include <SFML/Audio/Music.hpp>

#include "GameState.h"
#include "Stunn.h"
#include "SideHUD.h"

class Tile;
class GameObject;
class GUIElement;


class Level_One : public GameState
{
public:
	typedef std::vector<GUIElement*> AbilityVector;
	typedef std::vector<Tile*> TileVector;
	typedef std::vector<GameObject*> HumanVector;
	typedef std::vector<GameObject*> ZombieVector;
	typedef std::vector<Stunn*> StunnVector;

	Level_One();
	~Level_One();
	virtual GameState* switchState(GameState* state);
	virtual void run(sf::RenderWindow& window);
	virtual void leftMouseClick(sf::RenderWindow& window);
	virtual void rightMouseClick(sf::RenderWindow& window);
	TileVector& getTileVector();
	HumanVector& getHumanVector();
	ZombieVector& getZombieVector();
	StunnVector& getStunnVector();
	int& get_Human_Action_Points();
	int& get_Zombie_Action_Points();
	bool& getHumanTurn();

private:	
	void addTile();
	void addNeighbors();

	sf::Sprite background;

	sf::Music m_Music;

	bool m_Human_Turn;
	bool m_Unit_is_Walking;

	TileVector mTiles;
	HumanVector mHumans;
	ZombieVector mZombies;
	StunnVector mStunns;
	
	GameObject* mActiveUnit;

	SideHUD* leftSide;
	SideHUD* rightSide;

	int m_Human_Action_Points;
	int m_Zombie_Action_Points;
	int m_Move_Cost;
	int m_Heal_Cost;
	int m_Catch_Cost;
	int m_Stunn_Cost_Unit;
	int m_Stunn_Cost_Ground;
	int m_Damage_Const;
	int m_Call_In_Hero_Cost;
	int m_Stunn_Duration_Unit;
	int m_Stunn_Duration_Ground;
	int m_Stunn_SuccessRate_Unit;
	int m_Stunns_Per_Stunner_Per_Round;
	int m_Stunners_Total_Active_Stunns;
	int m_Heals_Per_Healer_Per_Round;
	int m_Damages_Per_Healer_Per_Round;
	int m_Catches_Per_Catcher_Per_Round;
	int m_Damage_Amount;
	int m_Catch_Fail_Drain;
	int m_Moral_After_Convertion;
	int m_Heal_In_Base_Per_Turn;

};

