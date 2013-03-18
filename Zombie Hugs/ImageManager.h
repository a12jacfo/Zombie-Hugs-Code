#pragma once

#include <map>
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Texture.hpp"

class ImageManager
{
public:
	~ImageManager();
	static ImageManager* getInstance();
private:
	static ImageManager* i_instance;
	ImageManager();
	ImageManager(const ImageManager &im);
	ImageManager& operator=(const ImageManager &im);

public:
	const sf::Texture&	get_image( const std::string& filename );
	void delete_image( const sf::Texture& image );
	void delete_image( const std::string& filename );
	void add_resource_directory( const std::string& directory );
	void remove_resource_directory( const std::string& directory );

private:
	std::map< std::string, sf::Texture > images_;
	std::vector< std::string > resource_directories_;
};


