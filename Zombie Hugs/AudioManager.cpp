#include "AudioManager.h"

#include <iostream>

AudioManager * AudioManager::a_instance = 0;

AudioManager::AudioManager() : sounds_(), resource_directories_()
{
}

AudioManager::~AudioManager()
{
	delete a_instance;
	sounds_.clear();
	resource_directories_.clear();
}

const sf::SoundBuffer& AudioManager::get_sound( const std::string& filename )
{
	// Check, whether the image already exists
	for( std::map<std::string, sf::SoundBuffer>::const_iterator it = sounds_.begin();
		 it != sounds_.end(); 
		 ++it)
	{
		if( filename == it->first )
		{
			std::cout << "DEBUG_MESSAGE: " << filename << " using existing audio.\n";
			return it->second;
		}
	}
	
	// The image doesen't exists. Create it and save it.
	sf::SoundBuffer sound;

	// Search project's main directory
	if( sound.loadFromFile( filename ) )
	{
		sounds_[filename] = sound;
		std::cout << "DEBUG_MESSAGE: " << filename << " loading sound.\n";
		return sounds_[filename];
	}

	// If the image has still not been found, search all registered directories
	for( std::vector< std::string >::iterator it = resource_directories_.begin();
		 it != resource_directories_.end();
		 ++it )
	{
		if( sound.loadFromFile( (*it) + filename ) )
		{
			sounds_[filename] = sound;
			std::cout << "DEBUG_MESSAGE: " << filename << " loading sound.\n";
			return sounds_[filename];
		}

	}

	std::cout << "GAME_ERROR: Sound was not found. It is filled with an empty sound.\n";
	sounds_[filename] = sound;
	return sounds_[filename];
}

void AudioManager::delete_sound( const sf::SoundBuffer& sound )
{
	for( std::map<std::string, sf::SoundBuffer>::const_iterator it = sounds_.begin();
		 it != sounds_.end(); 
		 ++it)
	{
		if( &sound == &it->second )
		{
			sounds_.erase( it );
                        return;
		}
	}
}

void AudioManager::delete_sound( const std::string& filename )
{
	std::map<std::string, sf::SoundBuffer>::const_iterator it = sounds_.find( filename );
	if( it != sounds_.end() )
		sounds_.erase( it );
}

void AudioManager::add_resource_directory( const std::string& directory )
{
	// Check whether the path already exists
	for( std::vector<std::string>::const_iterator it  = resource_directories_.begin();
		 it != resource_directories_.end();
		++it )
	{
		// The path exists. So it isn't necessary to add id once more.
		if( directory == (*it) )
			return;
	}

	// insert the directory
	resource_directories_.push_back( directory );
}

void AudioManager::remove_resource_directory( const std::string& directory )
{
	for( std::vector<std::string>::iterator it  = resource_directories_.begin();
		 it != resource_directories_.end(); )
	{
		// The path exists. So it isn't necessary to add id once more.
		if( directory == (*it) )
			it = resource_directories_.erase( it );
		else
			++it;
	}
}

AudioManager* AudioManager::getInstance()
{
    if (!a_instance)
    {
        a_instance = new AudioManager;
    }
    return a_instance;
}
