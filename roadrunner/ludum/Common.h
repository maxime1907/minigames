#pragma once

#define		G_TITLE			"NIGGA BLASTER"

#define		W_WIDTH			(1280)
#define		W_HEIGHT		(720)

#define		R_PATH			"Ressources\\"
#define		R_SPRITE(NAME)	R_PATH  "Sprites\\" NAME
#define		R_FONT(NAME)	R_PATH  "Fonts\\" NAME
#define		R_SOUND(NAME)	R_PATH	"Sounds\\" NAME

#define		F_LIMIT			(15)

#define		D_SPEED_X		(1.0f)
#define		D_SPEED_Y		(1.0f)

#define		B_WIDTH_RATIO	(2)
#define		B_HEIGHT_RATIO	(2)

#define		D_TIME			(3)

enum mod
{
	menu = 0,
	play,
	over
};