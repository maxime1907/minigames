#include "stdafx.h"
#include "Player.h"
#include "Common.h"

Player::Player(const std::string & pseudo, std::string & t_name, int id)
	: Sprite(t_name)
{
	this->t_score = new Text(R_FONT("Roboto.ttf"));
	this->pseudo = pseudo;
	this->id = id;

	this->setSpeed(sf::Vector2f(D_SPEED_X, D_SPEED_Y));
	this->setScore(0);
}

Player::~Player()
{

}

void	Player::setScore(int score)
{
	this->v_score = score;
	this->t_score->setString(std::to_string(this->v_score));
	this->t_score->setPosition(W_WIDTH - (this->t_score->getLocalBounds().width * 2), 0);
}

int		Player::getScore() const
{
	return (v_score);
}

void	Player::setSpeed(const sf::Vector2f speed)
{
	this->speed = speed;
}

sf::Vector2f	Player::getSpeed() const
{
	return (this->speed);
}

Text	*Player::getScoreText() const
{
	return (t_score);
}

void	Player::move(sf::Keyboard::Key dir)
{
	sf::Vector2f	pos(getPosition().x, getPosition().y);

	if (dir == sf::Keyboard::Left)
		pos.x -= 4.0f * this->speed.x;
	else if (dir == sf::Keyboard::Right)
		pos.x += 4.0f * this->speed.x;
	else if (dir == sf::Keyboard::Up)
		pos.y -= 4.0f * this->speed.y;
	else if (dir == sf::Keyboard::Down)
		pos.y += 4.0f * this->speed.y;

	setPosition(pos);
}

bool	Player::isColliding(Sprite object) const
{
	return (getGlobalBounds().intersects(object.getGlobalBounds()));
}

void	Player::die()
{
	this->alive = false;
}

bool	Player::isAlive() const
{
	return (this->alive);
}