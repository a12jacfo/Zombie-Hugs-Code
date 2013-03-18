#pragma once

#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\System\Clock.hpp"
#include <string>

class Animation
{
public:
	Animation(const sf::Texture& texture, int timePerFrame, int numFrames);
	~Animation();

	void update();
	void setCurrentFrame(int i);
	void setPosition(const sf::Vector2f& position);
	void setTexture(const sf::Texture& texture);
	sf::Texture& getTexture();

	const sf::Sprite& getSprite() const;
	int getNumFrames();
	int getCurrentFrame();
private:
	sf::Clock m_frameTimer;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	int m_timePerFrame;
	int m_numFrames;
	int m_currentFrame;
};