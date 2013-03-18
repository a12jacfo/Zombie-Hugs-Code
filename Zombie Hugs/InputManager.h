#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "HudManager.h"
#include <vector>

class GameObject;

class InputManager
{
public:
	typedef std::vector<GUIElement*> AbilityVector;
	typedef std::vector<GameObject*> HumanVector;
	typedef std::vector<GameObject*> ZombieVector;
	typedef std::vector<Stunn*> StunnVector;
	InputManager();
	~InputManager();
	static void update(GameObject* activeUnit,float x, float y, HumanVector &humans, ZombieVector &zombies, StunnVector &stunns, bool &human_Turn,int &Human_Action_Points,int &Zombie_Action_Points);
private:
	int m_Heal_In_Base_Per_Turn;
};

