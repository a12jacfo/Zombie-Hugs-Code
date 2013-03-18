#pragma once
#include "guielement.h"
#include "AbilityManager.h"
#include "SFML\Graphics.hpp"

class GUIAbilityButton : public GUIElement
{
public:
	GUIAbilityButton(const sf::Texture& texture, GUIname ButtonName);
	~GUIAbilityButton();
	virtual void setPosition(const sf::Vector2f& position);
	virtual const sf::Sprite& getSprite() const;
	virtual const GUIname getGUIname() const;
private:
	GUIname mGUIButtonName;
	sf::Texture m_texture;
	sf::Sprite m_sprite;;
};

