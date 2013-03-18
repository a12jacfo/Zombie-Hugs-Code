#pragma once

#include "SFML\Graphics.hpp"
#include "GUIElement.h"
#include "GUIAbilityButton.h"
#include "GUIButtonEndTurn.h"
#include "GameObject.h"

#include <vector>


class HudManager
{
public:
	~HudManager();
	typedef std::vector<GUIElement*> AbilityVector;
	typedef std::vector<GUIElement*> GUIElementVector;
	typedef std::vector<Tile*> TileVector;

	static HudManager* getInstance();

	void update(sf::RenderWindow& window, bool& humanTurn, int& humanAP, int& zombieAP, int& humanScore, int& zombieScore);

	void ShowAbilityHud(GameObject& activeUnit);
	void HideAbilityHud();

	AbilityVector& getAbilityVector();
	GUIButtonEndTurn* mGUIButtonEndTurn;

private:

	GUIElementVector mGUIElements;
	AbilityVector mAbilitys;

	static HudManager* hm_instance;
	HudManager();
	HudManager(const HudManager &hm);
	HudManager& operator=(const HudManager &hm);
	
	sf::Sprite m_Ability_hud;
	sf::Sprite m_Score_hud;
	sf::Sprite m_Go_Turn;
	sf::Sprite m_Nogo_Turn;
	sf::Sprite m_Zombie_One_Score;
	sf::Sprite m_Zombie_Two_Score;
	sf::Sprite m_Zombie_Three_Score;
	sf::Sprite m_Human_One_Score;
	sf::Sprite m_Human_Two_Score;
	sf::Sprite m_Human_Three_Score;

	sf::Vector2f m_Human_Side_Turn_Pos;
	sf::Vector2f m_Zombie_Side_Turn_Pos;
	sf::Vector2f m_Zombie_Side_Score_Pos;
	sf::Vector2f m_Human_Side_Score_Pos;

	sf::Text mAp;

	GUIAbilityButton* mAbilityMove;
	GUIAbilityButton* mAbilityHeal;
	GUIAbilityButton* mAbilityStunn;
	GUIAbilityButton* mAbilityCatch;
	GUIAbilityButton* mAbilityDamage;

};

