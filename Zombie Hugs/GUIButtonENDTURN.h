#pragma once
#include "guielement.h"

class GUIButtonEndTurn : public GUIElement
{
public:
	GUIButtonEndTurn(const sf::Texture& texture, GUIname ButtonName);
	~GUIButtonEndTurn();
	virtual void setPosition(const sf::Vector2f& position);
	virtual const sf::Sprite& getSprite() const;
	virtual const GUIname getGUIname() const;
private:
	GUIname mGUIButtonName;
	sf::Texture m_texture;
	sf::Sprite m_sprite;;
};

