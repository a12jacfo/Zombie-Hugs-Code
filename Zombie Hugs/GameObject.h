#ifndef INCLUDED_GAMEOBJECT
#define INCLUDED_GAMEOBJECT

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Tile;

class GameObject
{
public:
	virtual ~GameObject(){};
	enum Category {HUMAN,ZOMBIE};
	virtual Category getCategory() = 0;
	virtual void setCategory() = 0;
	virtual sf::Vector2f getPos() = 0;
	virtual void setPos(sf::Vector2f pos) = 0;
	virtual bool getActive() = 0;
	virtual void setActive() = 0;
	virtual void setDeactive() = 0;
	virtual void update(sf::RenderWindow &window) = 0;
	virtual void viewAbilities(sf::RenderWindow& window) = 0;
	virtual Tile& getCurrentTile() const = 0;
	virtual void SetCurrentTile(Tile& newtile) = 0;
	virtual void showAbilityHud() = 0;
	virtual void hideAbilityHud() = 0;
	virtual bool getShowAbilityHud() = 0;
	virtual sf::CircleShape getAbility(std::string abilityName) = 0;
	virtual sf::CircleShape getBoundingBox() = 0;
	virtual std::string getName() = 0;
};
#endif