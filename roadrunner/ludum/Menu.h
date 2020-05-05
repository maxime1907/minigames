#pragma once

#include "Sound.h"
#include "Player.h"
#include "Common.h"

class Menu
{
	public:
		Menu();
		~Menu();

		void	init();
		mod		run(sf::RenderWindow *window);
		Player	*getPlayer();
		void	setChoosen(int x);
		int		getChoosen() const;

	private:
		void		exec();
		mod			events();
		void		display(sf::RenderWindow *window);

	private:
		Sprite						*t_background;

		Sound						*effect;
		Sound						*ambient;

		std::vector<Player>			characters;

		sf::RectangleShape			t_choosen;
		int							choosen;
};