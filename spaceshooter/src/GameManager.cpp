//
// GameManager.cpp for GameManager in /home/maxime1907/Documents/tictoe_r/src
// 
// Made by maxime1907
// Login   <maxime.leroy@epitech.eu>
// 
// Started on  Thu Sep 21 14:39:14 2017 maxime1907
// Last update Thu Sep 21 14:40:51 2017 maxime1907
//

#include "GameManager.hpp"

GameManager::GameManager()
{
	this->window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "StarWars");
	this->clock = new sf::Clock();
	this->event = new sf::Event();
	this->player = new Player(ASSET_PLAYER, sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - (SCREEN_HEIGHT * 1/14)));

	this->buffer = new sf::SoundBuffer();
	this->sound = new sf::Sound();

    buffer->loadFromFile(SOUND_SHOOT);
    sound->setBuffer(*buffer);
	sound->setVolume(100);
	sound->setLoop(false);
}

GameManager::~GameManager()
{
	delete player;
	delete event;
	delete clock;
	delete window;
}

void 	GameManager::reset()
{
	this->clock->restart();
}

void 	GameManager::events()
{
	while (window->pollEvent(*event))
    {
   		if (event->type == sf::Event::Closed || (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Escape))
	         window->close();
    }
}

void 	GameManager::display()
{
	std::vector<Shoot*>	shoots = player->getShoots();

	window->clear();

	window->draw(*player);

	for (auto it = shoots.begin(); it < shoots.end(); ++it)
	{
		window->draw(*(*it));
	}
}

void 	GameManager::run()
{
	sf::Sound 					ambient;
	sf::SoundBuffer 			buffer;

    buffer.loadFromFile(SOUND_AMBIENT);
    ambient.setBuffer(buffer);
	ambient.setVolume(100);
	ambient.setLoop(true);
	ambient.play();

	while (window->isOpen())
    {
    	if (player->run())
    		sound->play();
    	this->display();
    	this->events();
      	window->display();
    }

    ambient.pause();
    ambient.stop();
}