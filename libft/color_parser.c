/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:35:05 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:21 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		choose_color(t_data *data, int i)
{
	if (!ft_strncmp(&data->frmt[data->index], "{:red}", i))
	{
		ft_putstr(RED);
		return (6);
	}
	else if (!ft_strncmp(&data->frmt[data->index], "{:yellow}", i))
	{
		ft_putstr(YELLOW);
		return (9);
	}
	else if (!ft_strncmp(&data->frmt[data->index], "{:blue}", i))
	{
		ft_putstr(BLUE);
		return (8);
	}
	else if (!ft_strncmp(&data->frmt[data->index], "{:reset}", i))
	{
		ft_putstr(RESET);
		return (8);
	}
	else
		return (0);
}

void	color_parser(t_data *data)
{
	int i;
	int j;

	if (data->frmt[data->index] == '{'
			&& data->frmt[data->index + 1] == ':')
	{
		j = data->index;
		i = 0;
		while (data->frmt[j] != '}')
		{
			i++;
			j++;
		}
		data->index += choose_color(data, i);
	}
}
