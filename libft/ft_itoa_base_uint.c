/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 21:48:39 by frenaud           #+#    #+#             */
/*   Updated: 2017/01/29 21:48:42 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nblen_base_uint(uintmax_t n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long int)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base_uint(uintmax_t n, int base)
{
	int				len;
	char			*str;
	static char		tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (base > 16 || base <= 1)
		return (NULL);
	len = ft_nblen_base_uint(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len)
	{
		str[--len] = tab[n % base];
		n = n / base;
	}
	return (str);
}
