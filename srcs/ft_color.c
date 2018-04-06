/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 17:04:17 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 16:07:00 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_color(int nb_iter, t_env *f)
{
	if (nb_iter == f->frac.max_iter)
		return (0);
	f->frac.col.coef = f->frac.freq * (nb_iter + 1);
	f->frac.col.red = cos(f->frac.col.coef) * 64 + 128;
	f->frac.col.green = cos(f->frac.col.coef + f->frac.col.val) * 32 + 128;
	f->frac.col.blue = (cos(f->frac.col.coef + 2 * f->frac.col.val) * 16 + 128);
	return ((f->frac.col.red << f->frac.col.sw1) +
			(f->frac.col.blue << f->frac.col.sw2) + f->frac.col.green);
}
