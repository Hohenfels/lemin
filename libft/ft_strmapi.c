/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:01:46 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/10 11:02:49 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(fresh = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[i])
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	return (fresh);
}
