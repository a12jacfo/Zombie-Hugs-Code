#include "HumanHealer.h"
#include "AudioManager.h"
#include "ImageManager.h"
#include "AbilityManager.h"
#include "Tile.h"
#include "ConfigFile.h"

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;

HumanHealer::HumanHealer(Tile& tile, std::string name) :
	m_walkLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_walk_straight_left.png" ), 200, 4),
	m_walkRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_walk_straight_right.png" ), 200, 4),
	m_walkUpLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_walk_up_left.png" ), 200, 4),
	m_walkUpRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_walk_up_right.png" ), 200, 4),
	m_walkDownLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_walk_down_left.png" ), 200, 4),
	m_walkDownRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_walk_down_right.png" ), 200, 4),

	m_idelLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_idle_left.png" ), 200, 2),
	m_idelRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_idle_right.png" ), 200, 2),
	m_idelSitLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_sit_idle_left.png" ), 200, 2),
	m_idelSitRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_sit_idle_right.png" ), 200, 2),
	m_idelStunnedLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_stunned_left.png" ), 200, 1),
	m_idelStunnedRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_stunned_right.png" ), 200, 1),

	m_skillHealLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_heal_left.png" ), 200, 10),
	m_skillHealRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_heal_right.png" ), 200, 10),

	//Zombie
	m_c_walkLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_walk_straight_left.png" ), 200, 4),
	m_c_walkRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_walk_straight_right.png" ), 200, 4),
	m_c_walkUpLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_walk_up_left.png" ), 200, 4),
	m_c_walkUpRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_walk_up_right.png" ), 200, 4),
	m_c_walkDownLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_walk_down_left.png" ), 200, 4),
	m_c_walkDownRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_walk_down_right.png" ), 200, 4),

	m_c_idelLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_idle_left.png" ), 200, 2),
	m_c_idelRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_idle_right.png" ), 200, 2),
	m_c_idelSitLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_sit_idle_left.png" ), 200, 2),
	m_c_idelSitRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_sit_idle_right.png" ), 200, 2),
	m_c_idelStunnedLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_stunned_left.png" ), 200, 1),
	m_c_idelStunnedRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c/lyn_c_stunned_right.png" ), 200, 1),

	m_GetHealed(ImageManager::getInstance()->get_image( "Resources/Images/skills/moral_heal.png" ), 200, 12),
	m_GetDemoed(ImageManager::getInstance()->get_image( "Resources/Images/skills/moral_damage.png" ), 200, 12),
	m_GetCatched(ImageManager::getInstance()->get_image( "Resources/Images/skills/uncatch.png" ), 200, 12),
	
	m_GetStunnedLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_get_stunned_left.png" ), 200, 5),
	m_GetStunnedRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_get_stunned_right.png" ), 200, 5),
	m_c_GetStunnedLeft(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c_stunned_left.png" ), 200, 5),
	m_c_GetStunnedRight(ImageManager::getInstance()->get_image( "Resources/Images/lyn/lyn_c_stunned_right.png" ), 200, 5)
{
	m_currentAnimation = &m_idelLeft;
	mCurrentTile = &tile;
	mCurrentTile->setOccupied(true);

	mCategory = GameObject::HUMAN;
	mClass = GameObject::HEALER;
	mName = name;
	mPos = mCurrentTile->getPos();

	mMorale = 100;
	mActive = false;
	mAbilityUsed = false;
	mStunned = false;
	mCastStunnAnimation = false;
	mCastCatchAnimation = false;
	mCastDemoAnimation = false;
	mCastHealAnimation = false;

	mGetStunnedAnimation = false;
	mGetCatchAnimation = false;
	mGetDemoAnimation = false;
	mGetHealAnimation = false;

	mSitDownAnimation = false;
	mRiseUpAnimation = false;
	mConverted = false;
	mMoveAfterAbilityUse = ConfigFile::getInstance()->getValueOfKey<int>("m_Move_After_Ability_Used");
}

HumanHealer::~HumanHealer()
{
}

void HumanHealer::update(sf::RenderWindow &window, bool &m_Unit_is_Walking)
{
	sf::Vector2f lengthVecTarget;
	sf::Vector2f lengthVecCaster;
	sf::Vector2f normal;
	float length;

	lengthVecTarget = sf::Vector2f((AbilityManager::getTargetPos().x - mPos.x),(AbilityManager::getTargetPos().y - mPos.y));
	lengthVecCaster = sf::Vector2f((AbilityManager::getCasterPos().x - mPos.x),(AbilityManager::getCasterPos().y - mPos.y));

	if(mPlay_Active_Sound == true)
	{
		m_Sound.setBuffer(AudioManager::getInstance()->get_sound("Resources/Audio/Sounds/Humans/Lyn/select.wav"));
		m_Sound.setLoop(false);
		m_Sound.play();
		mPlay_Active_Sound = false;
	}

	if(mPlay_Order_Sound == true)
	{
		m_Sound.setBuffer(AudioManager::getInstance()->get_sound("Resources/Audio/Sounds/Humans/Lyn/order.wav"));
		m_Sound.setLoop(false);
		m_Sound.play();	
		mPlay_Order_Sound = false;
	}

	if(mGetCatchAnimation == true)
	{
		m_GetCatched.update();
		m_GetCatched.setPosition(mPos);
		window.draw(m_GetCatched.getSprite());

		if(lengthVecCaster.x > 0)
		{
			if(mCategory == GameObject::ZOMBIE)
				m_currentAnimation = &m_c_idelRight;
			else
				m_currentAnimation = &m_idelRight;
		}
		else if(lengthVecCaster.x < 0)
		{
			if(mCategory == GameObject::ZOMBIE)
				m_currentAnimation = &m_c_idelLeft;
			else
				m_currentAnimation = &m_idelLeft;
		}

		if(m_GetCatched.getCurrentFrame() == m_GetCatched.getNumFrames()-1)
		{
			mGetCatchAnimation = false;
		}
	}
	if(mGetDemoAnimation == true)
	{
		m_GetDemoed.update();
		m_GetDemoed.setPosition(mPos);
		window.draw(m_GetDemoed.getSprite());
		if(m_GetDemoed.getCurrentFrame() == m_GetDemoed.getNumFrames()-1)
		{
			mGetDemoAnimation = false;
		}
	}
	if(mGetHealAnimation == true)
	{
		m_GetHealed.update();
		m_GetHealed.setPosition(mPos);
		window.draw(m_GetHealed.getSprite());
		if(m_GetHealed.getCurrentFrame() == m_GetHealed.getNumFrames()-1)
		{
			mGetHealAnimation = false;
		}
	}

	if(mMorale <= 0)
	{
		if(lengthVecCaster.x > 0 ) 
		{ 
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_idelSitRight;
			else
				m_currentAnimation = &m_c_idelSitRight;	
		}
		else if(lengthVecCaster.x < 0 ) 
		{
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_idelSitLeft;
			else
				m_currentAnimation = &m_c_idelSitLeft;
		}
	}

	else if(mRiseUpAnimation == true && mMorale > 0)
	{
		if(lengthVecCaster.x > 0 ) 
		{
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_idelRight;
			else
				m_currentAnimation = &m_c_idelRight;
		}
		else if(lengthVecCaster.x < 0 ) 
		{ 
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_idelLeft;
			else
				m_currentAnimation = &m_c_idelLeft;
		}
	}

	else if(mCastHealAnimation == true)
	{
		if(lengthVecTarget.x > 0 ) { 
			m_currentAnimation = &m_skillHealRight;
		}
		else if(lengthVecTarget.x < 0 ) {
			m_currentAnimation = &m_skillHealLeft;
		}

		if(m_currentAnimation->getCurrentFrame() == m_currentAnimation->getNumFrames()-1)
		{
			m_currentAnimation->setCurrentFrame(0);
			if(lengthVecTarget.x > 0 ) {
				m_currentAnimation = &m_idelRight;
			}
			else if(lengthVecTarget.x < 0 ) {
				m_currentAnimation = &m_idelLeft;
			}
			mCastHealAnimation = false;
		}
	}

	else if(mGetStunnedAnimation == true)
	{
		if(lengthVecCaster.x > 0) 
		{ 
			m_currentAnimation = &m_GetStunnedRight;
		}
		else if(lengthVecCaster.x < 0) 
		{ 
			m_currentAnimation = &m_GetStunnedLeft;
		}
		if(m_currentAnimation->getCurrentFrame() == m_currentAnimation->getNumFrames()-1)
		{
			m_currentAnimation->setCurrentFrame(0);
			if(lengthVecCaster.x > 0 ) {
				m_currentAnimation = &m_idelStunnedRight;
			}
			else if(lengthVecCaster.x < 0 ) {
				m_currentAnimation = &m_idelStunnedLeft;
			}
			mGetStunnedAnimation = false;
		}
	}

	else if(mActive == true && AbilityManager::getActiveMoveAbility() == true && (AbilityManager::getTargetPos().x - mPos.x) != 0)
	{
		m_Unit_is_Walking = true;

		if(mPlay_Walk_Sound == true)
		{
			m_Sound.resetBuffer();
			m_Sound.setBuffer(AudioManager::getInstance()->get_sound("Resources/Audio/Sounds/Movement/footstep.wav"));
			m_Sound.setLoop(true);
			m_Sound.play();
			mPlay_Walk_Sound = false;	
		}
	
		mCurrentTile->setDeactiveWalls();		

		float dx = (lengthVecTarget.x * lengthVecTarget.x);
		float dy = (lengthVecTarget.y * lengthVecTarget.y);
		float d = (dx + dy);
		length = sqrt(d);
		normal = sf::Vector2f((lengthVecTarget.x/length),(lengthVecTarget.y/length));

		mPos = mPos + normal;

		if(length <= 1)
		{
			length = 0;
			setPos(AbilityManager::getTargetPos());
		}

		if(lengthVecTarget.x > 0 && lengthVecTarget.y < 0) {
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_walkUpRight;
			else
				m_currentAnimation = &m_c_walkUpRight;
		}
		else if(lengthVecTarget.x > 0 && lengthVecTarget.y == 0) { 
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_walkRight;
			else
				m_currentAnimation = &m_c_walkRight;
		}
		else if(lengthVecTarget.x > 0 && lengthVecTarget.y > 0) {
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_walkDownRight;
			else
				m_currentAnimation = &m_c_walkDownRight;
		}
		else if(lengthVecTarget.x < 0 && lengthVecTarget.y > 0) {
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_walkDownLeft; 
			else
				m_currentAnimation = &m_c_walkDownLeft;
		}
		else if(lengthVecTarget.x < 0 && lengthVecTarget.y == 0) { 
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_walkLeft; 
			else
				m_currentAnimation = &m_c_walkLeft;
		}
		else if(lengthVecTarget.x < 0 && lengthVecTarget.y < 0) {
			if(mCategory == GameObject::HUMAN)
				m_currentAnimation = &m_walkUpLeft;
			else
				m_currentAnimation = &m_c_walkUpLeft;
		}

		if(mActive == true && mPos == AbilityManager::getTargetPos())
		{
			m_Sound.stop();
			if(mStunned == false)
			{
				mCurrentTile->setActiveWalls();
				mCurrentTile->setOccupied(true);
				mCurrentTile->setActive();
				setActive();
			}
			if(mStunned == true)
			{
				mCurrentTile->setDeactive();
				mCurrentTile->setDeactiveWalls();
				setDeactive();
			}
			m_Unit_is_Walking = false;

			if(lengthVecTarget.x > 0) {
				if(mCategory == GameObject::HUMAN)
					m_currentAnimation = &m_idelRight; 
				else
					m_currentAnimation = &m_c_idelRight;
			}
			else if(lengthVecTarget.x < 0) {
				if(mCategory == GameObject::HUMAN)
					m_currentAnimation = &m_idelLeft; 
				else
					m_currentAnimation = &m_c_idelLeft;
			}

		}
	}
	else if(mStunned == false)
	{
		if(m_currentAnimation == &m_idelStunnedRight)
		{
			m_currentAnimation = &m_idelRight; 
		}
		else
		{
			m_currentAnimation = &m_idelLeft; 
		}
	}
	m_currentAnimation->update();
	m_currentAnimation->setPosition(mPos);
	window.draw(m_currentAnimation->getSprite());
}