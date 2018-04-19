/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 09:44:06 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 10:51:56 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "keycode.h"
# include <pthread.h>
# define MAX_LEN 1000
# define MAX_WID 1000
# define MID_WID (MAX_WID / 2)
# define MINX f->mlx.minx
# define MINY f->mlx.miny
# define MAXX f->mlx.maxx
# define MAXY f->mlx.maxy
# define MOTION 6
# define NB_FRAC 10

typedef struct	s_col
{
	int			red;
	int			green;
	int			blue;
	int			val;
	int			sw1;
	int			sw2;
	double		coef;
}				t_col;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_tree
{
	int			iter;
	int			on;
	double		size1;
	double		size2;
	t_col		col;
}				t_tree;

typedef struct	s_mouse
{
	int			on;
	int			zoom;
	double		x;
	double		y;
}				t_mouse;

typedef struct	s_frac
{
	int			type;
	double		max_iter;
	double		freq;
	double		constr;
	double		consti;
	double		real;
	double		img;
	double		man;
	t_col		col;
	t_tree		tree;
}				t_frac;

typedef struct	s_img
{
	int			size_l;
	int			bpp;
	int			endian;
	char		*data;
	void		*img_ptr;
}				t_img;

typedef struct	s_mlx
{
	int			color;
	void		*mlx_ptr;
	void		*win;
	double		minx;
	double		miny;
	double		maxx;
	double		maxy;
	t_img		img;
}				t_mlx;

typedef struct	s_env
{
	t_frac		frac;
	t_mlx		mlx;
	t_mouse		mouse;
}				t_env;

/*
**  Initialize environment.
*/

int				ft_env_init(t_env *f);
int				ft_create(t_env *f);
void			ft_init_tree(t_env *f);
void			ft_initialization(t_env *f, int type);
void			ft_reset(t_env *f);

/*
**  Functions that take care of tracing.
*/

int				ft_trace(t_env *f);
int				ft_trace_next(t_env *f, int x, int y);
int				ft_color(int index, t_env *f);
void			ft_set_pixel(t_env *f, int x, int y);
void			ft_set_tree(t_env *f, int x, int y, int color);
void			ft_set_line(t_env *f, t_pos start, t_pos end);

/*
**  Functions of differents fractals.
*/

int				ft_julia(t_env *f, int x, int y);
int				ft_mandel(t_env *f, int x, int y);
int				ft_tricorn(t_env *f, int x, int y);
int				ft_sauron(t_env *f, int x, int y);
int				ft_newton(t_env *f, int x, int y);
int				ft_burning(t_env *f, int x, int y);
int				ft_clover(t_env *f, int x, int y);
int				ft_dragon(t_env *f, int x, int y);
void			ft_tree(t_env *f, t_pos tree, double angle, int iter);

/*
**  Functions that take care of events.
*/

int				ft_getting_keys(int key, t_env *f);
int				ft_motion(int x, int y, t_env *f);
int				ft_mouse(int button, int x, int y, t_env *f);
void			ft_zoom(t_env *f, double tmpx, double tmpy, int direction);
void			ft_moove(int key, t_env *f);
void			ft_iter(int key, t_env *f);
void			ft_rgb(int key, t_env *f);
void			ft_gradient(int key, t_env *f);
void			ft_launch(t_env *f);

/*
** Tried to implement multi-threading
**
** void     init_thread(t_env *f);
** void     *threaderize(void *th);
**
** typedef struct		s_th
**{
**	t_env			*f;
**	int				part;
**}                    t_th;
*/

#endif
