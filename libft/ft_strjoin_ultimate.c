/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ultimate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:37:20 by frenaud           #+#    #+#             */
/*   Updated: 2016/12/20 19:20:45 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_ultimate(char *s1, char *s2, int option)
{
	char	*fresh;

	fresh = ft_strjoin(s1, s2);
	if (option == 1)
		free(s1);
	if (option == 2)
		free(s2);
	if (option == 3)
	{
		free(s1);
		free(s2);
	}
	return (fresh);
}
