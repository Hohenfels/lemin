/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 23:29:57 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:01:37 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hhu(t_data *data)
{
	unsigned char		c;
	unsigned short int	nb;
	char				*str;

	if (data->hh == TRUE)
	{
		c = (unsigned char)va_arg(*data->ap, int);
		str = ft_itoa_base(c, 10);
		data->ret += ft_putstr(str);
	}
	else
	{
		nb = (unsigned short int)va_arg(*data->ap, unsigned int);
		str = ft_itoa_base(nb, 10);
		data->ret += ft_putstr(str);
	}
	free(str);
}

void	conv_u(t_data *data)
{
	unsigned int	nb;
	int				a;
	int				s;

	nb = va_arg(*data->ap, unsigned int);
	a = check_precision_int(data, (intmax_t)nb);
	s = width_nb(data, (intmax_t)nb);
	print_u(data, s, a, nb);
}

void	conv_llu(t_data *data)
{
	unsigned long long int	nb;
	unsigned long int		nb1;
	char					*str;

	if (data->ll == TRUE)
	{
		nb = va_arg(*data->ap, unsigned long long int);
		str = ft_itoa_base_ll(nb, 10);
		data->ret += ft_putstr(str);
	}
	else
	{
		nb1 = va_arg(*data->ap, unsigned long int);
		str = ft_itoa_base_l(nb1, 10);
		data->ret += ft_putstr(str);
	}
	free(str);
}

void	conv_zu(t_data *data)
{
	unsigned long long	nb;
	char				*str;

	nb = (unsigned long long)va_arg(*data->ap, int);
	str = ft_itoa_base_ll(nb, 10);
	data->ret += ft_putstr(str);
	free(str);
}

void	conv_ju(t_data *data)
{
	uintmax_t	nb;
	char		*str;

	nb = va_arg(*data->ap, uintmax_t);
	str = ft_itoa_base_uint(nb, 10);
	data->ret += ft_putstr(str);
	free(str);
}
