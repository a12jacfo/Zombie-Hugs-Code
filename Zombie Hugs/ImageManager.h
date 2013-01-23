#pragma once

#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Texture.hpp"

class ImageManager
{
public:
	~ImageManager();
	static ImageManager& getInstance();
	const sf::Sprite& getGridSprite() const;
	const sf::Sprite& getZombieHealerSprite() const;
private:
	ImageManager();
	ImageManager(const ImageManager &im);
	ImageManager& operator=(const ImageManager igm);
	sf::Texture mHumanHealerTexture;
	sf::Texture mL01GridTexture;
	//sf::Texture mHumanCatcherTexture;
	//sf::Texture mHumanStunnerTexture;
	//sf::Texture mHumanHeroTexture;
	//sf::Texture mZombieHeroTexture;
	//sf::Texture mZombieStunnerTexture;
	//sf::Texture mZombieCatcherTexture;
	sf::Texture mZombieHealerTexture;

	sf::Sprite mHumanHealerSprite;
	sf::Sprite mL01GridSprite;
	//sf::Sprite mHumanCatcherSprite;
	//sf::Sprite mHumanStunnerSprite;
	//sf::Sprite mHumanHeroSprite;
	sf::Sprite mZombieHealerSprite;
	//sf::Sprite mZombieCatcherSprite;
	//sf::Sprite mZombieStunnerSprite;
	//sf::Sprite mZombieHeroSprite;

};

