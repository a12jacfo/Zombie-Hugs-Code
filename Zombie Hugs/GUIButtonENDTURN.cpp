#include "GUIButtonEndTurn.h"


GUIButtonEndTurn::GUIButtonEndTurn(const sf::Texture& texture, GUIname ButtonName) :
	mGUIButtonName(ButtonName)
{
	m_texture = texture;
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(20,20);
	m_sprite.setPosition(591,107);
}

GUIButtonEndTurn::~GUIButtonEndTurn()
{
}

void GUIButtonEndTurn::setPosition(const sf::Vector2f& position) 
{
	m_sprite.setPosition(position);
}

const sf::Sprite& GUIButtonEndTurn::getSprite() const 
{
	return m_sprite;
}

const GUIButtonEndTurn::GUIname GUIButtonEndTurn::getGUIname() const
{
	return mGUIButtonName;
}
