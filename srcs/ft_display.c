/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <rlossy@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/13 10:41:36 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 14:51:20 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Head-Up Display
*/

void		ft_display(t_env *f)
{
	ft_header(f);
	if (!f->mouse.on)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 190, 0xe60000, "MOTION : OFF");
	else
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 190, 0x329932, "MOTION : ON");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 230, 0xffa500,
		"F1              : Change color");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 255, 0xffa500,
		"F2/F3           : Vary color shade");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 280, 0xffa500,
		"F5              : Reset");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 305, 0xffa500,
		"SCROLL / CLICK  : Zoom");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 330, 0xffa500,
		"^/</v/> W/A/S/D : Move fractal");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 355, 0xffa500,
		"R/G/B           : Change main color");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 380, 0xffa500,
		"M               : ON/OFF motion");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 405, 0xffa500,
		"+/-             : Vary iterations");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 430, 0xffa500,
		"ESC             : Exit");
	ft_fractals_list(f);
}

/*
**	Display header
*/

void		ft_header(t_env *f)
{
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 0, 0xffa500,
		"HHHHH   HHHHHUUUU   UUUUDDDDDD");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 11, 0xffa500,
		"H:::H   H:::HU::U   U::UD:::::DD");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 22, 0xffa500,
		"HH::H   H::HHUU:U   U:UUDDD:DDD:D");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 33, 0xffa500,
		"  H:H   H:H   U:U   U:U   D:D  D:D");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 44, 0xffa500,
		"  H::HHH::H   U:D   D:U   D:D   D:D");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 55, 0xffa500,
		"  H:::::::H   U:D   D:U   D:D   D:D");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 66, 0xffa500,
		"  H::HHH::H   U:D   D:U   D:D   D:D");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 77, 0xffa500,
		"  H:H   H:H   U::U U::U   D:D  D:D");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 88, 0xffa500,
		"HH::H   H::HH U:::U:::U DDD:DDD:D");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 99, 0xffa500,
		"H:::H   H:::H  UU:::UU  D:::::DD");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 110, 0xffa500,
		"HHHHH   HHHHH    UUU    DDDDDD");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1000, 150, 0xffa500,
		"________________________________________");
}

/*
**	Display fractals list
*/

void		ft_fractals_list(t_env *f)
{
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1000, 470, 0xffa500,
		"________________________________________");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 510, 0x800080,
		"   _   _   _   _   _   _   _   _  ");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 525, 0x800080,
		"  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ ");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 540, 0x800080,
		" ( F | r | a | c | t | a | l | s )");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1025, 555, 0x800080,
		"  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ ");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 595, 0x800080, "1: Julia");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 615, 0x800080, "2: Mandelbrot");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 635, 0x800080, "3: Tricorn");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 655, 0x800080, "4: Sauron");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 675, 0x800080, "5: Newton");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 695, 0x800080, "6: Burning_Ship");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 715, 0x800080, "7: Clover");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 735, 0x800080, "8: Dragon");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1140, 755, 0x800080, "9: Tree");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1000, 795, 0xffa500,
		"________________________________________");
	ft_fractals_infos(f);
}

/*
**	Display information about current fractal
*/

void		ft_fractals_infos(t_env *f)
{
	ft_footer(f);
	if (f->frac.type != 9)
	{
		f->s = ft_strjoin("Zoom : x", ft_ftoa(f->mouse.zoom), 2);
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1120, 922, 0x00FEDC, f->s);
		free(f->s);
		f->s = ft_strjoin("Iterations : ", ft_ftoa(f->frac.max_iter), 2);
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1120, 947, 0x00FEDC, f->s);
		free(f->s);
	}
	else
	{
		f->s = ft_strjoin("Iterations : ", ft_ftoa(f->frac.tree.iter), 2);
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1120, 947, 0x00FEDC, f->s);
		free(f->s);
	}
	if (f->frac.col.sw1 == 16 && f->frac.col.sw2 == 8)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1120, 972, 0x00FEDC,
			"Main color : RED");
	else if (f->frac.col.sw1 == 8 && f->frac.col.sw2 == 2)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1120, 972, 0x00FEDC,
			"Main color : GREEN");
	else if (f->frac.col.sw1 == 1 && f->frac.col.sw2 == 8)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1120, 972, 0x00FEDC,
			"Main color : BLUE");
}

/*
**	Display footer
*/

void		ft_footer(t_env *f)
{
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1130, 835, 0x00FEDC,
		"+-+-+-+-+-+-+-+");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1130, 846, 0x00FEDC,
		"|C|U|R|R|E|N|T|");
	PUT(f->mlx.mlx_ptr, f->mlx.win, 1130, 857, 0x00FEDC,
		"+-+-+-+-+-+-+-+");
	if (f->frac.type == 1)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Julia");
	else if (f->frac.type == 2)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Mandelbrot");
	else if (f->frac.type == 3)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Tricorn");
	else if (f->frac.type == 4)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Sauron");
	else if (f->frac.type == 5)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Newton");
	else if (f->frac.type == 6)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Burning_Ship");
	else if (f->frac.type == 7)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Clover");
	else if (f->frac.type == 8)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Dragon");
	else if (f->frac.type == 9)
		PUT(f->mlx.mlx_ptr, f->mlx.win, 1170, 897, 0x00FEDC, "Tree");
}
