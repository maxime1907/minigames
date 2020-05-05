//
// GameManager.hpp for GameManager in /home/maxime1907/Documents/tictoe_r/src
// 
// Made by maxime1907
// Login   <maxime.leroy@epitech.eu>
// 
// Started on  Thu Sep 21 14:39:29 2017 maxime1907
// Last update Thu Sep 21 14:41:31 2017 maxime1907
//

#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

#include "common.h"

#include "Player.hpp"

class GameManager
{
	public:
		GameManager();
		virtual ~GameManager();

	public:
		void 	run();
		void 	reset();
		void 	events();
		void 	display();

	private:
		sf::RenderWindow 		*window;
		sf::Event               *event;
		sf::Clock               *clock;
		sf::SoundBuffer			*buffer;
		sf::Sound 				*sound;

	private:
		Player 	*player;
};

#endif	/* __GAMEMANAGER_H_ */