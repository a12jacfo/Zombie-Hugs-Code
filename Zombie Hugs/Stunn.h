#ifndef INCLUDED_STUNN
#define INCLUDED_STUNN
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

class Stunn
{
public:
	enum Category{HUMAN, ZOMBIE};
	Stunn(sf::Vector2f pos, Category cat, int duration);
	~Stunn();
	int getDuration();
	void reduseDuration();
	sf::Vector2f getPos();
	Category getCatgory();
	void update(sf::RenderWindow& window);
private:
	sf::Vector2f m_Pos;
	int m_Duration;
	Category mCategory;
};
#endif