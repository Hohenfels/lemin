/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:39:44 by frenaud           #+#    #+#             */
/*   Updated: 2017/01/25 19:40:31 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strwlen(int *str)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (str[++i])
		len += ft_charwlen(str[i]);
	return (len);
}
