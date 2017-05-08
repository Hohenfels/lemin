/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 20:31:28 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 11:59:25 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ll(long long n)
{
	if (n == -9223372036854775807 - 1)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void	ft_putnbr_l(long int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_l(n / 10);
		ft_putnbr_l(n % 10);
	}
	else
		ft_putchar(n + 48);
}
