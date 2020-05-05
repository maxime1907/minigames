/*
** tekresize.c for tekresize in
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Mon Feb 29 19:33:26 2016 Tekm
** Last update Wed Mar  9 11:14:02 2016 Tekm
*/

#include <lapin.h>

void				tekblit(t_bunny_pixelarray *destination,
					const t_bunny_pixelarray *origin,
					const t_bunny_position *pos)
{
  int				saveyo;
  int				saveyd;
  int				cpt;
  int				i;

  (void)pos;
  i = 0;
  cpt = 0;
  saveyo = 0;
  saveyd = 0;
  while (cpt < origin->clipable.clip_width * origin->clipable.clip_height
	 && i < destination->clipable.clip_width * destination->clipable.clip_height)
    {
      ((t_color *)(destination->pixels))[i] = ((t_color *)(origin->pixels))[cpt];
      if (cpt - saveyo > origin->clipable.clip_width)
      	{
	  saveyo += origin->clipable.scale.y * origin->clipable.clip_width;
	  cpt = saveyo;
	  saveyd += destination->clipable.clip_width;
	  i = saveyd - 1;
	}
      else
	cpt += origin->clipable.scale.x;
      i++;
    }
}
