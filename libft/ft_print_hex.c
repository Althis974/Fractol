/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_hex.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 15:48:56 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:01:58 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(unsigned int n)
{
	char *hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
		ft_print_hex(n / 16);
	ft_putchar(hexa[n % 16]);
}
