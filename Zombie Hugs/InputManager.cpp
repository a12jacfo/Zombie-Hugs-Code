#include "InputManager.h"
#include "GameObject.h"
#include "ConfigFile.h"
#include "HudManager.h"


#include <iostream>

InputManager iobj;

InputManager::InputManager()
{
	m_Heal_In_Base_Per_Turn = ConfigFile::getInstance()->getValueOfKey<int>("m_Heal_In_Base_Per_Turn");
}

InputManager::~InputManager()
{
}

void InputManager::update(GameObject* activeUnit, float x, float y, HumanVector &humans, ZombieVector &zombies, StunnVector &stunns, bool &human_Turn,int &Human_Action_Points,int &Zombie_Action_Points)
{
	if(HudManager::getInstance()->mGUIButtonEndTurn->getSprite().getGlobalBounds().contains(x,y))
	{
		if(human_Turn == true)
		{
			AbilityManager::setAllAbilityToFalse();
			HudManager::getInstance()->HideAbilityHud();

			if(activeUnit != 0)
			{
				activeUnit->setDeactive();
				activeUnit->getCurrentTile().setDeactive();
				activeUnit->getCurrentTile().setDeactiveWalls();
			}
			activeUnit = 0;

			human_Turn = false;
			std::cout << "END TURN HUMAN" << std::endl;

			for(HumanVector::size_type i = 0; i < humans.size();i++)
			{
				humans[i]->ToggelStunned(false);
				humans[i]->setAbilityUsed(false);
				humans[i]->resetAbilityMoveUsed();
				if(humans[i]->getCurrentTile().getHomeBaseHuman() == true)
				{
					humans[i]->setMorale(iobj.m_Heal_In_Base_Per_Turn);
				}	
			}
			Human_Action_Points = 12;
			for(int q = stunns.size()-1; q >= 0; q--)
			{
				if(stunns[q]->getCatgory() == Stunn::ZOMBIE)
				{
					if(stunns[q]->getDuration() <= 1)
					{
						delete stunns[q];
						stunns[q]=stunns.back();
						stunns.pop_back();
					}
					else
					{
						stunns[q]->reduseDuration();
					}
				}
			}
		}
		else // Zombies Turn
		{			
			AbilityManager::setAllAbilityToFalse();
			HudManager::getInstance()->HideAbilityHud();

			if(activeUnit != 0)
			{
				activeUnit->setDeactive();
				activeUnit->getCurrentTile().setDeactive();
				activeUnit->getCurrentTile().setDeactiveWalls();
			}
			activeUnit = 0;

			human_Turn = true;

			Zombie_Action_Points = 12;
			std::cout << "END TURN ZOMBIE" << std::endl;
			for(ZombieVector::size_type i = 0; i < zombies.size();i++)
			{
				zombies[i]->ToggelStunned(false);
				zombies[i]->setAbilityUsed(false);
				zombies[i]->resetAbilityMoveUsed();
				if(zombies[i]->getCurrentTile().getHomeBaseHuman() == true)
				{
					zombies[i]->setMorale(iobj.m_Heal_In_Base_Per_Turn);
				}
			}
			for(int i = stunns.size()-1; i >= 0; i--)
			{
				if(stunns[i]->getCatgory() == Stunn::HUMAN)
				{
					if(stunns[i]->getDuration() <= 1)
					{
						delete stunns[i];
						stunns[i]=stunns.back();
						stunns.pop_back();
					}
					else
					{
						stunns[i]->reduseDuration();
					}
				}
			}
		}
	}
		
	else if(activeUnit != 0)
	{
		for(AbilityVector::size_type i = 0; i < HudManager::getInstance()->getAbilityVector().size(); i++)
		{
			if(HudManager::getInstance()->getAbilityVector()[i]->getSprite().getGlobalBounds().contains(x,y))
			{
				activeUnit->getCurrentTile().setDeactiveWalls();
				AbilityManager::callAbility(activeUnit, HudManager::getInstance()->getAbilityVector()[i]->getGUIname(), humans, zombies, stunns, x ,y, human_Turn);
			}
		}
	}

	if(activeUnit != 0 && AbilityManager::getActiveMoveAbility() == true)
	{
		AbilityManager::Use_Move_Ability(activeUnit, stunns, x, y, human_Turn, Human_Action_Points, Zombie_Action_Points);
	}
	else if(activeUnit != 0 && AbilityManager::getActiveCatchAbility() == true)
	{
		AbilityManager::Use_Catch_Ability(activeUnit, humans, zombies, x,y, human_Turn,Human_Action_Points,Zombie_Action_Points);
	}
	else if(activeUnit != 0 && AbilityManager::getActiveStunnAbility() == true)
	{
		AbilityManager::Use_Stunn_Ability(activeUnit, humans, zombies, stunns, x, y, human_Turn,Human_Action_Points,Zombie_Action_Points);
	}
	else if(activeUnit != 0 && AbilityManager::getActiveHealAbility() == true)
	{
		AbilityManager::Use_Heal_Ability(activeUnit, humans, zombies, x,y, human_Turn,Human_Action_Points,Zombie_Action_Points);
	}
	else if(activeUnit != 0 && AbilityManager::getActiveDmgAbility() == true)
	{
		AbilityManager::Use_Damage_Ability(activeUnit, humans, zombies, x,y, human_Turn,Human_Action_Points,Zombie_Action_Points);
	}

}

