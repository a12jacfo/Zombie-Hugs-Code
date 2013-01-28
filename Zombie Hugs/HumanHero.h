#ifndef INCLUDED_HUMANHERO
#define INCLUDED_HUMANHERO

#include "GameObject.h"
#include <string>
#include "SFML\System.hpp"

class Tile;

class HumanHero : public GameObject
{
public:
	HumanHero(Tile* tile);
	virtual ~HumanHero();
	virtual sf::Vector2f getPos();
	virtual void setPos(sf::Vector2f pos);
	virtual bool getActive();
	virtual void setActive();
	virtual void setDeactive();
	virtual void update(sf::RenderWindow &window);
	virtual Tile* getCurrentTile();
	virtual void setCurrentTile(Tile& newTile);
	virtual void viewAbilities(sf::RenderWindow& window);
	virtual void showAbilityHud();
	virtual void hideAbilityHud();
	virtual bool getShowAbilityHud();
	virtual sf::CircleShape getAbility01();
private:
	sf::CircleShape ability01; // MOVE
	sf::CircleShape ability02; // HEAL
	sf::CircleShape ability03; // STUNN
	sf::CircleShape ability04; // CATCH
	sf::CircleShape ability05; // DAMGE
	sf::Vector2f mPos;
	bool mActive;
	Tile* mCurrentTile;
	bool mShowAbilityHud;
};
#endif