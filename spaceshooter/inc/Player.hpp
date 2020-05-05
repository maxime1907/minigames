//
// Player.hpp for Player in /home/maxime1907/Documents/tictoe_r/src
// 
// Made by maxime1907
// Login   <maxime.leroy@epitech.eu>
// 
// Started on  Thu Sep 21 15:00:30 2017 maxime1907
// Last update Thu Sep 21 15:00:31 2017 maxime1907
//

#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Shoot.hpp"

class Player : public sf::Sprite
{
	public:
		Player(const std::string & filename, const sf::Vector2f pos);
		virtual ~Player();

	public:
		void 					left();
		void 					right();
		void 					shoot();
		bool					inputs();
		bool 					run();

		sf::Vector2f 			getMiddlePos();
		std::vector<Shoot*>		getShoots();

	private:
		sf::Texture *texture;

	private:
		float 						speedX;
		float 						speedY;
		std::vector<Shoot*> 		shoots;
		unsigned int 				shootLimit;
};

#endif	/* __PLAYER_HPP__ */