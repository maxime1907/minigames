#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const std::string & name)
	: sf::Sprite()
{
	this->texture = new sf::Texture();
	if (this->texture->loadFromFile(name))
	{
		this->setTexture(*this->texture);
	}
}

Sprite::~Sprite()
{

}