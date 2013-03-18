#include "AbilityManager.h"
#include "HudManager.h"
#include "Stunn.h"
#include <iostream>
#include "ConfigFile.h"

#include "SFML\System.hpp"

AbilityManager obj;

AbilityManager::AbilityManager() :
	mMoveAbilityActive(false),
	mHealAbilityActive(false),
	mStunnAbilityActive(false),
	mDamageAbilityActive(false),
	mCatchAbilityActive(false),
	mAbilityActive(false)
{
	m_Move_Cost = ConfigFile::getInstance()->getValueOfKey<int>("m_Move_Cost");
	m_Heal_Cost = ConfigFile::getInstance()->getValueOfKey<int>("m_Heal_Cost");
	m_Catch_Cost = ConfigFile::getInstance()->getValueOfKey<int>("m_Catch_Cost");
	m_Stunn_Cost_Unit = ConfigFile::getInstance()->getValueOfKey<int>("m_Stunn_Cost_Unit");
	m_Damage_Const = ConfigFile::getInstance()->getValueOfKey<int>("m_Damage_Const");
	m_Call_In_Hero_Cost = ConfigFile::getInstance()->getValueOfKey<int>("m_Call_In_Hero_Cost");
	m_Stunn_Duration_Ground = ConfigFile::getInstance()->getValueOfKey<int>("m_Stunn_Duration_Ground");
	m_Stunn_SuccessRate_Unit = ConfigFile::getInstance()->getValueOfKey<int>("m_Stunn_SuccessRate_Unit");
	m_Damage_Amount = ConfigFile::getInstance()->getValueOfKey<int>("m_Damage_Amount");
	m_Catch_Fail_Drain = ConfigFile::getInstance()->getValueOfKey<int>("m_Catch_Fail_Drain");
	m_Heal_Amount = ConfigFile::getInstance()->getValueOfKey<int>("m_Heal_Amount");
}

AbilityManager::~AbilityManager(void)
{
}

void AbilityManager::setAllAbilityToFalse()
{
	obj.mMoveAbilityActive = false;
	obj.mHealAbilityActive = false;
	obj.mStunnAbilityActive = false;
	obj.mDamageAbilityActive = false;
	obj.mCatchAbilityActive = false;
	obj.mAbilityActive = false;
}

void AbilityManager::callAbility(GameObject* activeUnit, GUIElement::GUIname name, HumanVector &humans, ZombieVector &zombies, StunnVector &stunns, float x, float y, bool &humanTurn)
{

	if(name == GUIElement::MOVE)		{	Activate_Move_Ability(activeUnit);						}
	else if(name == GUIElement::DAMGE)	{	Activate_Damage_Abilty(activeUnit, humans, zombies, humanTurn);	}
	else if(name == GUIElement::HEAL)	{	Activate_Heal_Ability(activeUnit, humans, zombies, humanTurn);		}
	else if(name == GUIElement::CATCH)	{	Activate_Catch_Ability(activeUnit, humans, zombies, humanTurn);	}
	else if(name == GUIElement::STUNN)	{	Activate_Stunn_Ability(activeUnit, humans, zombies, humanTurn);	}
}

void AbilityManager::Activate_Move_Ability(GameObject* activeUnit)
{
	setAllAbilityToFalse();
	if(activeUnit->getStunned() == false)
	{
		activeUnit->getCurrentTile().setActiveWalls();
		obj.mTargetPos = activeUnit->getCurrentTile().getPos();
		obj.mAbilityActive = true;
		obj.mMoveAbilityActive = true;
		activeUnit->SetOrderSound(true);
		std::cout << "MOVE" << std::endl;
	}
}
void AbilityManager::Activate_Heal_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, bool &humanTurn)
{
	setAllAbilityToFalse();
	if(activeUnit->getStunned() == false && activeUnit->getConverted() == false)
	{
		if(activeUnit->getAbilityUsed() == false)
		{
			for(TileVector::size_type i = 0; i< activeUnit->getCurrentTile().getVector().size(); i++)
			{
				if(humanTurn == true)
				{
					if(activeUnit->getCurrentTile().getVector()[i]->getOccupied() == true)
					{
						for(HumanVector::size_type h = 0; h < humans.size(); h++)
						{
							if(activeUnit->getCurrentTile().getVector()[i]->getPos() == humans[h]->getPos())
							{
								humans[h]->getCurrentTile().setActive();
							}
						}
						
					}
				}
				else
				{
					if(activeUnit->getCurrentTile().getVector()[i]->getOccupied() == true)
					{
						for(ZombieVector::size_type z = 0; z < humans.size(); z++)
						{
							if(activeUnit->getCurrentTile().getVector()[i]->getPos() == zombies[z]->getPos())
							{
								zombies[z]->getCurrentTile().setActive();
							}
						}
					}
				}
			}
			activeUnit->SetOrderSound(true);
			obj.mAbilityActive = true;
			obj.mHealAbilityActive = true;
			std::cout << "HEAL" << std::endl;
		}
		else
		{
			std::cout<< "alredy used"<<std::endl;
		}
	}
}
void AbilityManager::Activate_Damage_Abilty(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, bool &humanTurn)
{
	setAllAbilityToFalse();
	if(activeUnit->getStunned() == false  && activeUnit->getConverted() == false)
	{
		if(activeUnit->getAbilityUsed() == false)
		{
			for(TileVector::size_type i = 0; i< activeUnit->getCurrentTile().getVector().size(); i++)
			{
				if(activeUnit->getCurrentTile().getVector()[i]->getOccupied() == true)
				{
					if(humanTurn == true)
					{
						for(ZombieVector::size_type q = 0; q < zombies.size(); q++)
						{
							if(zombies[q]->getPos() == activeUnit->getCurrentTile().getVector()[i]->getPos())
							{
								activeUnit->getCurrentTile().getVector()[i]->setActive();
							}
						}
					}
					else
					{
						for(HumanVector::size_type q = 0; q < humans.size(); q++)
						{
							if(humans[q]->getPos() == activeUnit->getCurrentTile().getVector()[i]->getPos())
							{
								activeUnit->getCurrentTile().getVector()[i]->setActive();
							}
						}
					}
				}
			}
			activeUnit->SetOrderSound(true);
			obj.mAbilityActive = true;
			obj.mDamageAbilityActive = true;
			std::cout << "DAMAGE" << std::endl;
		}
		else
		{
			std::cout<< "alredy used"<<std::endl;
		}
	}
}
void AbilityManager::Activate_Catch_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, bool &humanTurn)
{
	setAllAbilityToFalse();
	if(activeUnit->getStunned() == false  && activeUnit->getConverted() == false)
	{
		if(activeUnit->getAbilityUsed() == false)
		{
			for(TileVector::size_type i = 0; i< activeUnit->getCurrentTile().getVector().size(); i++)
			{
				if(activeUnit->getCurrentTile().getVector()[i]->getOccupied() == true)
				{
					if(humanTurn == true)
					{
						for(ZombieVector::size_type q = 0; q < zombies.size(); q++)
						{
							if(zombies[q]->getPos() == activeUnit->getCurrentTile().getVector()[i]->getPos())
							{
								activeUnit->getCurrentTile().getVector()[i]->setActive();
							}
						}
					}
					else
					{
						for(HumanVector::size_type q = 0; q < humans.size(); q++)
						{
							if(humans[q]->getPos() == activeUnit->getCurrentTile().getVector()[i]->getPos())
							{
								activeUnit->getCurrentTile().getVector()[i]->setActive();
							}
						}
					}
				}
			}
			activeUnit->SetOrderSound(true);
			obj.mAbilityActive = true;
			obj.mCatchAbilityActive = true;
			std::cout << "CATCH" << std::endl;
		}
		else
		{
			std::cout<< "alredy used"<<std::endl;
		}
	}
}
void AbilityManager::Activate_Stunn_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, bool &humanTurn)
{
	setAllAbilityToFalse();
	if(activeUnit->getStunned() == false  && activeUnit->getConverted() == false)
	{
		if(activeUnit->getAbilityUsed() == false)
		{
			for(TileVector::size_type o = 0; o < activeUnit->getCurrentTile().getVector().size(); o++)
			{
				if(activeUnit->getCurrentTile().getVector()[o]->getOccupied() == false)
				{
					activeUnit->getCurrentTile().getVector()[o]->setActive();
				}
				if(humanTurn == true)
				{
					for(ZombieVector::size_type z = 0; z < zombies.size(); z++)
					{
						if(zombies[z]->getPos() == activeUnit->getCurrentTile().getVector()[o]->getPos())
						{
							activeUnit->getCurrentTile().getVector()[o]->setActive();
						}
					}
				}
				if(humanTurn == false)
				{
					for(HumanVector::size_type h = 0; h < humans.size(); h++)
					{
						if(humans[h]->getPos() == activeUnit->getCurrentTile().getVector()[o]->getPos())
						{
							activeUnit->getCurrentTile().getVector()[o]->setActive();
						}					
					}
				}
			}
			activeUnit->SetOrderSound(true);
			obj.mAbilityActive = true;
			obj.mStunnAbilityActive = true;
			std::cout << "STUNN" << std::endl;
		}
		else
		{
			std::cout<< "alredy used"<<std::endl;
		}
	}
}
void AbilityManager::Use_Move_Ability(GameObject* activeUnit, StunnVector &stunns, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points)
{
	if(activeUnit->getStunned() == false )
	{
		if(humanTurn == true)
		{		
			if(Human_Action_Points >= obj.m_Move_Cost)
			{	
				if(activeUnit->getAbilityUsed() == true)
				{
					if(activeUnit->getStepsLeft() > 0)
					{
						for(TileVector::size_type g = 0; g < activeUnit->getCurrentTile().getVector().size(); g++)
						{
							if(activeUnit->getCurrentTile().getVector()[g]->getHex().getGlobalBounds().contains(x, y) && activeUnit->getCurrentTile().getVector()[g]->getOccupied() == false)
							{
								activeUnit->reduseStepsLeft();
								activeUnit->getCurrentTile().setOccupied(false);
								activeUnit->getCurrentTile().setDeactive();
								activeUnit->getCurrentTile().setDeactiveWalls();
								activeUnit->SetCurrentTile(*activeUnit->getCurrentTile().getVector()[g]);
								obj.mTargetPos = activeUnit->getCurrentTile().getPos();
								activeUnit->SetWalkSound(true);
								Human_Action_Points -= obj.m_Move_Cost;
								if(stunns.size() != 0)
								{
									for(StunnVector::size_type s = 0; s < stunns.size(); s++)
									{
										if(stunns[s]->getPos() == activeUnit->getCurrentTile().getPos() && stunns[s]->getCatgory() == Stunn::ZOMBIE)
										{
											activeUnit->ToggelStunned(true);
											stunns[s]->reduseDuration();
										}
									}
								}
							}
						}
					}
				}
				else
				{
					if(Human_Action_Points >= obj.m_Move_Cost)
					{	
						for(TileVector::size_type g = 0; g < activeUnit->getCurrentTile().getVector().size(); g++)
						{
							if(activeUnit->getCurrentTile().getVector()[g]->getHex().getGlobalBounds().contains(x, y) && activeUnit->getCurrentTile().getVector()[g]->getOccupied() == false)
							{
								activeUnit->reduseStepsLeft();
								activeUnit->getCurrentTile().setOccupied(false);
								activeUnit->getCurrentTile().setDeactive();
								activeUnit->getCurrentTile().setDeactiveWalls();
								activeUnit->SetCurrentTile(*activeUnit->getCurrentTile().getVector()[g]);
								obj.mTargetPos = activeUnit->getCurrentTile().getPos();
								activeUnit->SetWalkSound(true);
								Human_Action_Points -= obj.m_Move_Cost;
								if(stunns.size() != 0)
								{
									for(StunnVector::size_type s = 0; s < stunns.size(); s++)
									{
										if(stunns[s]->getPos() == activeUnit->getCurrentTile().getPos() && stunns[s]->getCatgory() == Stunn::ZOMBIE)
										{
											activeUnit->ToggelStunned(true);
											stunns[s]->reduseDuration();
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if(Zombie_Action_Points >= obj.m_Move_Cost)
			{
				if(activeUnit->getAbilityUsed() == true)
				{
					if(activeUnit->getStepsLeft() > 0)
					{
						for(TileVector::size_type g = 0; g < activeUnit->getCurrentTile().getVector().size(); g++)
						{
							if(activeUnit->getCurrentTile().getVector()[g]->getHex().getGlobalBounds().contains(x, y) && activeUnit->getCurrentTile().getVector()[g]->getOccupied() == false)
							{
								activeUnit->reduseStepsLeft();
								activeUnit->getCurrentTile().setOccupied(false);
								activeUnit->getCurrentTile().setDeactive();
								activeUnit->getCurrentTile().setDeactiveWalls();
								activeUnit->SetCurrentTile(*activeUnit->getCurrentTile().getVector()[g]);
								obj.mTargetPos = activeUnit->getCurrentTile().getPos();
								activeUnit->SetWalkSound(true);
								Zombie_Action_Points -= obj.m_Move_Cost;
								if(stunns.size() != 0)
								{
									for(StunnVector::size_type s = 0; s < stunns.size(); s++)
									{
										if(stunns[s]->getPos() == activeUnit->getCurrentTile().getPos() && stunns[s]->getCatgory() == Stunn::HUMAN)
										{
											activeUnit->ToggelStunned(true);
											stunns[s]->reduseDuration();
										}
									}
								}
							}
						}
					}
				}
				else
				{
					if(Zombie_Action_Points >= obj.m_Move_Cost)
					{
						for(TileVector::size_type g = 0; g < activeUnit->getCurrentTile().getVector().size(); g++)
						{
							if(activeUnit->getCurrentTile().getVector()[g]->getHex().getGlobalBounds().contains(x, y) && activeUnit->getCurrentTile().getVector()[g]->getOccupied() == false)
							{
								activeUnit->getCurrentTile().setOccupied(false);
								activeUnit->getCurrentTile().setDeactive();
								activeUnit->getCurrentTile().setDeactiveWalls();
								activeUnit->SetCurrentTile(*activeUnit->getCurrentTile().getVector()[g]);
								obj.mTargetPos = activeUnit->getCurrentTile().getPos();
								activeUnit->SetWalkSound(true);
								Zombie_Action_Points -= obj.m_Move_Cost;
								if(stunns.size() != 0)
								{
									for(StunnVector::size_type s = 0; s < stunns.size(); s++)
									{
										if(stunns[s]->getPos() == activeUnit->getCurrentTile().getPos() && stunns[s]->getCatgory() == Stunn::HUMAN)
										{
											activeUnit->ToggelStunned(true);
											stunns[s]->reduseDuration();
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void AbilityManager::Use_Heal_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points)
{
	if(activeUnit->getAbilityUsed() == false)
	{
		for(TileVector::size_type w = 0; w < activeUnit->getCurrentTile().getVector().size(); w++)
		{
			if(activeUnit->getCurrentTile().getVector()[w]->getHex().getGlobalBounds().contains(x, y) && activeUnit->getCurrentTile().getVector()[w]->getActive()==true)
			{
				if(humanTurn == true)
				{
					if(Human_Action_Points >= obj.m_Heal_Cost)
					{
						for(HumanVector::size_type z = 0;z < humans.size();z++)
						{
							if(activeUnit->getCurrentTile().getVector()[w]->getPos() == humans[z]->getCurrentTile().getPos())
							{
								if(humans[z]->getMorale() > 0)
								{
									humans[z]->ShowRiseUpAnimation(true);
								}
								humans[z]->setMorale(obj.m_Heal_Amount);
								humans[z]->ToggelStunned(false);
								obj.mTargetPos = humans[z]->getCurrentTile().getPos();
								obj.mCasterPos = activeUnit->getPos();
								humans[z]->ShowGetHealAnimation(true);
								activeUnit->ShowCastHealAnimation(true);
								activeUnit->setAbilityUsed(true);
								std::cout << "heal" << std::endl;
								Human_Action_Points -= obj.m_Heal_Cost;
								break;
							}//if correct unit
						}//for human vector
					}
				}
				else
				{
					if(Zombie_Action_Points >= obj.m_Heal_Cost)
					{
						for(ZombieVector::size_type z = 0;z<zombies.size();z++)
						{
							if(activeUnit->getCurrentTile().getVector()[w]->getPos() == zombies[z]->getCurrentTile().getPos())
							{
								if(zombies[z]->getMorale() > 0)
								{
									zombies[z]->ShowRiseUpAnimation(true);
								}
								zombies[z]->setMorale(obj.m_Heal_Amount);
								zombies[z]->ToggelStunned(false);
								activeUnit->setAbilityUsed(true);
								obj.mTargetPos = zombies[z]->getCurrentTile().getPos();
								obj.mCasterPos = activeUnit->getPos();
								zombies[z]->ShowGetHealAnimation(true);
								activeUnit->ShowCastHealAnimation(true);
								std::cout << "heal" << std::endl;
								Zombie_Action_Points -= obj.m_Heal_Cost;
								break;
							}//if correct unit
						}//for zombie vector
					}//if enough action points
				}//unitclick
			}//for tilevector
		}
	}
	else
	{
		std::cout<<"alredy used"<<std::endl;
	}
}
void AbilityManager::Use_Damage_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points)
{
	if(activeUnit->getAbilityUsed() == false)
	{
		for(TileVector::size_type w = 0; w < activeUnit->getCurrentTile().getVector().size(); w++)
		{
			if(activeUnit->getCurrentTile().getVector()[w]->getHex().getGlobalBounds().contains(x, y) && activeUnit->getCurrentTile().getVector()[w]->getActive()==true)
			{
				if(humanTurn == true)
				{
					if(Human_Action_Points >= obj.m_Damage_Const)
					{
						for(ZombieVector::size_type z = 0; z < zombies.size(); z++)
						{
							if(activeUnit->getCurrentTile().getVector()[w]->getPos() == zombies[z]->getCurrentTile().getPos())
							{
								zombies[z]->setMorale(-obj.m_Damage_Amount);
								std::cout << "dmg" << std::endl;
								if(zombies[z]->getMorale() <= 0)
								{
									zombies[z]->ShowSitDownAnimation(true);
								}
								obj.mTargetPos = zombies[z]->getCurrentTile().getPos();
								obj.mCasterPos = activeUnit->getPos();
								std::cout << zombies[z]->getMorale() << std::endl;
								activeUnit->setAbilityUsed(true);
								activeUnit->ShowCastDemoAnimation(true);
								zombies[z]->ShowGetDemoAnimation(true);
								Human_Action_Points -= obj.m_Damage_Const;
								break;
							}//if correct unit
						}
					}//for zombie vector
				}
				else
				{
				  if(Zombie_Action_Points >= obj.m_Damage_Const)
				  {
						for(HumanVector::size_type z = 0; z < humans.size(); z++)
						{
							if(activeUnit->getCurrentTile().getVector()[w]->getPos() == humans[z]->getCurrentTile().getPos())
							{
								humans[w]->setMorale(-obj.m_Damage_Amount);
								std::cout << "dmg" << std::endl;
								if(humans[z]->getMorale() <= 0)
								{
									humans[z]->ShowSitDownAnimation(true);
								}
								obj.mTargetPos = humans[z]->getCurrentTile().getPos();
								obj.mCasterPos = activeUnit->getPos();
								activeUnit->setAbilityUsed(true);
								activeUnit->ShowCastDemoAnimation(true);
								humans[z]->ShowGetDemoAnimation(true);
								Zombie_Action_Points -= obj.m_Damage_Const;
								break;
							}//if correct unit
						}//
					}
				}
			}//unitclick
		}//for tilevector
	}
	else
	{
		std::cout<<"alredy used"<<std::endl;
	}
}
void AbilityManager::Use_Catch_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points)
{
	if(activeUnit->getAbilityUsed() == false)
	{
		for(TileVector::size_type w = 0; w < activeUnit->getCurrentTile().getVector().size(); w++)
		{
			if(activeUnit->getCurrentTile().getVector()[w]->getHex().getGlobalBounds().contains(x, y) && activeUnit->getCurrentTile().getVector()[w]->getActive() == true)
			{
				if(humanTurn == true)
				{
					if(Human_Action_Points >= obj.m_Catch_Cost)
					{
						for(ZombieVector::size_type z = 0; z < zombies.size(); z++)
						{
							if(activeUnit->getCurrentTile().getVector()[w]->getPos() == zombies[z]->getCurrentTile().getPos())
							{
								int catchChance = rand() % 100+1;
								if(catchChance > zombies[z]->getMorale()-1)
								{
									std::cout << "captured" << std::endl;
									obj.mTargetPos = zombies[z]->getCurrentTile().getPos();
									obj.mCasterPos = activeUnit->getPos();
									zombies[z]->ShowGetCatchAnimation(true);
									zombies[z]->setCategory();
									zombies[z]->ToggelStunned(true);
									humans.push_back(zombies[z]);
									zombies[z] = zombies.back();
									zombies.pop_back();
									activeUnit->ShowCastCatchAnimation(true);
									activeUnit->setAbilityUsed(true);
								}
								else
								{
									std::cout<< "cap dmg " << std::endl;
									obj.mTargetPos = zombies[z]->getCurrentTile().getPos();
									obj.mCasterPos = activeUnit->getPos();
									zombies[z]->setMorale(-obj.m_Catch_Fail_Drain);
									activeUnit->ShowCastCatchAnimation(true);
									activeUnit->setAbilityUsed(true);
								}
								Human_Action_Points -= obj.m_Catch_Cost;
								break;
							}//if correct unit
						}//for zombie vector
					}
				}
				else
				{
					if(Zombie_Action_Points >= obj.m_Catch_Cost)
					{
						for(HumanVector::size_type z = 0; z < humans.size(); z++)
						{
							if(activeUnit->getCurrentTile().getVector()[w]->getPos() == humans[z]->getCurrentTile().getPos())
							{
								int catchChance = rand() % 100+1;
								if(catchChance > humans[z]->getMorale()-1)
								{
									std::cout << "captured" << std::endl;
									obj.mTargetPos = humans[z]->getCurrentTile().getPos();
									obj.mCasterPos = activeUnit->getPos();
									humans[z]->ShowGetCatchAnimation(true);
									humans[z]->setCategory();
									zombies.push_back(humans[z]);
									humans[z] = humans.back();
									humans.pop_back();
									activeUnit->setAbilityUsed(true);
								}
								else
								{
									std::cout<< "cap dmg " << std::endl;
									obj.mTargetPos = humans[z]->getCurrentTile().getPos();
									obj.mCasterPos = activeUnit->getPos();
									humans[z]->setMorale(-obj.m_Catch_Fail_Drain);
									activeUnit->setAbilityUsed(true);
								}
								Zombie_Action_Points -= obj.m_Catch_Cost;
								break;
							}//if correct unit
						}
					}
				}
			}//unitclick
		}
	}
	else
	{
		std::cout<<"alredy used"<<std::endl;
	}
}
void AbilityManager::Use_Stunn_Ability(GameObject* activeUnit, HumanVector &humans, ZombieVector &zombies, StunnVector &stunns, float x, float y, bool &humanTurn,int & Human_Action_Points,int & Zombie_Action_Points)
{
	if(activeUnit->getAbilityUsed() == false)
	{
		for(TileVector::size_type s = 0; s < activeUnit->getCurrentTile().getVector().size(); s++)
		{
			if(activeUnit->getCurrentTile().getVector()[s]->getHex().getGlobalBounds().contains(x, y))
			{
				if(humanTurn == true)
				{
					if(Human_Action_Points >= obj.m_Stunn_Cost_Unit)
					{
						if(activeUnit->getCurrentTile().getVector()[s]->getOccupied())
						{
							int stunnChance = rand() %100;
							if(stunnChance <= obj.m_Stunn_SuccessRate_Unit)
							{
								for(ZombieVector::size_type z = 0; z < zombies.size(); z++)
								{
									if(activeUnit->getCurrentTile().getVector()[s]->getPos() == zombies[z]->getCurrentTile().getPos())
									{
										std::cout << "stunnedplayer" << std::endl;
										obj.mTargetPos = zombies[z]->getCurrentTile().getPos();
										obj.mCasterPos = activeUnit->getPos();
										zombies[z]->ShowGetStunnedAnimation(true);
										zombies[z]->ToggelStunned(true);
										activeUnit->setAbilityUsed(true);
										activeUnit->ShowCastStunnAnimation(true);
									}
								}
							}
							else
							{
								for(ZombieVector::size_type z = 0; z < zombies.size(); z++)
								{
									if(activeUnit->getCurrentTile().getVector()[s]->getPos() == zombies[z]->getCurrentTile().getPos())
									{
										obj.mTargetPos = zombies[z]->getCurrentTile().getPos();
										obj.mCasterPos = activeUnit->getPos();
									}
								}
								std::cout << "stunned fail" << std::endl;
								activeUnit->setAbilityUsed(true);
								activeUnit->ShowCastStunnAnimation(true);
							}										
							Human_Action_Points -= obj.m_Stunn_Cost_Unit;
							break;
						}
						else
						{
							stunns.push_back(new Stunn(activeUnit->getCurrentTile().getVector()[s]->getPos(), Stunn::HUMAN,ConfigFile::getInstance()->getValueOfKey<int>("m_Stunn_Duration_Ground")));
							activeUnit->setAbilityUsed(true);
							Human_Action_Points -= obj.m_Stunn_Cost_Unit;
							break;
						}
					}
				}
				else
				{
					if(Zombie_Action_Points >= obj.m_Stunn_Cost_Unit)
					{
							if(activeUnit->getCurrentTile().getVector()[s]->getOccupied())
							{
								int stunnChance = rand() %100;
								if(stunnChance <= obj.m_Stunn_SuccessRate_Unit)
								{
									for(HumanVector::size_type z = 0; z < humans.size(); z++)
									{
										if(activeUnit->getCurrentTile().getVector()[s]->getPos() == humans[z]->getCurrentTile().getPos())
										{
											std::cout << "stunnedplayer" << std::endl;
											obj.mTargetPos = humans[z]->getCurrentTile().getPos();
											obj.mCasterPos = activeUnit->getPos();
											humans[z]->ShowGetStunnedAnimation(true);
											humans[z]->ToggelStunned(true);
											activeUnit->setAbilityUsed(true);
											activeUnit->ShowCastStunnAnimation(true);
										}
									}
								}
								else
								{
									for(HumanVector::size_type z = 0; z < humans.size(); z++)
									{
										if(activeUnit->getCurrentTile().getVector()[s]->getPos() == humans[z]->getCurrentTile().getPos())
										{
											obj.mTargetPos = humans[z]->getCurrentTile().getPos();
											obj.mCasterPos = activeUnit->getPos();
										}
									}
									std::cout << "stunned fail" << std::endl;
									activeUnit->setAbilityUsed(true);
									activeUnit->ShowCastStunnAnimation(true);
								}
								Zombie_Action_Points -= obj.m_Stunn_Cost_Unit;
								break;
							}
							else
							{
								stunns.push_back(new Stunn(activeUnit->getCurrentTile().getVector()[s]->getPos(), Stunn::ZOMBIE,ConfigFile::getInstance()->getValueOfKey<int>("m_Stunn_Duration_Ground")));
								activeUnit->setAbilityUsed(true);
								Zombie_Action_Points -= obj.m_Stunn_Cost_Unit;
								break;
							}
					 }
				}
			}
		}
	}
	else
	{
		std::cout<<"alredy used"<<std::endl;
	}
}
bool AbilityManager::getActiveMoveAbility()
{
	return obj.mMoveAbilityActive;
}
bool AbilityManager::getActiveCatchAbility()
{
	return obj.mCatchAbilityActive;
}
bool AbilityManager::getActiveStunnAbility()
{
	return obj.mStunnAbilityActive;
}
bool AbilityManager::getActiveDmgAbility()
{
	return obj.mDamageAbilityActive;
}
bool AbilityManager::getActiveHealAbility()
{
	return obj.mHealAbilityActive;
}
bool AbilityManager::isAnyAbilityActive()
{
	return obj.mAbilityActive;
}

sf::Vector2f AbilityManager::getTargetPos()
{
	return obj.mTargetPos;
}

sf::Vector2f AbilityManager::getCasterPos()
{
	return obj.mCasterPos;
}