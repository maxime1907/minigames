#include "stdafx.h"
#include "Common.h"
#include "Game.h"

Game::Game()
{
	std::srand(static_cast<unsigned int>(time(0)));

	this->win = new sf::RenderWindow(sf::VideoMode(W_WIDTH, W_HEIGHT), G_TITLE);
	this->clock = new sf::Clock();

	this->mod = mod::menu;

	this->menu = new Menu();
	this->play = new Play();
	this->over = new Over();

	this->hardcore = true;
}

Game::~Game()
{
	
}

bool	Game::isSynchronized()
{
	sf::Time elapsed = this->clock->getElapsedTime();

	if (elapsed.asMilliseconds() > lastTime.asMilliseconds() + F_LIMIT)
	{
		lastTime = elapsed;
		return (true);
	}
	return (false);
}

void	Game::events()
{
	sf::Event event;
	while (this->win->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->win->close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				this->win->close();
			if (event.key.code == sf::Keyboard::R)
				this->hardcore ? this->hardcore = false : this->hardcore = true;
			if (event.key.code == sf::Keyboard::S)
				this->menu->getPlayer()->getSpeed().x > 1.0f ? this->menu->getPlayer()->setSpeed(sf::Vector2f(1.0f, 1.0f)) :
				this->menu->getPlayer()->setSpeed(sf::Vector2f(5.0f, 5.0f));

			if (this->mod == mod::menu)
			{
				if (event.key.code == sf::Keyboard::Left)
					this->menu->setChoosen(this->menu->getChoosen() - 1);
				else if (event.key.code == sf::Keyboard::Right)
					this->menu->setChoosen(this->menu->getChoosen() + 1);
			}
		}
	}
}

void	Game::run()
{
	while (this->win->isOpen())
	{
		this->events();
		if (this->isSynchronized())
		{
			if (this->mod == mod::menu)
			{
				this->mod = this->menu->run(this->win);
				if (this->mod == mod::play)
					this->play->init(this->hardcore);
			}
			else if (this->mod == mod::play)
			{
				this->mod = this->play->run(this->win, this->menu->getPlayer(), this->clock);
				if (this->mod == mod::over)
					this->over->init(this->clock);
			}
			else if (this->mod == mod::over)
			{
				this->mod = this->over->run(this->win, this->menu->getPlayer(), this->lastTime);
				if (this->mod == mod::menu)
					this->menu->init();
			}
			this->win->display();
		}
	}
}