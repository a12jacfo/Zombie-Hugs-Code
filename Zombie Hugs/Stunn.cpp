#include "Stunn.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

Stunn::Stunn(sf::Vector2f pos, Category cat, int duration) :
	m_Pos(pos),
	m_Duration(duration),
	mCategory(cat)
{

}
Stunn::~Stunn()
{

}

int Stunn::getDuration()
{
	return m_Duration;
}
void Stunn::reduseDuration()
{
	m_Duration--;
}
sf::Vector2f Stunn::getPos()
{
	return m_Pos;
}
Stunn::Category Stunn::getCatgory()
{
	return mCategory;
}
void Stunn::update(sf::RenderWindow& window)
{
	sf::CircleShape cirkel;
	cirkel.setFillColor(sf::Color::Black);
	cirkel.setOrigin(20,20);
	cirkel.setRadius(20);
	cirkel.setPosition(m_Pos);
	window.draw(cirkel);
}
