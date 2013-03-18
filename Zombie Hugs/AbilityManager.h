#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "GUIElement.h"
#include "GameObject.h"
#include "Stunn.h"

class AbilityManager
{
public:
	typedef std::vector<Tile*> TileVector;
	typedef std::vector<GameObject*> HumanVector;
	typedef std::vector<GameObject*> ZombieVector;
	typedef std::vector<Stunn*> StunnVector;
	AbilityManager();
	~AbilityManager();
	static void setAllAbilityToFalse();
	static void callAbility(GameObject* activeUnit, GUIElement::GUIname ame, HumanVector &humans, ZombieVector &zombies, StunnVector &stunns, float x, float y, bool &humanTurn);
	static void Activate_Move_Ability(GameObject* activeUnit);
	static void Activate_Heal_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, bool &humanTurn);
	static void Activate_Damage_Abilty(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, bool &humanTurn);
	static void Activate_Catch_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, bool &humanTurn);
	static void Activate_Stunn_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, bool &humanTurn);
	static void Use_Move_Ability(GameObject* activeUnit, StunnVector &stunns, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points);
	static void Use_Heal_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points);
	static void Use_Damage_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points);
	static void Use_Catch_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points);
	static void Use_Stunn_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, StunnVector &stunns, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points);
	static bool getActiveMoveAbility();
	static bool getActiveStunnAbility();
	static bool getActiveCatchAbility();
	static bool getActiveHealAbility();
	static bool getActiveDmgAbility();
	static bool isAnyAbilityActive();
	static sf::Vector2f getTargetPos();
	static sf::Vector2f getCasterPos();
private:

	sf::Vector2f mTargetPos;
	sf::Vector2f mCasterPos;


	bool mAbilityActive;
	bool mMoveAbilityActive;
	bool mHealAbilityActive;
	bool mStunnAbilityActive;
	bool mDamageAbilityActive;
	bool mCatchAbilityActive;

	int m_Move_Cost;
	int m_Heal_Cost;
	int m_Catch_Cost;
	int m_Stunn_Cost_Unit;
	int m_Damage_Const;
	int m_Call_In_Hero_Cost;
	int m_Stunn_Duration_Ground;
	int m_Stunn_SuccessRate_Unit;
	int m_Damage_Amount;
	int m_Heal_Amount;
	int m_Catch_Fail_Drain;
	int m_Moral_After_Convertion;
	int m_Heal_In_Base_Per_Turn;
};

