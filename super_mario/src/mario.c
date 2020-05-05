/*
** mario.c for mario in
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Mon Feb 29 18:10:45 2016 Tekm
** Last update Mon Mar 14 13:55:27 2016 Tekm
*/

#include		"../include/mario.h"

int			check_pos(t_struct *data)
{
  t_color		curcol;
  int			i;

  i = 0;
  curcol = getpixel(data->map, data->pos);
  if (data->tmpcol.full == curcol.full)
    i = 1;
  else
    {
      if (data->dir == 'j')
	data->dir = 'r';
      else if (data->dir == 'k')
	data->dir = 'l';
    }
  return (i);
}

int			check_rght(t_struct *data)
{
  data->pos->x = data->player.x + data->marior->clipable.clip_width + 1 - data->fen.x;
  data->pos->y = data->player.y;
  while (data->pos->y != data->player.y + data->marior->clipable.clip_height - 1)
    {
      if (check_pos(data) == 0)
	return (1);
      data->pos->y += 1;
    }
  return (0);
}

int			check_lft(t_struct *data)
{
  data->pos->x = data->player.x - data->fen.x - 5;
  data->pos->y = data->player.y;
  while (data->pos->y != data->player.y + data->marior->clipable.clip_height - 1)
    {
      if (check_pos(data) == 0)
	return (1);
      data->pos->y += 1;
    }
  return (0);
}

int			check_grnd(t_struct *data)
{
  int		cpt = 0;

  data->pos->x = data->player.x + - data->fen.x;
  data->pos->y = data->player.y + data->marior->clipable.clip_height + 1;
  while (data->pos->x != data->marior->clipable.clip_width + data->player.x - data->fen.x - 1)
    {
      while (cpt < 15)
	{
	  if (check_pos(data) == 0)
	    return (1);
	  data->pos->x += 1;
	  cpt++;
	}
    }
  return (0);
}

void			go_right(t_struct *data)
{
  if (check_rght(data) == 0)
    {
      if (data->player.x > data->win->buffer.width / 2
	  && data->fen.x > data->win->buffer.width - data->map->clipable.clip_width)
	data->fen.x -= 2;
      else
	data->player.x += 2;
    }
  if (data->pwhere == 0 && data->keyj == 'z')
    data->dir = 'r';
  else
    data->dir = 'j';
}

void			go_left(t_struct *data)
{
  if (check_lft(data) == 0)
    {
      if (data->player.x < data->win->buffer.width / 2 && data->fen.x != 0)
	data->fen.x += 2;
      else
	data->player.x -= 2;
    }
  if (data->pwhere == 0 && data->keyj == 'z')
    data->dir = 'l';
  else
    data->dir = 'k';
}

void			go_up(t_struct *data)
{
  static int		cpt = 0;

  if (data->pwhere == 0 && data->up == 0 && data->player.y > 0)
    {
      if (data->dir == 'r')
	data->dir = 'j';
      else if (data->dir == 'l')
	data->dir = 'k';
      bunny_sound_play(&data->jump->sound);
      cpt = data->player.y - 80;
      data->player.y -= 2;
      data->up = 1;
    }
  else
    {
      if (data->player.y > cpt && data->player.y > 0)
	data->player.y -= 2;
      else
	data->up = 0;
    }
}

t_bunny_response        key(t_bunny_event_state state,
			    t_bunny_keysym key, t_struct *data)
{
  if (((bunny_get_keyboard())[BKS_RIGHT]) || data->keyr == 'r')
    {
      if (((bunny_get_keyboard())[BKS_RIGHT]) || state == GO_DOWN)
	data->keyr = 'r';
      else
	data->keyr = 'z';
    }
  if (((bunny_get_keyboard())[BKS_LEFT]) || data->keyl == 'l')
    {
      if (((bunny_get_keyboard())[BKS_LEFT]) || state == GO_DOWN)
	data->keyl = 'l';
      else
	data->keyl = 'z';
    }
  if (((bunny_get_keyboard())[BKS_UP]) || data->keyj == 'j')
    {
      if (data->pwhere == 0 && (((bunny_get_keyboard())[BKS_UP]) || state == GO_DOWN))
	data->keyj = 'j';
      else
	data->keyj = 'z';
    }
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void			game_over(t_struct *data)
{
  data->fen.x = -140;
  data->fen.y = -120;
  bunny_sound_stop(&data->music->sound);
  bunny_sound_play(&data->effect->sound);
  bunny_blit(&data->win->buffer, &data->over->clipable, &data->fen);
  bunny_display(data->win);
  sleep(3.5);
  bunny_sound_stop(&data->effect->sound);
  bunny_sound_play(&data->music->sound);
  data->player.x = 100;
  data->player.y = data->win->buffer.height - 64;
  data->fen.x = 0;
  data->fen.y = 0;
}

void			go_game(t_struct *data)
{
  if (check_grnd(data) == 0 && data->up == 0)
    {
      data->player.y += 2;
      data->pwhere = 1;
    }
  else
    data->pwhere = 0;
  bunny_blit(&data->win->buffer, &data->map->clipable, &data->fen);
  if (data->keyr == 'r')
    go_right(data);
  if (data->keyl == 'l')
    go_left(data);
  if (data->keyj == 'j' || data->up == 1)
    go_up(data);
  if (data->dir == 'r')
    bunny_blit(&data->win->buffer, &data->marior->clipable, &data->player);
  else if (data->dir == 'l')
    bunny_blit(&data->win->buffer, &data->mariol->clipable, &data->player);
  else if (data->dir == 'j')
    bunny_blit(&data->win->buffer, &data->mariojr->clipable, &data->player);
  else if (data->dir == 'k')
    bunny_blit(&data->win->buffer, &data->mariojl->clipable, &data->player);
  bunny_display(data->win);
}

t_bunny_response	mainloop(t_struct *data)
{
  if ((data->player.y + data->marior->clipable.clip_height + 1) >= data->win->buffer.height)
    game_over(data);
  else
    go_game(data);
  return (GO_ON);
}

void			init_value(t_struct *data, t_color curcol)
{
  data->tmp = bunny_load_pixelarray("mariol.png");
  data->tmp->clipable.scale.x = 18;
  data->tmp->clipable.scale.y = 18;
  tekblit(data->mariol, data->tmp, data->pos);
  tekcoldel(data->mariol, &curcol, &data->tmpcol);
  data->tmp = bunny_load_pixelarray("mariojl.png");
  data->mariojl = bunny_new_pixelarray(data->tmp->clipable.clip_width / 18,
				       data->tmp->clipable.clip_height / 18);
  data->mariojr = bunny_new_pixelarray(data->tmp->clipable.clip_width / 18,
				       data->tmp->clipable.clip_height / 18);
  data->tmp->clipable.scale.x = 18;
  data->tmp->clipable.scale.y = 18;
  tekblit(data->mariojl, data->tmp, data->pos);
  tekcoldel(data->mariojl, &curcol, &data->tmpcol);
  data->tmp = bunny_load_pixelarray("mariojr.png");
  data->tmp->clipable.scale.x = 18;
  data->tmp->clipable.scale.y = 18;
  tekblit(data->mariojr, data->tmp, data->pos);
  tekcoldel(data->mariojr, &curcol, &data->tmpcol);
  data->over = bunny_load_pixelarray("over.png");
  data->effect = bunny_load_music("over.ogg");
  data->music = bunny_load_music("music_nmario.ogg");
  bunny_sound_play(&data->music->sound);
  data->player.x = 100;
  data->player.y = data->win->buffer.height - 65;
}

void			init_values(t_struct *data, char *map)
{
  t_color		curcol;

  data->fen.x = 0;
  data->fen.y = 0;
  data->dir = 'r';
  data->pos->x = 1;
  data->pos->y = 1;
  data->up = 0;
  data->map = bunny_load_pixelarray(map);
  data->tmpcol = getpixel(data->map, data->pos);
  data->win = bunny_start(SIZE_X, data->map->clipable.clip_height, false, "Mario");
  data->font = bunny_load_pixelarray("ascii.png");
  data->tmp = bunny_load_pixelarray("marior.png");
  data->marior = bunny_new_pixelarray(data->tmp->clipable.clip_width / 18,
				      data->tmp->clipable.clip_height / 18);
  data->mariol = bunny_new_pixelarray(data->tmp->clipable.clip_width / 18,
				      data->tmp->clipable.clip_height / 18);
  data->tmp->clipable.scale.x = 18;
  data->tmp->clipable.scale.y = 18;
  curcol = getpixel(data->tmp, data->pos);
  tekblit(data->marior, data->tmp, data->pos);
  tekcoldel(data->marior, &curcol, &data->tmpcol);
  data->jump = bunny_load_music("jump.ogg");
  bunny_sound_volume(&data->jump->sound, 15.00);
  init_value(data, curcol);
}

void			end_values(t_struct *data)
{
  bunny_delete_clipable(&data->map->clipable);
  bunny_delete_clipable(&data->marior->clipable);
  bunny_delete_clipable(&data->mariol->clipable);
  bunny_delete_clipable(&data->mariojr->clipable);
  bunny_delete_clipable(&data->mariojl->clipable);
  bunny_delete_clipable(&data->font->clipable);
  bunny_delete_clipable(&data->over->clipable);
  bunny_clear(&data->win->buffer, BLACK);
  bunny_sound_stop(&data->music->sound);
  bunny_sound_stop(&data->jump->sound);
  bunny_delete_sound(&data->music->sound);
  bunny_delete_sound(&data->effect->sound);
  bunny_delete_sound(&data->jump->sound);
  bunny_stop(data->win);
}

int                     main(int ac, char **av)
{
  t_struct		data;

  if (ac == 2)
    {
      init_values(&data, av[1]);
      set_max_heap_size(50);
      bunny_set_key_response((t_bunny_key)&key);
      bunny_set_loop_main_function((t_bunny_loop)mainloop);
      bunny_loop(data.win, 150, &data);
      end_values(&data);
    }
  else
    {
      printf("Usage: ./mario map\n");
      return (1);
    }
  return (0);
}
