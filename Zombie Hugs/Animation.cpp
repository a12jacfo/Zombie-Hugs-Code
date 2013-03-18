#include "Animation.h"

Animation::Animation(const sf::Texture& texture, int timePerFrame, int numFrames) :
	m_timePerFrame(timePerFrame),
	m_numFrames(numFrames),
	m_currentFrame(0)
{
	m_texture = texture;
	m_sprite.setTexture(m_texture);

	sf::IntRect textureRect(0,0,m_texture.getSize().x/m_numFrames,m_texture.getSize().y);
	m_sprite.setTextureRect(textureRect);

	m_sprite.setOrigin(m_texture.getSize().x/m_numFrames/2,m_texture.getSize().y-5);

}

Animation::~Animation()
{
	m_texture.~Texture();
}

void Animation::setTexture(const sf::Texture& texture)
{
	if(*(long*)&m_texture != *(long*)&texture)
	{
		m_texture = texture;
		m_sprite.setTexture(m_texture);
		sf::IntRect textureRect(0,0,m_texture.getSize().x/m_numFrames,m_texture.getSize().y);
		m_sprite.setTextureRect(textureRect);

		m_sprite.setOrigin(m_texture.getSize().x/m_numFrames/2,m_texture.getSize().y-5);
	}
}

sf::Texture& Animation::getTexture()
{
	return m_texture;
}

int Animation::getNumFrames()
{
	return m_numFrames;
}

int Animation::getCurrentFrame()
{
	return m_currentFrame;
}

void Animation::setCurrentFrame(int i)
{
	m_currentFrame = i;
}

void Animation::update() 
{
	if(m_frameTimer.getElapsedTime().asMilliseconds() > m_timePerFrame)
	{
		m_frameTimer.restart();
		m_currentFrame++;
		
		if(m_currentFrame >= m_numFrames)
		{
			m_currentFrame = 0;
		}
		
		sf::IntRect currentRect = m_sprite.getTextureRect();
		currentRect.left = currentRect.width * m_currentFrame;

		m_sprite.setTextureRect(currentRect);
	}
}

void Animation::setPosition(const sf::Vector2f& position) 
{
	m_sprite.setPosition(position);
}

const sf::Sprite& Animation::getSprite() const 
{
	return m_sprite;
}