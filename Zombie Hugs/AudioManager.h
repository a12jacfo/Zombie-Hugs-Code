#pragma once

#include <map>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class AudioManager
{
public:
	~AudioManager();
	static AudioManager* getInstance();
private:
	static AudioManager* a_instance;
	AudioManager();
	AudioManager(const AudioManager &am);
	AudioManager& operator=(const AudioManager &am);

public:
	const sf::SoundBuffer& get_sound( const std::string& filename );
	const std::string get_music( const std::string& filename);
	void delete_sound( const sf::SoundBuffer& image );
	void delete_sound( const std::string& filename );
	void add_resource_directory( const std::string& directory );
	void remove_resource_directory( const std::string& directory );

private:
	std::map< std::string, sf::SoundBuffer > sounds_;
	std::vector< std::string > resource_directories_;
};