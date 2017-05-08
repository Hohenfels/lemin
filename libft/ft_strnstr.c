/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:19:55 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/16 11:04:53 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;

	i = 0;
	if ((*little == '\0' || ft_isspace(*little == 1)))
		return ((char *)big);
	while (big[i] && (size_t)i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && (size_t)i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
