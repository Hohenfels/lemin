/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:42:31 by frenaud           #+#    #+#             */
/*   Updated: 2016/12/12 14:19:42 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
