/*
** structure.h for structure in /home/leroy_0/rendu/lightning_2015
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Nov 10 10:46:05 2015 leroy_0
** Last update Fri Mar 11 16:55:26 2016 Tekm
*/

#ifndef			STRUCTURE_H_
# define		STRUCTURE_H_

# define		SIZE_X		1025
# define		SIZE_Y		769

#include		<lapin.h>
#include                <stdio.h>
#include		<stdlib.h>
#include                <unistd.h>
#include                <math.h>

typedef struct		s_struct
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*out;
  t_bunny_pixelarray	*font;
  t_bunny_pixelarray	*map;
  t_bunny_pixelarray	*mariol;
  t_bunny_pixelarray	*marior;
  t_bunny_pixelarray	*mariojl;
  t_bunny_pixelarray	*mariojr;
  t_bunny_pixelarray	*over;
  t_bunny_pixelarray	*tmp;
  t_bunny_music         *music;
  t_bunny_music         *effect;
  t_bunny_music		*jump;
  t_bunny_position	fen;
  t_bunny_position	player;
  t_bunny_position	pos[3];
  const	t_bunny_position	*mouse;
  char			dir;
  char			keyr;
  char			keyl;
  char			keyj;
  int			pwhere;
  int			up;
  t_color		color;
  t_color		tmpcol;
}			t_struct;

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
void		        tektext(t_bunny_pixelarray *out,
				t_bunny_pixelarray *font_png,
				const t_bunny_position *pos,
				const char *str);
void                    tekblit(t_bunny_pixelarray *destination,
				const t_bunny_pixelarray *origin,
				const t_bunny_position *pos);
t_color			getpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos);
void                    tekcoldel(t_bunny_pixelarray *dest,
                                  t_color *color,
				  t_color *rcolor);

#endif			/*!STRUCTURE_H_!*/
