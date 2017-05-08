/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nblen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:51:27 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 11:59:56 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nblen(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = ft_nblen(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_nblen(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}

int		ft_nblen_ll(long long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		if (n == -9223372036854775807 - 1)
			return (20);
		n = -n;
		len = ft_nblen_ll(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_nblen_ll(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}

int		ft_nblen_l(long int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = ft_nblen_l(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_nblen_l(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}
