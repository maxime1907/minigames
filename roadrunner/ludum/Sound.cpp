#include "stdafx.h"
#include "Sound.h"

Sound::Sound(const std::string & name)
{
	this->buffer = new sf::SoundBuffer();
	if (this->buffer->loadFromFile(name))
	{
		setBuffer(*buffer);
	}
}

Sound::~Sound()
{
}