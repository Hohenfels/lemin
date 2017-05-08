/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 12:58:22 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/06 16:14:19 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *tmp;

	tmp = str;
	tmp = tmp + ft_strlen(str);
	while (*tmp != (char)c && tmp != str)
		tmp--;
	if (*tmp == (char)c)
		return ((char *)tmp);
	return (NULL);
}
