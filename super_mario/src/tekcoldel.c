/*
** tekcoldel.c for tekcoldel in
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Wed Mar  9 14:07:56 2016 Tekm
** Last update Wed Mar  9 15:58:34 2016 Tekm
*/

#include <lapin.h>
#include "../include/mario.h"

void			tekcoldel(t_bunny_pixelarray	*dest,
				  t_color		*color,
				  t_color		*rcolor)
{
  t_color			tmpcol;
  t_bunny_position		pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < dest->clipable.clip_height)
    {
      tmpcol = getpixel(dest, &pos);
      if (tmpcol.full == color->full)
	tekpixel(dest, &pos, rcolor);
      if (pos.x > dest->clipable.clip_width)
	{
	  pos.x = 0;
	  pos.y++;
	}
      else
	pos.x++;
    }
}
