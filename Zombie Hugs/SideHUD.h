#ifndef INCLUDED_SIDEHUD
#define INCLUDED_SIDEHUD

#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include <vector>
#include <string>

class SideHUD
{
public:
	typedef std::vector<GameObject*> HumanVector;
	typedef std::vector<GameObject*> ZombieVector;
	typedef std::vector<sf::Text> UnitVector;
	SideHUD(sf::Vector2f pos, std::string type);
	~SideHUD();
	void update(sf::RenderWindow &window, int &ap, HumanVector &humans, ZombieVector &zombies);
private:
	sf::RectangleShape rect;
	sf::RectangleShape cont;
	sf::Vector2f mSize;
	sf::Vector2f mPos;
	sf::Text ap_Count;
	sf::Text mUnit;
	std::string mTyp;
	UnitVector mUnits;
	sf::Sprite hmorale;
	sf::Sprite zmorale;

};
#endif