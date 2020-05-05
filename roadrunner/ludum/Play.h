#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PatternManager.h"
#include "Common.h"

class Play
{
	public:
		Play();
		~Play();
		
		void	init(bool hardcore);
		mod		run(sf::RenderWindow *window, Player *player, sf::Clock	*clock);

	private:
		void	events(Player *player);
		mod		exec(Player *player, sf::Clock	*clock);
		void	display(sf::RenderWindow *window, Player *player);

	private:
		Sound						*ambient;

		Sprite						*t_background;
		Sprite						*t_background2;

		PatternManager				*pattern;

		std::vector<std::string>	lines;
		std::vector<Sprite>			blocks;

		int							B_LIMIT;
		int							rows;
};