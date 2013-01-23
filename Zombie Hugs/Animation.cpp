#include "Animation.h"

Animation::Animation(const sf::Texture& texture, int timePerFrame, int numFrames) :
	mTimePerFrame(timePerFrame),
	mNumFrames(numFrames),
	mCurrentFrame(0)
{
	mSprite.setTexture(texture);

	sf::IntRect textureRect(0,0,mTexture.getSize().x/mNumFrames,mTexture.getSize().y);
	mSprite.setTextureRect(textureRect);
}


Animation::~Animation()
{
}

void Animation::update() 
{
	if(mFrameTimer.getElapsedTime().asMilliseconds() > mTimePerFrame)
	{
		mFrameTimer.restart();
		mCurrentFrame++;
		
		if(mCurrentFrame >= mNumFrames)
		{
			mCurrentFrame = 0;
		}
		
		sf::IntRect currentRect = mSprite.getTextureRect();
		currentRect.left = currentRect.width * mCurrentFrame;

		mSprite.setTextureRect(currentRect);
	}
}

void Animation::setPosition(const sf::Vector2f& position) 
{
	mSprite.setPosition(position);
}

const sf::Sprite& Animation::getSprite() const 
{
	return mSprite;
}
