/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_len.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 16:41:23 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 15:01:58 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_len(intmax_t val, int base)
{
	int len;

	len = 1;
	if (val < 0 && base == 10)
		len++;
	val = ft_abs(val);
	while (val /= base)
		len++;
	return (len);
}
