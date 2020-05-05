//
// Shoot.hpp for Shoot in /home/maxime1907/Documents/tictoe_r
// 
// Made by maxime1907
// Login   <maxime.leroy@epitech.eu>
// 
// Started on  Thu Sep 21 15:54:51 2017 maxime1907
// Last update Thu Sep 21 15:54:52 2017 maxime1907
//

#ifndef __SHOOT_HPP__
#define __SHOOT_HPP__

#include "common.h"

class Shoot : public sf::Sprite
{
	public:
		Shoot(const std::string & filename, const sf::Vector2f pos, const e_direction dir);
		virtual ~Shoot();

	public:
		bool 	run();
		void 	up();
		void 	down();

		bool 	collide();

	private:
		sf::Texture 	*texture;

		e_direction 	dir;
		float 			speedX;
		float 			speedY;
};

#endif /* __SHOOT_HPP__ */