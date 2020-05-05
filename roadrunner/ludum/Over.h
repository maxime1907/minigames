#pragma once

#include <SFML/Graphics.hpp>
#include "Sound.h"
#include "Player.h"
#include "Common.h"

class Over
{
	public:
		Over();
		~Over();
		mod		run(sf::RenderWindow *window, Player *player, sf::Time lastTime);
		void	Over::init(sf::Clock *clock);

	private:
		mod		exec(Player *player, sf::Time lastTime);
		void	display(sf::RenderWindow *window);

	private:
		Sound		*ambient;

		sf::Time	last;

		Sprite		*t_background;

		bool		first = true;
};