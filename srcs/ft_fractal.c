/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fractal.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 11:05:23 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 16:07:00 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_julia(t_env *f, int x, int y)
{
	int			nb_iter;
	double		tmp;

	nb_iter = -1;
	f->frac.real = MINX + ((double)x * (MAXX - MINX) / MAX_LEN);
	f->frac.img = MINY + ((double)y * (MAXY - MINY) / MAX_WID);
	while (++nb_iter < f->frac.max_iter && (f->frac.real * f->frac.real +
				f->frac.img * f->frac.img) < 4)
	{
		tmp = f->frac.real;
		f->frac.real = f->frac.real * f->frac.real - f->frac.img * f->frac.img
			+ f->frac.constr;
		f->frac.img = 2 * f->frac.img * tmp + f->frac.consti;
	}
	return (nb_iter);
}

int		ft_mandel(t_env *f, int x, int y)
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
		f->frac.img = f->frac.man * f->frac.img * tmp + f->frac.consti;
	}
	return (nb_iter);
}

int		ft_tricorn(t_env *f, int x, int y)
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
		f->frac.img = -f->frac.man * f->frac.img * tmp + f->frac.consti;
	}
	return (nb_iter);
}

int		ft_sauron(t_env *f, int x, int y)
{
	int			nb_iter;

	nb_iter = -1;
	f->frac.real = 0.0;
	f->frac.img = 0.0;
	if (!f->mouse.on)
		f->frac.man = 12.0;
	f->frac.constr = MINX + ((double)x * (MAXX - MINX) / MAX_LEN);
	f->frac.consti = MINY + ((double)y * (MAXY - MINY) / MAX_WID);
	while (++nb_iter < f->frac.max_iter && (f->frac.real * f->frac.real +
				f->frac.img * f->frac.img) < 4)
	{
		f->frac.real = -2 * f->frac.real * f->frac.real + f->frac.constr;
		f->frac.img = f->frac.man * f->frac.img * f->frac.real + f->frac.consti;
	}
	return (nb_iter);
}

int		ft_newton(t_env *f, int x, int y)
{
	int			nb_iter;
	double		tmp;
	double		oldr;
	double		oldi;

	tmp = 1.0;
	nb_iter = -1;
	f->frac.constr = MINX + ((double)x * (MAXX - MINX) / MAX_LEN);
	f->frac.consti = MINY + ((double)y * (MAXY - MINY) / MAX_WID);
	f->frac.real = f->frac.constr;
	f->frac.img = f->frac.consti;
	while (++nb_iter < f->frac.max_iter && tmp > 0.000001)
	{
		oldr = f->frac.real;
		oldi = f->frac.img;
		tmp = (f->frac.real * f->frac.real + f->frac.img * f->frac.img)
				* (f->frac.real * f->frac.real + f->frac.img * f->frac.img);
		f->frac.real = (f->frac.man * f->frac.real * tmp + f->frac.real
				* f->frac.real - f->frac.img * f->frac.img) / (3.0 * tmp);
		f->frac.img = (f->frac.man * f->frac.img * (tmp - f->frac.real))
			/ (3.0 * tmp);
		tmp = (f->frac.real - oldr) * (f->frac.real - oldr) +
				(f->frac.img - oldi) * (f->frac.img - oldi);
	}
	return (nb_iter);
}
