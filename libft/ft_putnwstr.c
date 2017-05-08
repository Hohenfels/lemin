/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:39:14 by frenaud           #+#    #+#             */
/*   Updated: 2017/01/25 19:39:28 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnwstr(int *str, int len)
{
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	while (ret < len && str[++i])
		ret += ft_putnwchar(str[i], len - ret);
	return (ret);
}
