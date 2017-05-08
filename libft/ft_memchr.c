/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:58:34 by frenaud           #+#    #+#             */
/*   Updated: 2016/12/12 14:18:49 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	d;
	int		i;

	str = (char *)s;
	d = (char)c;
	i = 0;
	while (n--)
	{
		if (str[i] == d)
			return (str + i);
		i++;
	}
	return (NULL);
}
