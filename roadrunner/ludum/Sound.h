#pragma once

#include <SFML/Audio.hpp>

class Sound : public sf::Sound
{
	public:
		Sound(const std::string & name);
		~Sound();

	private:
		sf::SoundBuffer		*buffer;
};