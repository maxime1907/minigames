#include "stdafx.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include "PatternManager.h"


PatternManager::PatternManager()
{
	this->chosen_pattern = 0;
	for (unsigned x = 0; x < 20; x++)
	{
		this->map.push_back("000000000000000000");
	}
}


PatternManager::~PatternManager()
{

}

void PatternManager::reset_map()
{
	this->map.clear();
	for (unsigned x = 0; x < 20; x++)
	{
		this->map.push_back("000000000000000000");
	}
}

void	PatternManager::assign_line()
{
	std::stringstream s;
	std::string str;

	if (this->chosen_pattern == 0)
		this->chosen_pattern = this->chose_a_new_pattern();
	else
		this->chosen_pattern = 0;
	std::string tmp = this->number_to_string_pattern(this->chosen_pattern);
	s << tmp;
	while (std::getline(s, str))
		this->lines.push_back(str);
}

std::vector<std::string> PatternManager::get_your_pattern()
{
	std::string line = this->get_next_line();
	this->add_line(line);
	return this->map;
}

unsigned PatternManager::chose_a_new_pattern()
{
	unsigned which = (std::rand() % 8) + 1;

	return which;
}

std::string PatternManager::number_to_string_pattern(unsigned number)
{
	switch (number)
	{
	case 1:
		return this->pattern1;
	case 2:
		return this->pattern2;
	case 3:
		return this->pattern3;
	case 4:
		return this->pattern4;
	case 5:
		return this->pattern5;
	case 6:
		return this->pattern6;
	case 7:
		return this->pattern7;
	case 8:
		return this->pattern8;
	default:
		return this->blank_pattern;
	}
}

std::string PatternManager::get_next_line()
{
	if (this->lines.empty())
		this->assign_line();
	std::string line = this->lines.at(0);
	this->lines.erase(this->lines.begin());
	return line;
}

std::string PatternManager::line_to_map(std::string line)
{
	std::string tmp = "";

	for (auto c = line.begin(); c < line.end(); c++)
	{
		if ((*c) == '0')
			tmp += "0";
		else if ((*c) == '1')
			tmp += "1";
	}

	return tmp;
}

void PatternManager::add_line(std::string line)
{
	//On retire la première ligne
	this->map.erase(this->map.begin());

	//On converti la prochaine ligne
	this->map.push_back(line);
}