#include "stdafx.h"
#include "Menu.h"
#include "Common.h"
#include <windows.h>
#include <direct.h>

Menu::Menu()
{
	this->t_background = new Sprite(R_SPRITE("texture-menu-background.png"));
	this->t_background->setScale(sf::Vector2f(W_WIDTH / this->t_background->getGlobalBounds().width,
		W_HEIGHT / this->t_background->getGlobalBounds().height));

	this->ambient = new Sound(R_SOUND("Illuminati.wav"));
	this->ambient->setLoop(true);

	this->init();
}

Menu::~Menu()
{

}

void		Menu::init()
{
	HANDLE			hFind;
	WIN32_FIND_DATA data;
	char			cCurrentPath[FILENAME_MAX];
	std::string		filename;
	std::string		name;

	sf::Vector2f	pos(10, 10);
	float			max = 0;

	this->choosen = 0;
	this->characters.clear();
	_getcwd(cCurrentPath, sizeof(cCurrentPath));
	std::string spritePath = std::string(cCurrentPath) + "\\" + std::string(R_SPRITE("") + std::string("*.*"));
	hFind = FindFirstFile(spritePath.c_str(), &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			filename = data.cFileName;
			std::size_t pos = filename.find("c_");
			if (pos != std::string::npos)
			{
				name = filename.substr(pos);
				this->characters.push_back(Player(std::string(name), R_SPRITE("") + filename, 0));
			}
		} while (FindNextFile(hFind, &data));
		FindClose(hFind);
	}

	for (auto player = characters.begin(); player < characters.end(); player++)
	{
		if (pos.x + (*player).getGlobalBounds().width <= W_WIDTH)
		{
			(*player).setPosition(pos);
			if (max < (*player).getGlobalBounds().height)
				max = (*player).getGlobalBounds().height;
			pos.x += (*player).getGlobalBounds().width;
		}
		else
		{
			pos.x = 10;
			pos.y += max;
			max = 0;
			(*player).setPosition(pos);
		}
	}
	this->ambient->play();
}

void	Menu::exec()
{
	if (choosen >= characters.size())
		choosen = 0;
	else if (choosen < 0)
		choosen = static_cast<int>(characters.size()) - 1;

	this->t_choosen = sf::RectangleShape(sf::Vector2f(this->characters.at(this->choosen).getGlobalBounds().width, 10));
	this->t_choosen.setFillColor(sf::Color::White);
	this->t_choosen.setPosition(this->characters.at(this->choosen).getPosition().x,
		this->characters.at(this->choosen).getPosition().y +
		this->characters.at(this->choosen).getGlobalBounds().height + 5);
}

mod		Menu::events()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		this->effect = new Sound(R_SOUND("Nigga.wav"));
		this->effect->play();
		return (mod::play);
	}
	return (mod::menu);
}

void		Menu::display(sf::RenderWindow *window)
{
	window->draw(*this->t_background);

	for (auto it = characters.begin(); it < characters.end(); it++)
		window->draw(*it);
	window->draw(this->t_choosen);
}

Player 		*Menu::getPlayer()
{
	return (&this->characters.at(this->choosen));
}

void		Menu::setChoosen(int x)
{
	this->choosen = x;
}

int			Menu::getChoosen() const
{
	return (this->choosen);
}
 
mod			Menu::run(sf::RenderWindow *window)
{
	mod		mod;

	mod = this->events();
	this->exec();
	this->display(window);
	if (mod != mod::menu)
	{
		this->ambient->stop();
	}
	return (mod);
}