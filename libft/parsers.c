/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:57:04 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 11:59:51 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flag_other(t_data *data, int end)
{
	if (data->cnv[end - 1] == 'j')
		data->j = TRUE;
	if (data->cnv[end - 1] == 'z')
		data->z = TRUE;
}

static void	get_flag_util(t_data *data, int end)
{
	if (data->cnv[end - 1] == 'l')
		data->l = TRUE;
	if (data->cnv[end - 1] == 'h')
		data->h = TRUE;
}

static void	get_flag(t_data *data)
{
	int end;

	end = ft_strlen(data->cnv) - 1;
	if (end != 0)
		data->type = data->cnv[end];
	if (data->type != 'S' && data->type != 'D' && data->type != 'C' &&
			data->type != 'O' && data->type != 'U' && data->type != 'p')
	{
		if (data->cnv[end - 1] == 'l' || data->cnv[end - 1] == 'h')
		{
			if (data->cnv[end - 2] == 'l' || data->cnv[end - 2] == 'h')
			{
				if (data->cnv[end - 2] == 'l')
					data->ll = TRUE;
				if (data->cnv[end - 2] == 'h')
					data->hh = TRUE;
			}
			else
				get_flag_util(data, end);
		}
		else
			get_flag_other(data, end);
	}
}

static void	get_conv(t_data *data)
{
	int i;

	i = data->index + 1;
	while (data->frmt[i] != 's' && data->frmt[i] != 'S' &&
			data->frmt[i] != 'p' && data->frmt[i] != 'd' &&
			data->frmt[i] != 'D' && data->frmt[i] != 'i' &&
			data->frmt[i] != 'o' && data->frmt[i] != 'O' &&
			data->frmt[i] != 'u' && data->frmt[i] != 'U' &&
			data->frmt[i] != 'x' && data->frmt[i] != 'X' &&
			data->frmt[i] != 'c' && data->frmt[i] != 'C' &&
			data->frmt[i] != '%' && data->frmt[i] != 'r' &&
			data->frmt[i] != '\0')
		i++;
	if (data->frmt[i] == '\0')
		data->cnv = ft_strsub(data->frmt, data->index, 1);
	else
	{
		data->cnv = ft_strsub(data->frmt, data->index,
				i - data->index + 1);
		data->index = i;
	}
}

void		parser(t_data *data)
{
	get_conv(data);
	get_flag(data);
	if (data->l == TRUE)
		conv_l(data);
	else if (data->ll == TRUE)
		conv_ll(data);
	else if (data->h == TRUE || data->hh == TRUE)
		conv_h(data);
	else if (data->j == TRUE)
		conv_j(data);
	else if (data->z == TRUE)
		conv_z(data);
	else
		conv_basic(data);
	reset_struct(data);
}
