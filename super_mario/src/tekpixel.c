/*
** tekpixel.c for tekpixel in /home/leroy_0/rendu/gfx_fdf1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Nov 22 21:27:14 2015 leroy_0
** Last update Thu Feb 25 13:36:21 2016 Tekm
*/

#include		<lapin.h>

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color)
{
  ((t_color *)(pix->pixels))[pos->y * pix->clipable.clip_width + pos->x]
    = (*color);
}
