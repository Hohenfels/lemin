/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:44:20 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/14 19:17:41 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t len;
	size_t i;
	size_t len_dest;
	size_t len_src;

	i = 0;
	len = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (n <= len_dest)
		return (n + len_src);
	while (dest[len] != '\0' && len < n)
		len++;
	while ((src[i] != '\0') && (i + len) < n - 1)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (len < n)
		dest[len + i] = 0;
	return (len + ft_strlen(src));
}
