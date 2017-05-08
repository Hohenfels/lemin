/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 23:36:36 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:01:55 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hho(t_data *data)
{
	unsigned char		nb;
	short unsigned int	nb1;

	if (data->hh == TRUE)
	{
		nb = (unsigned char)va_arg(*data->ap, int);
		check_precision_int(data, nb);
		data->ret += ft_putstr(ft_itoa_base(nb, 8));
	}
	else
	{
		nb1 = (short unsigned int)va_arg(*data->ap, unsigned int);
		check_precision_int(data, nb1);
		data->ret += ft_putstr(ft_itoa_base(nb1, 8));
	}
}

void	conv_o(t_data *data)
{
	unsigned int	nb;
	int				a;
	int				s;
	unsigned int	nbh;
	char			*str;

	nb = va_arg(*data->ap, unsigned int);
	check_hashtag(data);
	str = ft_itoa_base(nb, 8);
	nbh = ft_atoi(str);
	a = check_precision_int(data, nbh);
	s = width_nb(data, nbh);
	free(str);
	print_o(data, s, a, nb);
}

void	conv_llo(t_data *data)
{
	long long unsigned int		nb;
	long unsigned int			nb1;

	if (data->ll == TRUE)
	{
		nb = va_arg(*data->ap, long long unsigned int);
		data->ret += ft_putstr(ft_itoa_base_ll(nb, 8));
	}
	else
	{
		nb1 = va_arg(*data->ap, long unsigned int);
		data->ret += ft_putstr(ft_itoa_base_ll(nb1, 8));
	}
}

void	conv_zo(t_data *data)
{
	ssize_t nb;

	nb = va_arg(*data->ap, ssize_t);
	data->ret += ft_putstr(ft_itoa_base_ll(nb, 8));
}

void	conv_jo(t_data *data)
{
	uintmax_t nb;

	nb = va_arg(*data->ap, uintmax_t);
	data->ret += ft_putstr(ft_itoa_base_ll(nb, 8));
}
