/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:18:31 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/10 12:32:40 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (!s || start > (unsigned int)ft_strlen(s))
		return (NULL);
	if (!(fresh = ft_strnew(len)))
		return (0);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
