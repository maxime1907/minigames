#pragma once

#include "Play.h"
#include "Menu.h"
#include "Over.h"
#include "Common.h"

class Game
{
	public:
		Game::Game();
		Game::~Game();

	public:
		void	run();

	private:
		void	events();
		bool	isSynchronized();

		mod		mod;

	private:
		sf::RenderWindow			*win;
		Play						*play;
		Menu						*menu;
		Over						*over;

		sf::Clock					*clock;
		sf::Time					lastTime;

		bool						hardcore;
		sf::Vector2f				speed;
};