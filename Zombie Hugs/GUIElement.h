#pragma once

#include "SFML\Graphics.hpp"

class GUIElement
{
public:
	GUIElement();
	static enum GUIname {HEAL, MOVE, DAMGE, STUNN, CATCH, ENDTURN};
	virtual ~GUIElement();
	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual const sf::Sprite& getSprite() const = 0;
	virtual const GUIname getGUIname() const = 0;
};

