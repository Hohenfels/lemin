/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 00:01:18 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 11:59:33 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		str_itoa_free(t_data *data, long long int nb)
{
	char	*str;

	if (data->ll == TRUE)
		str = (ft_strlower(ft_itoa_base_ll(nb, 16)));
	else if (data->l == TRUE)
		str = (ft_strlower(ft_itoa_base_l(nb, 16)));
	else
		str = (ft_strlower(ft_itoa_base(nb, 16)));
	data->ret += ft_putstr(str);
	free(str);
}

static void		inner(t_data *data, int s, int a, long long int nb)
{
	if (data->sharp == TRUE)
		data->ret += write(1, "0x", 2);
	s = s + a;
	while (s-- > 0)
		data->ret += write(1, "0", 1);
	if (a != -1)
		str_itoa_free(data, nb);
}

static void		deeper_more(t_data *data, int s, int a, long long int nb)
{
	while (s > 0)
	{
		data->ret += write(1, " ", 1);
		s--;
	}
	while (a > 0)
	{
		data->ret += write(1, "0", 1);
		a--;
	}
	if (data->sharp == TRUE)
		data->ret += write(1, "0x", 2);
	if (a != -1)
		str_itoa_free(data, nb);
}

static void		deeper(t_data *data, int s, int a, long long int nb)
{
	if (data->moins == TRUE)
	{
		while (a > 0)
		{
			data->ret += write(1, "0", 1);
			a--;
		}
		if (data->sharp == TRUE)
			data->ret += write(1, "0x", 2);
		if (a != -1)
			str_itoa_free(data, nb);
		while (s-- > 0)
			data->ret += write(1, " ", 1);
	}
	else
		deeper_more(data, s, a, nb);
}

void			print_x(t_data *data, int s, int a, long long int nb)
{
	char	*str;

	str = ft_itoa_base(nb, 16);
	if (data->sharp == TRUE)
		s = (s - 2 - a - (ft_strlen(str)));
	else
		s = (s - a - (ft_strlen(str)));
	free(str);
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
