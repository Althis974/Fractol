/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 10:36:34 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:01:58 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_set_pixel(t_env *f, int x, int y)
{
	int		i;
	int		p;

	i = -1;
	p = x * (f->mlx.img.bpp / 8) + y * (f->mlx.img.size_l);
	while (++i < (f->mlx.img.bpp / 8))
	{
		f->mlx.img.data[p + i] = (char)f->mlx.color;
		f->mlx.color >>= 8;
	}
}

void	ft_set_line(t_env *f, t_pos start, t_pos end)
{
	double	x;
	double	y;
	double	dd;
	double	dx;
	double	dy;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
		ft_set_tree(f, x, y, f->mlx.color);
		x += dx;
		y += dy;
	}
}

void	ft_set_tree(t_env *f, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color) >> 16;
	g = (color) >> 8;
	b = (color);
	if (y >= 0 && x >= 0 && y < MAX_H && x < MAX_W)
	{
		f->mlx.img.data[(y * f->mlx.img.size_l)
			+ ((f->mlx.img.bpp / 8) * x) + 2] = (char)r;
		f->mlx.img.data[(y * f->mlx.img.size_l)
			+ ((f->mlx.img.bpp / 8) * x) + 1] = (char)g;
		f->mlx.img.data[(y * f->mlx.img.size_l)
			+ ((f->mlx.img.bpp / 8) * x)] = (char)b;
	}
}
