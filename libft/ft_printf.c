/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:17:35 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 11:59:20 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_struct(t_data *data)
{
	data->l = FALSE;
	data->ll = FALSE;
	data->h = FALSE;
	data->hh = FALSE;
	data->j = FALSE;
	data->z = FALSE;
	data->sharp = FALSE;
	data->moins = FALSE;
}

static void	init_struct(va_list *ap, t_data *data, char const *format)
{
	int i;

	i = -1;
	reset_struct(data);
	data->ap = ap;
	data->len_frmt = ft_strlen(format);
	data->ret = 0;
	data->index = 0;
	data->frmt = ft_strnew(sizeof(char) * (data->len_frmt + 1));
	while (format[++i])
		data->frmt[i] = format[i];
	data->frmt[i] = '\0';
}

int			ft_printf(char const *format, ...)
{
	va_list	ap;
	t_data	data;

	va_start(ap, format);
	init_struct(&ap, &data, format);
	while (data.frmt[data.index])
	{
		color_parser(&data);
		if (data.frmt[data.index] == '%')
		{
			parser(&data);
			free(data.cnv);
		}
		else
		{
			ft_putchar(data.frmt[data.index]);
			data.ret++;
		}
		if (!data.frmt[data.index])
			break ;
		data.index++;
	}
	va_end(ap);
	free(data.frmt);
	return (data.ret);
}
