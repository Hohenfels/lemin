/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:31:28 by frenaud           #+#    #+#             */
/*   Updated: 2017/04/20 15:52:14 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		itoa_len(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nbr;

	len = itoa_len(n);
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = nbr % 10 + '0';
	while (nbr /= 10)
	{
		len--;
		str[len] = nbr % 10 + '0';
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
