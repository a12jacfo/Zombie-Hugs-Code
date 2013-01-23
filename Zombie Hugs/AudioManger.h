#pragma once

class AudioManager
{
public:
	~AudioManager();
	static AudioManager& getInstance();
private:
	AudioManager();
	AudioManager(const AudioManager &am);
	AudioManager& operator=(const AudioManager aum);
};