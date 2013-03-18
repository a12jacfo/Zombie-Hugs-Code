#include "GUIAbilityButton.h"
#include "ImageManager.h"

GUIAbilityButton::GUIAbilityButton(const sf::Texture& texture, GUIname ButtonName) :
	mGUIButtonName(ButtonName)
{
	m_texture = texture;
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(20,20);
}

GUIAbilityButton::~GUIAbilityButton()
{
}

void GUIAbilityButton::setPosition(const sf::Vector2f& position) 
{
	m_sprite.setPosition(position);
}

const sf::Sprite& GUIAbilityButton::getSprite() const 
{
	return m_sprite;
}

const GUIAbilityButton::GUIname GUIAbilityButton::getGUIname() const
{
	return mGUIButtonName;
}
