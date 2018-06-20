/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keycode_partwo.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 11:11:59 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 11:14:11 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_switch(int key, t_env *f)
{
	if (key == ONE)
		f->frac.type = 1;
	else if (key == TWO)
		f->frac.type = 2;
	else if (key == THREE)
		f->frac.type = 3;
	else if (key == FOUR)
		f->frac.type = 4;
	else if (key == FIVE)
		f->frac.type = 5;
	else if (key == SIX)
		f->frac.type = 6;
	else if (key == SEVEN)
		f->frac.type = 7;
	else if (key == EIGHT)
		f->frac.type = 8;
	else if (key == NINE)
		f->frac.type = 9;
	ft_reset(f);
}
