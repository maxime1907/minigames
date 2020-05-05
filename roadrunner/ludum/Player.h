#pragma once

#include "Sprite.h"
#include "Text.h"
#include "Sound.h"

class Player : public Sprite
{
	public:
		Player(const std::string & pseudo, std::string & t_name, int id);
		~Player();

	public:
		Text			*getScoreText() const;

		void			setScore(int score);
		int				getScore() const;

		void			move(sf::Keyboard::Key dir);
		void			setSpeed(const sf::Vector2f speed);
		sf::Vector2f	getSpeed() const;

		void			die();
		bool			isColliding(Sprite object) const;
		bool			isAlive() const;

	private:
		bool			alive = true;

		std::string		pseudo;
		int				id;

		Text			*t_score;
		int				v_score;

		sf::Vector2f	speed;
};