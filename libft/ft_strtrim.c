/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:03:07 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/10 15:59:56 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	k = 0;
	while (i <= j)
	{
		tmp[k] = s[i];
		i++;
		k++;
	}
	tmp[k] = '\0';
	return (tmp);
}
