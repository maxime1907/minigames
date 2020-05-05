#include "stdafx.h"
#include "Over.h"

Over::Over()
{
	this->t_background = new Sprite(R_SPRITE("die.png"));
	this->t_background->setScale(sf::Vector2f(W_WIDTH / this->t_background->getGlobalBounds().width,
		W_HEIGHT / this->t_background->getGlobalBounds().height));

	this->ambient = new Sound(R_SOUND("No.wav"));
}

Over::~Over()
{

}

void	Over::init(sf::Clock *clock)
{
	this->last = clock->getElapsedTime();
}

mod	Over::exec(Player *player, sf::Time lastTime)
{
	if (lastTime.asSeconds() > last.asSeconds() + D_TIME)
	{
		this->first = true;
		return (mod::menu);
	}
	else if (first)
	{
		player->die();
		this->ambient->play();
		this->first = false;
	}
	return (mod::over);
}

void	Over::display(sf::RenderWindow *window)
{
	window->draw(*this->t_background);
}

mod		Over::run(sf::RenderWindow *window, Player *player, sf::Time lastTime)
{
	mod mod;

	mod = this->exec(player, lastTime);
	this->display(window);
	return (mod);
}
