#include "HudManager.h"
#include "ImageManager.h"
#include <sstream>
#include <iostream>
#include "GameObject.h"

HudManager * HudManager::hm_instance = 0;

HudManager::HudManager()
{
	m_Human_Side_Turn_Pos.x = 710;
	m_Human_Side_Turn_Pos.y = 5;
	m_Zombie_Side_Turn_Pos.x = 470;
	m_Zombie_Side_Turn_Pos.y = 5;

	m_Human_Side_Score_Pos.x = 831;
	m_Human_Side_Score_Pos.y = 4;
	m_Zombie_Side_Score_Pos.x = 329;
	m_Zombie_Side_Score_Pos.y = 4;

	mAbilityMove = new GUIAbilityButton(ImageManager::getInstance()->get_image("Resources/Images/hud/Actionbar/Actionbar_Walking.png"), GUIElement::MOVE);
	mAbilityHeal = new GUIAbilityButton(ImageManager::getInstance()->get_image("Resources/Images/hud/Actionbar/Actionbar_Positive.png"), GUIElement::HEAL);
	mAbilityStunn = new GUIAbilityButton(ImageManager::getInstance()->get_image("Resources/Images/hud/Actionbar/Actionbar_Stun_Z.png"), GUIElement::STUNN);
	mAbilityCatch = new GUIAbilityButton(ImageManager::getInstance()->get_image("Resources/Images/hud/Actionbar/Actionbar_Heart.png"), GUIElement::CATCH);
	mAbilityDamage = new GUIAbilityButton(ImageManager::getInstance()->get_image("Resources/Images/hud/Actionbar/Actionbar_Negative.png"),GUIElement::DAMGE);
	
	m_Ability_hud.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Actionbar/Actionbar_Z.png"));
	m_Ability_hud.setPosition(0,635);

	m_Score_hud.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/HUDTop.png"));
	m_Score_hud.setPosition(304,-1);

	m_Go_Turn.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/HUD_Go_Turn.png"));
	m_Nogo_Turn.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/HUD_Stop_Turn.png"));

	m_Zombie_One_Score.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/Z_Score_1.png"));
	m_Zombie_Two_Score.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/Z_Score_2.png"));
	m_Zombie_Three_Score.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/Z_Score_3.png"));
	
	m_Human_One_Score.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/H_Score_1.png"));
	m_Human_Two_Score.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/H_Score_2.png"));
	m_Human_Three_Score.setTexture(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/H_Score_3.png"));

	m_Zombie_One_Score.setPosition(m_Zombie_Side_Score_Pos);
	m_Zombie_Two_Score.setPosition(m_Zombie_Side_Score_Pos);
	m_Zombie_Three_Score.setPosition(m_Zombie_Side_Score_Pos);
	
	m_Human_One_Score.setPosition(m_Human_Side_Score_Pos);
	m_Human_Two_Score.setPosition(m_Human_Side_Score_Pos);
	m_Human_Three_Score.setPosition(m_Human_Side_Score_Pos);

	mAp.setCharacterSize(35);
	mAp.setPosition(620,35);
	mAp.setColor(sf::Color::Black);

	mGUIButtonEndTurn = new GUIButtonEndTurn(ImageManager::getInstance()->get_image("Resources/Images/hud/Scorebar/End_Turn_Button.png"),GUIElement::ENDTURN);
	mGUIElements.push_back(mGUIButtonEndTurn);

}

HudManager::~HudManager()
{
	delete hm_instance;
}

HudManager* HudManager::getInstance()
{
    if (!hm_instance)
    {
        hm_instance = new HudManager;
    }
    return hm_instance;
}

HudManager::AbilityVector& HudManager::getAbilityVector()
{
	return mAbilitys;
}

void HudManager::HideAbilityHud()
{
	mAbilitys.clear();
}

void HudManager::ShowAbilityHud(GameObject& activeUnit)
{
	sf::Vector2f abpos;
	
	for(TileVector::size_type i = 0; i < activeUnit.getCurrentTile().getVector().size(); i++)
	{
		activeUnit.getCurrentTile().getVector()[i]->setDeactiveWalls();
	}
	activeUnit.getCurrentTile().setActive();

	if(activeUnit.getGameObjectCategory() == GameObject::HERO)
	{
		abpos = sf::Vector2f(290,652);
		mAbilityMove->setPosition(abpos);
		mAbilitys.push_back(mAbilityMove);

		abpos = sf::Vector2f(410,655);
		mAbilityHeal->setPosition(abpos);
		mAbilitys.push_back(mAbilityHeal);

		abpos = sf::Vector2f(525,652);
		mAbilityStunn->setPosition(abpos);
		mAbilitys.push_back(mAbilityStunn);

		abpos = sf::Vector2f(638,652);
		mAbilityCatch->setPosition(abpos);
		mAbilitys.push_back(mAbilityCatch);

		abpos = sf::Vector2f(758,655);
		mAbilityDamage->setPosition(abpos);
		mAbilitys.push_back(mAbilityDamage);
	}
	else if(activeUnit.getGameObjectCategory() == GameObject::CATCHER)
	{
		abpos = sf::Vector2f(290,652);
		mAbilityMove->setPosition(abpos);
		mAbilitys.push_back(mAbilityMove);

		abpos = sf::Vector2f(638,652);
		mAbilityCatch->setPosition(abpos);
		mAbilitys.push_back(mAbilityCatch);
	}
	else if(activeUnit.getGameObjectCategory() == GameObject::STUNNER)
	{
		abpos = sf::Vector2f(290,652);
		mAbilityMove->setPosition(abpos);
		mAbilitys.push_back(mAbilityMove);

		abpos = sf::Vector2f(525,652);
		mAbilityStunn->setPosition(abpos);
		mAbilitys.push_back(mAbilityStunn);
	}
	else if(activeUnit.getGameObjectCategory() == GameObject::HEALER)
	{
		abpos = sf::Vector2f(290,652);
		mAbilityMove->setPosition(abpos);
		mAbilitys.push_back(mAbilityMove);

		abpos = sf::Vector2f(410,655);
		mAbilityHeal->setPosition(abpos);
		mAbilitys.push_back(mAbilityHeal);

		abpos = sf::Vector2f(758,655);
		mAbilityDamage->setPosition(abpos);
		mAbilitys.push_back(mAbilityDamage);
	}
}

void HudManager::update(sf::RenderWindow& window, bool& humanTurn, int& humanAP, int& zombieAP, int& humanScore, int& zombieScore)
{
	window.draw(m_Ability_hud);
	window.draw(m_Score_hud);
	std::stringstream ss;
	if(humanTurn == true)
	{
		ss.clear();
		ss.str("");
		ss << humanAP;
		mAp.setString(ss.str());
		m_Go_Turn.setPosition(m_Human_Side_Turn_Pos);
		m_Nogo_Turn.setPosition(m_Zombie_Side_Turn_Pos);
	}
	else
	{
		ss.clear();
		ss.str("");
		ss << zombieAP;
		mAp.setString(ss.str());
		m_Go_Turn.setPosition(m_Zombie_Side_Turn_Pos);
		m_Nogo_Turn.setPosition(m_Human_Side_Turn_Pos);
		
	}
	if(humanScore == 1)
	{
		window.draw(m_Human_One_Score);
	}
	else if(humanScore == 2)
	{
		window.draw(m_Human_Two_Score);
	}
	else if(humanScore == 3)
	{
		window.draw(m_Human_Three_Score);
	}

	if(zombieScore == 1)
	{
		window.draw(m_Zombie_One_Score);
	}
	else if(zombieScore == 2)
	{
		window.draw(m_Zombie_Two_Score);
	}
	else if(zombieScore == 3)
	{
		window.draw(m_Zombie_Three_Score);
	}






	

	window.draw(m_Go_Turn);
	window.draw(m_Nogo_Turn);
	window.draw(mAp);

	for(AbilityVector::size_type i = 0; i < mAbilitys.size(); i++)
	{
		window.draw(mAbilitys[i]->getSprite());
	}
	for(GUIElementVector::size_type i = 0; i < mGUIElements.size(); i++)
	{
		window.draw(mGUIElements[i]->getSprite());
	}
}