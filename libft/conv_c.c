/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 21:29:04 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:10 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_c(t_data *data)
{
	int		c;
	int		s;
	char	x;

	x = ' ';
	c = va_arg(*data->ap, int);
	s = width_nb(data, 1);
	s = (s - 1);
	if (data->c == '0')
		x = '0';
	if (data->moins == TRUE)
	{
		data->ret += write(1, &c, 1);
		while (s-- > 0)
			data->ret += write(1, &x, 1);
	}
	else
	{
		while (s-- > 0)
			data->ret += write(1, &x, 1);
		data->ret += write(1, &c, 1);
	}
}

void	conv_lc(t_data *data)
{
	unsigned int c;

	c = va_arg(*data->ap, unsigned int);
	data->len_nb = ft_charwlen(c);
	data->ret += ft_putwchar(c);
}
