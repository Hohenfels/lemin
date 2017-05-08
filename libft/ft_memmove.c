/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:12:24 by frenaud           #+#    #+#             */
/*   Updated: 2016/12/06 15:54:45 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	if (dest < src)
		ft_memcpy(d, s, n);
	else
	{
		while (n)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
