/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:18:34 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:01:42 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(t_data *data)
{
	char	*str;
	int		s;
	char	x;

	x = ' ';
	str = check_precision_str(data, va_arg(*data->ap, char *));
	if (!str)
		str = "(null)";
	s = width_nb(data, 1);
	s = (s - ft_strlen(str));
	if (data->c == '0')
		x = '0';
	if (data->moins == TRUE)
	{
		data->ret += ft_putstr(str);
		while (s-- > 0)
			data->ret += write(1, &x, 1);
	}
	else
	{
		while (s-- > 0)
			data->ret += write(1, &x, 1);
		data->ret += ft_putstr(str);
	}
}

void	conv_ls(t_data *data)
{
	int		*str;
	int		s;
	char	x;

	x = ' ';
	str = va_arg(*data->ap, int *);
	if (!str)
		str = L"(null)";
	s = width_nb(data, 1);
	s = (s - ft_strwlen(str));
	if (data->c == '0')
		x = '0';
	if (data->moins == TRUE)
	{
		data->ret += ft_putnwstr(str, ft_strwlen(str));
		while (s-- > 0)
			data->ret += write(1, &x, 1);
	}
	else
	{
		while (s-- > 0)
			data->ret += write(1, &x, 1);
		data->len_nb = ft_strwlen(str);
		data->ret += ft_putnwstr(str, data->len_nb);
	}
}
