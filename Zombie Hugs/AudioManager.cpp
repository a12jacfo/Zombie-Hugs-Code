#include "AudioManger.h"

AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
}

AudioManager& AudioManager::getInstance()
{
	static AudioManager audiomanager;
	return audiomanager;
}