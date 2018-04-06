/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keycode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/21 16:22:50 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 16:38:42 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_getting_keys(int key, t_env *f)
{
	if (key == ESC)
		exit(0);
	else if (key == F5)
		ft_reset(f);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN
			|| key == A || key == D || key == W || key == S)
		ft_moove(key, f);
	else if (key == MORE || key == LESS)
		ft_iter(key, f);
	else if (key == R || key == G || key == B)
		ft_rgb(key, f);
	else if (key == F1 || key == F2 || key == F3)
		ft_gradient(key, f);
	else if (key == F4)
	{
		f->frac.type = ((++f->frac.type) < NB_FRAC) ? f->frac.type : 1;
		ft_reset(f);
	}
	else if (key == M)
		f->mouse.on = (f->mouse.on == 0) ? 1 : 0;
	ft_launch(f);
	return (0);
}

void	ft_moove(int key, t_env *f)
{
	if (key == LEFT || key == A)
	{
		MINX += ((MAXX - MINX) / MAX_LEN) * 15;
		MAXX += ((MAXX - MINX) / MAX_LEN) * 15;
	}
	else if (key == RIGHT || key == D)
	{
		MINX -= ((MAXX - MINX) / MAX_LEN) * 15;
		MAXX -= ((MAXX - MINX) / MAX_LEN) * 15;
	}
	else if (key == UP || key == W)
	{
		MINY += ((MAXX - MINX) / MAX_LEN) * 15;
		MAXY += ((MAXX - MINX) / MAX_LEN) * 15;
	}
	else if (key == DOWN || key == S)
	{
		MINY -= ((MAXX - MINX) / MAX_LEN) * 15;
		MAXY -= ((MAXX - MINX) / MAX_LEN) * 15;
	}
}

void	ft_iter(int key, t_env *f)
{
	if (key == MORE)
		f->frac.max_iter += 2.0;
	else if (key == LESS && f->frac.max_iter > 2)
		f->frac.max_iter -= 2.0;
}

void	ft_rgb(int key, t_env *f)
{
	if (key == R)
	{
		f->frac.col.sw1 = 16;
		f->frac.col.sw2 = 8;
	}
	else if (key == G)
	{
		f->frac.col.sw1 = 8;
		f->frac.col.sw2 = 2;
	}
	else if (key == B)
	{
		f->frac.col.sw1 = 1;
		f->frac.col.sw2 = 8;
	}
}

void	ft_gradient(int key, t_env *f)
{
	if (key == F1)
		f->frac.col.val++;
	else if (key == F3)
		f->frac.freq = (f->frac.freq < 210) ? f->frac.freq * 2 : f->frac.freq;
	else if (key == F2)
		f->frac.freq = (f->frac.freq > 0.1) ? f->frac.freq / 2 : f->frac.freq;
}
