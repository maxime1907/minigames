/*
** tektext.c for tektext in /home/tekm/tek1/gfx_tekgui/tcore
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Mon Feb 22 12:41:42 2016 Tekm
** Last update Mon Feb 29 18:04:06 2016 Tekm
*/

#include <lapin.h>
#include <stdio.h>
#include "../include/tektext.h"

int		do_text(t_bunny_pixelarray *out,
			const char *str,
			t_bunny_pixelarray *font_png,
			t_text		*text)
{
  text->i = 0;
  text->car = str[text->cpt]*5;
  while (text->i <= 6)
    {
      text->x = text->car;
      while (text->x <= text->car + 4)
	{
	  ((unsigned int *)(out->pixels))[text->z]
	    = ((unsigned int *)(font_png->pixels))[text->x];
	  text->z++;
	  text->x++;
	}
      text->i++;
      text->z -= 5;
      text->z += out->clipable.clip_width;
      text->car = text->car + font_png->clipable.clip_width;
    }
  text->cpt++;
  return (text->cpt);
}

void		tektext(t_bunny_pixelarray *out,
			t_bunny_pixelarray *font_png,
			const t_bunny_position *pos,
			const char *str)
{
  t_text		text;

  text.savey = pos->y;
  text.z = pos->y * out->clipable.clip_width + pos->x;
  text.savepos = pos->y * out->clipable.clip_width + pos->x;
  text.cpt = 0;
  text.savez = 0;
  while (str[text.cpt])
    {
      text.savez = text.z;
      if (str[text.cpt] != '\n')
	{
	  text.cpt = do_text(out, str, font_png, &text);
	  text.z = text.savez + 6;
	}
      else
	text.cpt++;
      if (text.z - (text.savey * out->clipable.clip_width)
	  >= out->clipable.clip_width - 5 || str[text.cpt] == '\n')
       	{
	  text.savepos = text.savepos + (out->clipable.clip_width * 8);
	  text.savey += (out->clipable.clip_width * 8);
	  text.z = text.savepos;
	}
    }
}
