/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 23:25:44 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:01:33 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hhx(t_data *data)
{
	unsigned char	nb;
	unsigned short	nb1;

	if (data->hh == TRUE)
	{
		nb = (unsigned char)va_arg(*data->ap, int);
		if (nb != 0)
			check_hashtag(data);
		if (data->type == 'x')
			data->ret += ft_putstr(ft_strlower(ft_itoa_base(nb, 16)));
		else
			data->ret += ft_putstr(ft_strcapitalize(ft_itoa_base(nb, 16)));
	}
	else
	{
		nb1 = (unsigned short)va_arg(*data->ap, int);
		if (nb1 != 0)
			check_hashtag(data);
		check_precision_int(data, nb1);
		if (data->type == 'x')
			data->ret += ft_putstr(ft_strlower(ft_itoa_base(nb1, 16)));
		else
			data->ret += ft_putstr(ft_strcapitalize(ft_itoa_base(nb1, 16)));
	}
}

void	conv_x(t_data *data)
{
	int nb;
	int	a;
	int s;

	nb = va_arg(*data->ap, int);
	if (nb != 0)
		check_hashtag(data);
	a = check_precision_int(data, nb);
	s = width_nb(data, nb);
	if (data->type == 'x')
		print_x(data, s, a, nb);
	else
		print_xx(data, s, a, nb);
}

void	conv_llx(t_data *data)
{
	long long int	nb;
	int				a;
	int				s;

	if (data->ll == TRUE)
		nb = va_arg(*data->ap, long long int);
	else
		nb = va_arg(*data->ap, long int);
	if (nb != 0)
		check_hashtag(data);
	a = check_precision_int(data, nb);
	s = width_nb(data, nb);
	if (data->type == 'x')
		print_x(data, s, a, nb);
	else
		print_xx(data, s, a, nb);
}

void	conv_zx(t_data *data)
{
	ssize_t nb;

	nb = va_arg(*data->ap, ssize_t);
	if (nb != 0)
		check_hashtag(data);
	check_precision_int(data, nb);
	if (data->type == 'x')
		data->ret += ft_putstr(ft_strlower(ft_itoa_base_ll(nb, 16)));
	else
		data->ret += ft_putstr(ft_strcapitalize(ft_itoa_base_ll(nb, 16)));
}

void	conv_jx(t_data *data)
{
	intmax_t nb;

	nb = va_arg(*data->ap, intmax_t);
	if (nb != 0)
		check_hashtag(data);
	check_precision_int(data, nb);
	if (data->type == 'x')
		data->ret += ft_putstr(ft_strlower(ft_itoa_base_ll(nb, 16)));
	else
		data->ret += ft_putstr(ft_strcapitalize(ft_itoa_base_ll(nb, 16)));
}
