#include "GameObject.h"
#include "ConfigFile.h"

GameObject::~GameObject()
{
}

GameObject::Category GameObject::getCategory()
{
	return mCategory;
}
GameObject::Category GameObject::getGameObjectCategory()
{
	return mClass;
}
void GameObject::setCategory()
{
	if(mCategory == HUMAN)
	{
		mCategory = ZOMBIE;
	}
	else
	{
		mCategory = HUMAN;
	}
	mMorale = ConfigFile::getInstance()->getValueOfKey<int>("m_Moral_After_Convertion");
	mConverted = !mConverted;
}
std::string GameObject::getName()
{
	return mName;
}
Tile& GameObject::getCurrentTile() const
{
	return *mCurrentTile;
}
void GameObject::SetCurrentTile(Tile& newTile)
{
	mCurrentTile = &newTile;
}
sf::Vector2f GameObject::getPos()
{
	return mPos;
}
void GameObject::setPos(sf::Vector2f pos)
{
	mPos = pos;
}
bool GameObject::getActive()
{
	return mActive;
}
void GameObject::setActive()
{
	mActive = true;
}
void GameObject::setDeactive()
{
	mActive = false;
}
int GameObject::getMorale()
{
	return mMorale;
}
void GameObject::setMorale(int i)
{
	mMorale = mMorale+=i;
	if(mMorale>100)
	{
		mMorale=100;
	}
	if(mMorale<0)
	{
		mMorale = 0;
	}
}
sf::Sprite GameObject::getBoundingBox()
{
	return m_currentAnimation->getSprite();
}
void GameObject::ToggelStunned(bool a)
{
	mStunned = a;
}
bool GameObject::getStunned()
{
	return mStunned;
}
void GameObject::setAbilityUsed(bool i)
{
	mAbilityUsed = i;
}
bool GameObject::getAbilityUsed()
{
	return mAbilityUsed;
}

void GameObject::reduseStepsLeft()
{
	mMoveAfterAbilityUse = mMoveAfterAbilityUse - 1 ;
}

int GameObject::getStepsLeft()
{
	return mMoveAfterAbilityUse;
}

void GameObject::resetAbilityMoveUsed()
{
	mMoveAfterAbilityUse = ConfigFile::getInstance()->getValueOfKey<int>("m_Move_After_Ability_Used");
}

bool GameObject::getConverted()
{
	return mConverted;
}

void GameObject::ShowCastStunnAnimation(bool a)
{
	mCastStunnAnimation = a;
}

void GameObject::ShowCastCatchAnimation(bool a)
{
	mCastCatchAnimation = a;
}

void GameObject::ShowCastDemoAnimation(bool a)
{
	mCastDemoAnimation = a;
}

void GameObject::ShowCastHealAnimation(bool a)
{
	mCastHealAnimation = a;	
}

void GameObject::ShowGetStunnedAnimation(bool a)
{
	mGetStunnedAnimation = a;
}


void GameObject::ShowGetCatchAnimation(bool a)
{
	mGetCatchAnimation = a;
}

void GameObject::ShowGetHealAnimation(bool a)
{
	mGetHealAnimation = a;
}

void GameObject::ShowGetDemoAnimation(bool a)
{
	mGetDemoAnimation = a;
}

void GameObject::ShowSitDownAnimation(bool a)
{
	mSitDownAnimation = a;
}

void GameObject::ShowRiseUpAnimation(bool a)
{
	mRiseUpAnimation = a;
}

void GameObject::SetActiveSound(bool a)
{
	mPlay_Active_Sound = a;
}

void GameObject::SetWalkSound(bool a)
{
	mPlay_Walk_Sound = a;
}

void GameObject::SetOrderSound(bool a)
{
	mPlay_Order_Sound = a;
}

void GameObject::SetCastHealSound(bool a)
{
	mPlay_CastHeal_Sound = a;
}
void GameObject::SetCastStunnSound(bool a)
{
	mPlay_CastStunn_Sound = a;
}
void GameObject::SetCastDemoSound(bool a)
{
	mPlay_CastDemo_Sound = a;
}
void GameObject::SetCastCatchSound(bool a)
{
	mPlay_CastCatch_Sound = a;
}
void GameObject::SetGetHealSound(bool a)
{
	mPlay_GetHeal_Sound = a;
}
void GameObject::SetGetStunnSound(bool a)
{
	mPlay_GetStunn_Sound = a;
}
void GameObject::SetGetDemoSound(bool a)
{
	mPlay_GetDemo_Sound = a;
}
void GameObject::SetGetCatchSound(bool a)
{
	mPlay_GetCatch_Sound = a;
}