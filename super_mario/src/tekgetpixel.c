/*
** tekgetpixel.c for tekgetpixel.c in
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Mon Feb 29 23:23:41 2016 Tekm
** Last update Mon Feb 29 23:24:56 2016 Tekm
*/

#include <lapin.h>
#include "../include/mario.h"

t_color                 getpixel(t_bunny_pixelarray *pix,
                                 t_bunny_position *pos)
{
  t_color               color;
  if ((pos->y >= 0 && pos->y <= pix->clipable.clip_height) && (pos->x >= 0 && pos->x <= pix->clipable.clip_width))
    color = ((t_color *)(pix->pixels))[pos->y *
                                       pix->clipable.clip_width + pos->x];
  return (color);
}
