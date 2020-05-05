//
// Player.cpp for Player in /home/maxime1907/Documents/tictoe_r/src
// 
// Made by maxime1907
// Login   <maxime.leroy@epitech.eu>
// 
// Started on  Thu Sep 21 15:00:19 2017 maxime1907
// Last update Thu Sep 21 15:00:21 2017 maxime1907
//

#include "Player.hpp"
#include "common.h"

Player::Player(const std::string & filename, const sf::Vector2f pos)
: Sprite()
{
	this->texture = new sf::Texture();
    this->texture->loadFromFile(filename);

	this->speedX = 0.3f;
	this->speedY = 0.3f;
	this->setPosition(pos.x - (texture->getSize().x / 2), pos.y - (texture->getSize().y / 2));
	this->setTexture(*texture);
	this->setScale(0.5f, 0.5f);
	this->shootLimit = 1;
}

Player::~Player()
{
	delete texture;
}

std::vector<Shoot*> Player::getShoots()
{
	return (shoots);
}

void 	Player::shoot()
{
	shoots.push_back(new Shoot(ASSET_SHOOT, this->getMiddlePos(), e_direction::UP));
}

void 	Player::left()
{
	sf::Transformable::move(-(this->speedX), 0);
}

void 	Player::right()
{
	sf::Transformable::move(this->speedX, 0);
}

bool 		Player::inputs()
{
	bool 	shoot = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shoots.size() < shootLimit)
	{
		this->shoot();
		shoot = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->left();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->right();
	}
	return (shoot);
}

bool 		Player::run()
{
	for (auto it = shoots.begin(); it < shoots.end(); ++it)
	{
		if ((*it)->run() == false)
			shoots.erase(it);
	}
	return (this->inputs());
}

sf::Vector2f 	Player::getMiddlePos()
{
	return (sf::Vector2f(this->getPosition().x + (this->texture->getSize().x / 2), this->getPosition().y));
}