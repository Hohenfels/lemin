/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:35:58 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/09 12:22:46 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *d;
	char *s;
	char x;

	d = (char *)dest;
	s = (char *)src;
	x = (char)c;
	while (n)
	{
		*d = *s;
		if (*s == c)
			return ((void *)d + 1);
		s++;
		d++;
		n--;
	}
	return (NULL);
}
