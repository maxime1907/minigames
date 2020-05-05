#include "stdafx.h"
#include "Play.h"
#include "Common.h"

Play::Play()
{
	this->t_background = new Sprite(R_SPRITE("texture-background.jpg"));
	this->t_background->setScale(sf::Vector2f(W_WIDTH / this->t_background->getGlobalBounds().width,
		W_HEIGHT / this->t_background->getGlobalBounds().height));

	this->t_background2 = new Sprite(R_SPRITE("texture-background.jpg"));
	this->t_background2->setScale(sf::Vector2f(W_WIDTH / this->t_background2->getGlobalBounds().width,
		W_HEIGHT / this->t_background2->getGlobalBounds().height));

	this->t_background2->setPosition(sf::Vector2f(0, W_HEIGHT));

	this->ambient = new Sound(R_SOUND("Death Note Kyrie II.wav"));
	this->ambient->setLoop(true);

	this->pattern = new PatternManager();

	this->B_LIMIT = 1000;
	this->rows = 0;
}

Play::~Play()
{

}

void	Play::events(Player *player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player->move(sf::Keyboard::Left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player->move(sf::Keyboard::Right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player->move(sf::Keyboard::Up);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player->move(sf::Keyboard::Down);
	}
}

mod	Play::exec(Player *player, sf::Clock	*clock)
{
	static sf::Time			last = clock->getElapsedTime();
	sf::Time				elapsed = clock->getElapsedTime();

	if (elapsed.asMilliseconds() > last.asMilliseconds() + B_LIMIT)
	{
		blocks.clear();

		if (this->rows != 0 && this->rows % 10 == 0)
			this->B_LIMIT -= 10;

		this->lines = this->pattern->get_your_pattern();

		float width = W_WIDTH / static_cast<float>((*this->lines.begin()).size());
		float height = player->getLocalBounds().height * B_HEIGHT_RATIO;
		float x = 0;
		float y = 0;

		for (auto it = this->lines.begin(); it < this->lines.end(); it++)
		{
			for (auto c = (*it).begin(); c < (*it).end(); c++)
			{
				if ((*c) == '0')
				{

				}
				else if ((*c) == '1')
				{
					Sprite line(R_SPRITE("texture-wall2.jpg"));
					line.setScale(width / line.getGlobalBounds().width,
						height / line.getGlobalBounds().height);
					line.setPosition(sf::Vector2f(x, y));
					blocks.push_back(line);
				}
				x += width;
			}
			x = 0;
			y += height;
		}
		last = elapsed;
		this->rows++;
	}

	this->t_background->setPosition(this->t_background->getPosition().x, this->t_background->getPosition().y - 2);
	this->t_background2->setPosition(this->t_background2->getPosition().x, this->t_background2->getPosition().y - 2);

	if (this->t_background->getPosition().y + this->t_background->getGlobalBounds().height <= 0)
	{
		this->t_background->setPosition(this->t_background->getPosition().x, 0);
		this->t_background2->setPosition(this->t_background2->getPosition().x, W_HEIGHT);
	}

	for (auto it = blocks.begin(); it < blocks.end(); it++)
	{
		if (player->isColliding(*it))
			return (mod::over);
	}
	return (mod::play);
}

void	Play::display(sf::RenderWindow *window, Player *player)
{
	window->draw(*this->t_background);
	window->draw(*this->t_background2);

	for (auto it = blocks.begin(); it < blocks.end(); it++)
		window->draw(*it);

	window->draw(*player);
	window->draw(*player->getScoreText());
}

void	Play::init(bool hardcore)
{
	this->ambient->play();
	if (hardcore == false)
		this->pattern = new PatternManager();
}

mod		Play::run(sf::RenderWindow *window, Player *player, sf::Clock	*clock)
{
	mod	mod;

	this->events(player);
	mod = this->exec(player, clock);
	this->display(window, player);
	if (mod != mod::play)
	{
		this->ambient->stop();
	}
	return (mod);
}