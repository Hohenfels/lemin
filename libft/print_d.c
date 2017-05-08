/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 19:42:26 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 11:59:46 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		inner(t_data *data, int s, int a, long long int nb)
{
	if (data->plus == TRUE)
		data->ret += write(1, "+", 1);
	if (nb < 0)
	{
		data->ret += write(1, "-", 1);
		nb = -nb;
	}
	s = s + a;
	while (s > 0)
	{
		data->ret += write(1, "0", 1);
		s--;
	}
	if (a != -1)
	{
		ft_putnbr_l(nb);
		data->ret += ft_nblen_l(nb);
	}
}

static void		deeper_more(t_data *data, int s, int a, long long int nb)
{
	while (s > 0)
	{
		data->ret += write(1, " ", 1);
		s--;
	}
	if (data->plus == TRUE)
		data->ret += write(1, "+", 1);
	if (nb < 0)
	{
		data->ret += write(1, "-", 1);
		nb = -nb;
	}
	while (a > 0)
	{
		data->ret += write(1, "0", 1);
		a--;
	}
	if (a != -1)
	{
		ft_putnbr_l(nb);
		data->ret += ft_nblen_l(nb);
	}
}

static void		deeper(t_data *data, int s, int a, long long int nb)
{
	if (data->moins == TRUE)
	{
		if (data->plus == TRUE)
			data->ret += write(1, "+", 1);
		if (nb < 0)
		{
			data->ret += write(1, "-", 1);
			nb = -nb;
		}
		while (a > 0)
		{
			data->ret += write(1, "0", 1);
			a--;
		}
		if (a != -1)
		{
			ft_putnbr_l(nb);
			data->ret += ft_nblen_l(nb);
		}
		while (s-- > 0)
			data->ret += write(1, " ", 1);
	}
	else
		deeper_more(data, s, a, nb);
}

void			print_d(t_data *data, int s, int a, int nb)
{
	if (data->plus == TRUE)
		s--;
	s = (s - a - ft_nblen_l(nb));
	if (a == 0 && nb == 0 && data->prec == TRUE)
	{
		a = -1;
		s++;
	}
	if (data->prec == TRUE)
		data->c = ' ';
	if (data->c == '0')
		inner(data, s, a, nb);
	else
		deeper(data, s, a, nb);
}
