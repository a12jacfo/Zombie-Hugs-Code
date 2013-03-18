#ifndef INCLUDED_GAMEOBJECT
#define INCLUDED_GAMEOBJECT

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

#include "Tile.h"
#include "Animation.h"

class GameObject
{
public:
	virtual ~GameObject();
	enum Category {HUMAN, ZOMBIE, HEALER, STUNNER, CATCHER, HERO};

	virtual void update(sf::RenderWindow &window, bool &m_Unit_is_Walking) = 0;

	virtual Category getCategory();
	virtual Category getGameObjectCategory();
	virtual void setCategory();
	virtual sf::Vector2f getPos();
	virtual void setPos(sf::Vector2f pos);
	virtual void setActive();
	virtual void setDeactive();
	virtual bool getActive();
	virtual void setMorale(int i);
	virtual int getMorale();
	virtual void ToggelStunned(bool a);
	virtual bool getStunned();
	virtual void setAbilityUsed(bool i);
	virtual bool getAbilityUsed();
	virtual Tile& getCurrentTile() const;
	virtual void SetCurrentTile(Tile& newtile);
	virtual sf::Sprite getBoundingBox();
	virtual std::string getName();
	virtual void reduseStepsLeft();
	virtual int getStepsLeft();
	virtual void resetAbilityMoveUsed();
	virtual bool getConverted();

	virtual void ShowCastStunnAnimation(bool a);
	virtual void ShowCastCatchAnimation(bool a);
	virtual void ShowCastHealAnimation(bool a);
	virtual void ShowCastDemoAnimation(bool a);
	
	virtual void ShowGetStunnedAnimation(bool a);
	virtual void ShowGetCatchAnimation(bool a);
	virtual void ShowGetHealAnimation(bool a);
	virtual void ShowGetDemoAnimation(bool a);

	virtual void ShowSitDownAnimation(bool a);
	virtual void ShowRiseUpAnimation(bool a);

	virtual void SetActiveSound(bool a);
	virtual void SetWalkSound(bool a);
	virtual void SetOrderSound(bool a);

	virtual void SetCastHealSound(bool a);
	virtual void SetCastStunnSound(bool a);
	virtual void SetCastDemoSound(bool a);
	virtual void SetCastCatchSound(bool a);

	virtual void SetGetHealSound(bool a);
	virtual void SetGetStunnSound(bool a);
	virtual void SetGetDemoSound(bool a);
	virtual void SetGetCatchSound(bool a);

protected:
	Animation* m_currentAnimation;
	Tile* mCurrentTile;

	sf::Vector2f mPos;
	Category mCategory;
	Category mClass;
	std::string mName;
	int mMoveAfterAbilityUse;

	sf::Sound m_Sound;

	int mMorale;
	
	bool mPlay_Active_Sound;
	bool mPlay_Walk_Sound;
	bool mPlay_Order_Sound;

	bool mPlay_CastHeal_Sound;
	bool mPlay_CastStunn_Sound;
	bool mPlay_CastCatch_Sound;
	bool mPlay_CastDemo_Sound;

	bool mPlay_GetHeal_Sound;
	bool mPlay_GetStunn_Sound;
	bool mPlay_GetCatch_Sound;
	bool mPlay_GetDemo_Sound;

	bool mActive;
	bool mStunned;
	bool mAbilityUsed;
	bool mConverted;

	//Animeringar
	bool mCastStunnAnimation;
	bool mCastCatchAnimation;
	bool mCastHealAnimation;
	bool mCastDemoAnimation;

	bool mGetStunnedAnimation;
	bool mGetCatchAnimation;
	bool mGetHealAnimation;
	bool mGetDemoAnimation;

	bool mSitDownAnimation;
	bool mRiseUpAnimation;
};


#endif