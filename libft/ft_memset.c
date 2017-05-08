/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:45:17 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/09 17:20:22 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char *str;

	str = (char *)s;
	if (len == 0)
		return (s);
	while (len)
	{
		*str = (char)c;
		str++;
		len--;
	}
	return (s);
}
