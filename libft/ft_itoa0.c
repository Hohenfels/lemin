/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:08:01 by jlasne            #+#    #+#             */
/*   Updated: 2017/05/08 12:09:28 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = n;
	len = ft_nblen_l(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		nbr = -nbr;
	while (len)
	{
		str[--len] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	if (str[len] == '0' && str[1] != '\0')
		str[len] = '-';
	return (str);
}
