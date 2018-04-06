/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fractal_partwo.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 14:31:41 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 16:11:09 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_burning(t_env *f, int x, int y)
{
	int			nb_iter;
	double		tmp;

	nb_iter = -1;
	f->frac.real = 0.0;
	f->frac.img = 0.0;
	f->frac.constr = MINX + ((double)x * (MAXX - MINX) / MAX_LEN);
	f->frac.consti = MINY + ((double)y * (MAXY - MINY) / MAX_WID);
	while (++nb_iter < f->frac.max_iter && (f->frac.real * f->frac.real +
				f->frac.img * f->frac.img) < 4)
	{
		tmp = f->frac.real;
		f->frac.real = f->frac.real * f->frac.real - f->frac.img * f->frac.img
			+ f->frac.constr;
		f->frac.img = f->frac.man * fabs(f->frac.img * tmp) + f->frac.consti;
	}
	return (nb_iter);
}

int		ft_clover(t_env *f, int x, int y)
{
	int			nb_iter;
	double		tmp;

	nb_iter = -1;
	f->frac.real = MINX + ((double)x * (MAXX - MINX) / MAX_LEN);
	f->frac.img = MINY + ((double)y * (MAXY - MINY) / MAX_WID);
	f->frac.constr = 0.285;
	f->frac.consti = 0.01;
	while (++nb_iter < f->frac.max_iter && (f->frac.real * f->frac.real +
				f->frac.img * f->frac.img) < 4)
	{
		tmp = f->frac.real;
		f->frac.real = fabs(f->frac.real * f->frac.real - f->frac.img
				* f->frac.img + f->frac.constr);
		f->frac.img = fabs(f->frac.man * f->frac.img * tmp + f->frac.consti);
	}
	return (nb_iter);
}

int		ft_dragon(t_env *f, int x, int y)
{
	int			nb_iter;
	double		tmp;

	nb_iter = -1;
	f->frac.real = 0.0;
	f->frac.img = 0.0;
	f->frac.constr = MINX + ((double)x * (MAXX - MINX) / MAX_LEN);
	f->frac.consti = MINY + ((double)y * (MAXY - MINY) / MAX_WID);
	while (++nb_iter < f->frac.max_iter && (f->frac.real * f->frac.real +
				f->frac.img * f->frac.img) < 4)
	{
		tmp = f->frac.real;
		f->frac.real = f->frac.real * f->frac.real * f->frac.real -
			(f->frac.man * 1.5 * f->frac.real * f->frac.img * f->frac.img)
			+ f->frac.constr;
		f->frac.img = (f->frac.man * 1.5 * tmp * tmp * f->frac.img)
			+ f->frac.consti;
	}
	return (nb_iter);
}

void	ft_tree(t_env *f, t_pos start, double angle, int iter)
{
	t_pos end;

	if (iter > 0)
	{
		end.x = start.x + (cos(angle) * iter * 6);
		end.y = start.y + (sin(angle) * iter * 9);
		f->mlx.color = ((f->frac.tree.col.red * iter) << f->frac.col.sw1)
			+ ((f->frac.tree.col.green * iter) << f->frac.col.sw2)
			+ (f->frac.tree.col.blue * iter);
		ft_set_line(f, start, end);
		ft_tree(f, end, angle - (M_PI / 8 * f->frac.tree.size1 * 2), iter - 1);
		ft_tree(f, end, angle + (M_PI / 8 * f->frac.tree.size2 * 2), iter - 1);
	}
}
