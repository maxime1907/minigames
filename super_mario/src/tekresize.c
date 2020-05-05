/*
** tekresize.c for tekresize in
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Mon Feb 29 19:33:26 2016 Tekm
** Last update Mon Feb 29 22:27:12 2016 Tekm
*/

#include <lapin.h>
#include "../include/mario.h"

void				tekresize(t_bunny_pixelarray *pix,
					  t_bunny_pixelarray *resized, int resize)
{
  int				savey;
  int				cpt;
  int				i;

  i = 0;
  cpt = 0;
  savey = 0;
  while (cpt < pix->clipable.clip_width * pix->clipable.clip_height
	 && i < resized->clipable.clip_width * resized->clipable.clip_height)
    {
      ((t_color *)(resized->pixels))[i] = ((t_color *)(pix->pixels))[cpt];
      if (cpt - (savey * pix->clipable.clip_width)
      	  > pix->clipable.clip_width)
      	{
      	  cpt += (pix->clipable.clip_width * (resize - 1)) + resize;
      	  savey += resize;
      	}
      else
	cpt += resize;
      i++;
    }
}
