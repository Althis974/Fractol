/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trace.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 16:45:29 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:01:58 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Tracing
*/

void	*ft_trace(void *th)
{
	t_env		*f;
	int			x;
	int			y;

	f = (t_env *)th;
	y = 0;
	while (y < MAX_H)
	{
		x = MAX_W * f->th / THREADS;
		while (x < MAX_W * (f->th + 1) / THREADS)
		{
			if (f->frac.type == 1)
				f->mlx.color = ft_color(ft_julia(f, x, y), f);
			else if (f->frac.type == 2)
				f->mlx.color = ft_color(ft_mandel(f, x, y), f);
			else if (f->frac.type == 3)
				f->mlx.color = ft_color(ft_tricorn(f, x, y), f);
			else if (f->frac.type > 3 && f->frac.type < NB_FRAC)
				ft_trace_next(f, x, y);
			ft_set_pixel(f, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

int		ft_trace_next(t_env *f, int x, int y)
{
	if (f->frac.type == 4)
		f->mlx.color = ft_color(ft_sauron(f, x, y), f);
	else if (f->frac.type == 5)
		f->mlx.color = ft_color(ft_newton(f, x, y), f);
	else if (f->frac.type == 6)
		f->mlx.color = ft_color(ft_burning(f, x, y), f);
	else if (f->frac.type == 7)
		f->mlx.color = ft_color(ft_clover(f, x, y), f);
	else if (f->frac.type == 8)
		f->mlx.color = ft_color(ft_dragon(f, x, y), f);
	return (0);
}
