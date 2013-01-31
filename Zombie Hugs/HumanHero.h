#ifndef INCLUDED_HUMANHERO
#define INCLUDED_HUMANHERO

#include "GameObject.h"
#include <string>
#include "SFML\System.hpp"

class Tile;

class HumanHero : public GameObject
{
public:
	HumanHero(Tile& tile, std::string name);
	virtual ~HumanHero();
	virtual Category getCategory();
	virtual void setCategory();
	virtual sf::Vector2f getPos();
	virtual void setPos(sf::Vector2f pos);
	virtual bool getActive();
	virtual void setActive();
	virtual void setDeactive();
	virtual int getMorale();
	virtual void setMorale(int i);
	virtual void update(sf::RenderWindow &window);
	virtual Tile& getCurrentTile() const;
	virtual void SetCurrentTile(Tile& newtile);
	virtual void viewAbilities(sf::RenderWindow& window);
	virtual void showAbilityHud();
	virtual void hideAbilityHud();
	virtual bool getShowAbilityHud();
	virtual sf::CircleShape getAbility(std::string abilityName);
	virtual sf::CircleShape getBoundingBox();
	virtual std::string getName();
private:
	sf::CircleShape cirkel;
	sf::CircleShape mAbilityMove; // MOVE 1
	sf::CircleShape mAbilityHeal; // HEAL 2 
	sf::CircleShape mAbilityStunn; // STUNN 3 
	sf::CircleShape mAbilityCatch; // CATCH 4
	sf::CircleShape mAbilityDamage; // DAMGE 5
	sf::Vector2f mPos;
	bool mActive;
	Tile* mCurrentTile;
	bool mShowAbilityHud;
	std::string mName;
	int mMorale;
};
#endif