/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:17:42 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/14 15:15:48 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(fresh = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[i])
	{
		fresh[i] = f(s[i]);
		i++;
	}
	return (fresh);
}
