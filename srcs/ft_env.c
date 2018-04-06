/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 12:11:11 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/05 16:48:53 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_env_init(t_env *f)
{
	f->mlx.mlx_ptr = mlx_init();
	f->mlx.win = mlx_new_window(f->mlx.mlx_ptr, MAX_LEN, MAX_WID, "Fractol");
	mlx_expose_hook(f->mlx.win, ft_create, f);
	mlx_hook(f->mlx.win, MOTION, 0, ft_motion, f);
	mlx_hook(f->mlx.win, 2, 0, ft_getting_keys, f);
	mlx_mouse_hook(f->mlx.win, ft_mouse, f);
	mlx_loop(f->mlx.mlx_ptr);
	return (0);
}

int		ft_create(t_env *f)
{
	t_pos start;

	start.x = MID_WID - (MAXX - MINX);
	start.y = (MAX_LEN / 1.5) - 20 + (MAXY - MINY);
	f->mlx.img.img_ptr = mlx_new_image(f->mlx.mlx_ptr, MAX_LEN, MAX_WID);
	f->mlx.img.data = mlx_get_data_addr(f->mlx.img.img_ptr, &f->mlx.img.bpp,
			&f->mlx.img.size_l, &f->mlx.img.endian);
	if (!f->frac.tree.on)
		ft_trace(f);
	else
		ft_tree(f, start, -(M_PI / 2), f->frac.tree.iter);
	mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win, f->mlx.img.img_ptr,
			0, 0);
	return (0);
}

void	ft_launch(t_env *f)
{
	mlx_destroy_image(f->mlx.mlx_ptr, f->mlx.img.img_ptr);
	mlx_clear_window(f->mlx.mlx_ptr, f->mlx.win);
	ft_create(f);
}
/*
** Tried to implement multi-threading
**
**void    init_thread(t_env *f)
**{
**	pthread_t	th[THREADS];
**	t_th       p[THREADS];
**	int			i;
**
**	i = -1;
**	while (++i < THREADS)
**	{
**		p[i].f = f;
**		p[i].part = i;
**		pthread_create(&th[i], NULL, threaderize, &p[i]);
**		pthread_join(th[i], NULL);
**	}
**	i = -1;
**	while (++i < THREADS)
**		pthread_join(th[i], NULL);
**}
**
**void		*threaderize(void *th)
**{
**	t_th			*p;
**
**	p = (t_th *)th;
**	ft_trace(p->f, p->part);
**	return (NULL);
**}
*/
