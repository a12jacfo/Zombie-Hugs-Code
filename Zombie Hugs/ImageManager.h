#pragma once

#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Texture.hpp"

class ImageManager
{
public:
	~ImageManager();
	static ImageManager* getInstance();
	const sf::Sprite& getGridSprite() const;
	const sf::Sprite& getZombieHealerSprite() const;
private:
	static ImageManager* i_instance;
	ImageManager();
	ImageManager(const ImageManager &im);
	ImageManager& operator=(const ImageManager &im);

	sf::Texture mL01GridTexture;
	sf::Sprite mL01GridSprite;


};

