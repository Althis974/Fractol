/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wcharlen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 14:16:54 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:01:58 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(wchar_t c)
{
	size_t i;

	i = 0;
	if (MB_CUR_MAX == 1 && (c >= 127) && (c <= 255))
		i++;
	else if (c <= 0x7F)
		i++;
	else if (c <= 0x7FF)
		i += 2;
	else if (c <= 0xFFFF)
		i += 3;
	else if (c <= 0x10FFFF)
		i += 4;
	return (i);
}
