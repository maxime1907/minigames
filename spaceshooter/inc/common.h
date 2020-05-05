/*
** common.h for common in /home/maxime1907/Documents/tictoe_r
** 
** Made by maxime1907
** Login   <maxime.leroy@epitech.eu>
** 
** Started on  Thu Sep 21 15:06:45 2017 maxime1907
** Last update Thu Sep 21 15:07:05 2017 maxime1907
*/

#ifndef __COMMON__H__
#define __COMMON__H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include <string>

enum e_direction
{
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3
};

#define	SCREEN_WIDTH	1280
#define SCREEN_HEIGHT	800

#define SOUND_AMBIENT	"media/sounds/ambient.ogg"
#define SOUND_SHOOT 	"media/sounds/shoot.ogg"

#define ASSET_PLAYER	"media/assets/spaceship.png"
#define ASSET_SHOOT 	"media/assets/shoot.png"

#endif	/* __COMMON_H__ */