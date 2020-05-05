//
// Shoot.cpp for Shoot in /home/maxime1907/Documents/tictoe_r
// 
// Made by maxime1907
// Login   <maxime.leroy@epitech.eu>
// 
// Started on  Thu Sep 21 15:54:44 2017 maxime1907
// Last update Thu Sep 21 15:54:45 2017 maxime1907
//

#include "Shoot.hpp"

Shoot::Shoot(const std::string & filename, const sf::Vector2f pos, const e_direction direction)
: Sprite()
{
	this->texture = new sf::Texture();
    this->texture->loadFromFile(filename);

    this->setTexture(*texture);
	this->setPosition(pos.x - (texture->getSize().x / 2), pos.y - texture->getSize().y);
	this->dir = direction;
	this->speedX = 0.6f;
	this->speedY = 0.6f;
}

Shoot::~Shoot()
{

}

bool 	Shoot::collide()
{
	if (getPosition().x < 0 || getPosition().x > SCREEN_WIDTH)
		return (false);
	if (getPosition().y < 0 || getPosition().y > SCREEN_HEIGHT)
		return (false);
	return (true);
}

void 	Shoot::up()
{
	sf::Transformable::move(0, -(this->speedY));
}

void 	Shoot::down()
{
	sf::Transformable::move(0, this->speedY);
}

bool 	Shoot::run()
{

	if (this->dir == e_direction::UP)
		this->up();
	else if (this->dir == e_direction::DOWN)
		this->down();
	return (this->collide());
}