/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:54:53 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:04 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_d(t_data *data)
{
	long long int	nb;
	int				a;
	int				s;
	int				n;

	a = 0;
	nb = va_arg(*data->ap, long long int);
	while (nb > 2147483647)
		nb = (nb - 4294967296);
	n = nb;
	if (n > 0)
		check_plus(data);
	a = check_precision_int(data, (intmax_t)n);
	s = width_nb(data, (intmax_t)n);
	check_spaces(data);
	if (n > -1 && data->plus == FALSE && data->spaces == TRUE)
	{
		data->ret += write(1, " ", 1);
		s--;
	}
	print_d(data, s, a, n);
}

void	conv_hhd(t_data *data)
{
	signed char	c;
	short int	nb;

	if (data->hh == TRUE)
	{
		c = (signed char)va_arg(*data->ap, int);
		ft_putnbr((int)c);
		data->ret += ft_nblen((int)c);
	}
	else
	{
		nb = (short int)va_arg(*data->ap, int);
		if (nb > 0)
			check_plus(data);
		check_precision_int(data, nb);
		ft_putnbr(nb);
		data->ret += ft_nblen(nb);
	}
}

void	conv_lld(t_data *data)
{
	long long int	nb;
	long int		nb1;

	if (data->ll == TRUE)
	{
		nb = va_arg(*data->ap, long long int);
		if (nb > 0)
			check_plus(data);
		ft_putnbr_ll(nb);
		data->ret += ft_nblen_ll(nb);
	}
	else
	{
		nb1 = (long int)va_arg(*data->ap, long long int);
		if (nb1 > 0)
			check_plus(data);
		if (data->plus == TRUE)
			data->ret += write(1, "+", 1);
		ft_putnbr_ll(nb1);
		data->ret += ft_nblen_ll(nb1);
	}
}

void	conv_zd(t_data *data)
{
	ssize_t nb;

	nb = va_arg(*data->ap, ssize_t);
	if (nb > 0)
		check_plus(data);
	ft_putnbr_ll(nb);
	data->ret += ft_nblen_ll(nb);
}

void	conv_jd(t_data *data)
{
	long long nb;

	nb = (long long)va_arg(*data->ap, long long int);
	if (nb > 0)
		check_plus(data);
	ft_putnbr_ll(nb);
	data->ret += ft_nblen_ll(nb);
}
