#include "stdafx.h"
#include "Text.h"
#include <iostream>
#include <string>

Text::Text(const std::string & name)
	: sf::Text()
{
	this->t_font = new sf::Font();
	if (this->t_font->loadFromFile(name))
	{
		this->setFont(*this->t_font);
		this->setCharacterSize(24);
		this->setFillColor(sf::Color::Red);
	}
}

Text::~Text()
{

}