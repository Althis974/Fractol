/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 11:21:10 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 16:48:54 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_initialization(t_env *f, int type)
{
	f->mlx.minx = -3.2;
	f->mlx.miny = -3.2;
	f->mlx.maxx = 3.4;
	f->mlx.maxy = 3.4;
	f->frac.freq = 0.1;
	f->frac.max_iter = 16.0;
	f->frac.col.val = 2;
	f->frac.constr = -1.1380;
	f->frac.consti = 0.2403;
	f->frac.type = type;
	f->frac.col.sw1 = 16;
	f->frac.col.sw2 = 8;
	f->mouse.on = 0;
	f->frac.man = 2.0;
	f->mouse.x = 0.0;
	f->mouse.y = 0.0;
	f->mouse.zoom = 0;
	f->frac.tree.on = (f->frac.type == 9) ? 1 : 0;
}

void	ft_init_tree(t_env *f)
{
	f->frac.tree.iter = 10;
	f->frac.tree.size1 = 1;
	f->frac.tree.size2 = 1;
	f->frac.tree.col.red = 64;
	f->frac.tree.col.green = 32;
	f->frac.tree.col.blue = 16;
}

void	ft_reset(t_env *f)
{
	ft_initialization(f, f->frac.type);
	ft_init_tree(f);
}

int		main(int ac, char **av)
{
	t_env f;

	if (ac != 2 || ft_atoi(av[1]) < 1 || ft_atoi(av[1]) >= NB_FRAC)
	{
		write(2, "usage : ./fractol <fractal number>\n", 35);
		write(2, "1: Julia\n2: Mandelbrot\n3: Tricorn\n", 34);
		write(2, "4: Sauron\n5: Newton\n6: Burning_Ship\n", 36);
		write(2, "7: Clover\n8: Dragon\n9: Tree\n", 28);
		return (1);
	}
	ft_bzero(&f, sizeof(t_env));
	ft_initialization(&f, ft_atoi(av[1]));
	if (f.frac.tree.on)
		ft_init_tree(&f);
	ft_env_init(&f);
	free(&f);
	ft_bzero(&f, sizeof(t_env));
	return (0);
}
