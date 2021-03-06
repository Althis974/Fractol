/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:36:54 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 12:03:15 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_mouse(int button, int x, int y, t_env *f)
{
	double tmpx;
	double tmpy;

	f->mouse.x = MINX + (double)x * (MAXX - MINX) / MAX_H;
	f->mouse.y = MINY + (double)y * (MAXY - MINY) / MAX_W;
	tmpx = MINX;
	tmpy = MINY;
	if (f->frac.type != 9)
	{
		if ((button == 1 || button == 4) && (x >= 0 && x <= MAX_W) &&
			(y >= 0 && y <= MAX_H) && !f->mouse.on)
			ft_zoom(f, tmpx, tmpy, 1);
		else if ((button == 2 || button == 5) && (x >= 0 && x <= MAX_W) &&
			(y >= 0 && y <= MAX_H) && !f->mouse.on && f->mouse.zoom)
			ft_zoom(f, tmpx, tmpy, 0);
	}
	ft_launch(f);
	return (0);
}

int		ft_motion(int x, int y, t_env *f)
{
	if (x >= 0 && x <= MAX_W && y >= 0 && y <= MAX_H && f->mouse.on
			&& (f->frac.type == 1))
	{
		f->frac.constr = MINX + ((x * MAXX) / MAX_H);
		f->frac.consti = MINY + ((y * MAXY) / MAX_W);
	}
	else if (x >= 0 && x <= MAX_W && y >= 0 && y <= MAX_H && f->mouse.on
			&& f->frac.type > 1 && f->frac.type <= 8)
		f->frac.man = MINX + ((x * MAXX) / MAX_W) - MINY
			+ ((y * MAXY) / MAX_H);
	else if (x >= 0 && x <= MAX_W && y >= 0 && y <= MAX_H && f->mouse.on
			&& (f->frac.type == 9))
	{
		f->frac.tree.size1 = (double)y / 600;
		f->frac.tree.size2 = (double)x / 600;
	}
	ft_launch(f);
	return (0);
}

void	ft_zoom(t_env *f, double tmpx, double tmpy, int direction)
{
	if (direction)
	{
		f->mouse.zoom++;
		MINX = f->mouse.x - (MAXX - MINX) / 4;
		MAXX = f->mouse.x + (MAXX - tmpx) / 4;
		MINY = f->mouse.y - (MAXY - MINY) / 4;
		MAXY = f->mouse.y + (MAXY - tmpy) / 4;
	}
	else
	{
		f->mouse.zoom--;
		MINX = f->mouse.x - (MAXX - MINX);
		MAXX = f->mouse.x + (MAXX - tmpx);
		MINY = f->mouse.y - (MAXY - MINY);
		MAXY = f->mouse.y + (MAXY - tmpy);
	}
}
