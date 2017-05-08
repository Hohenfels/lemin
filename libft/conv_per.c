/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_per.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 23:45:38 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:01:46 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_percent(t_data *data)
{
	int s;

	s = width_nb(data, 1);
	s = (s - 1);
	if (data->moins == TRUE)
	{
		data->ret += write(1, "%", 1);
		while (s > 0)
		{
			data->ret += write(1, " ", 1);
			s--;
		}
	}
	else
	{
		while (s > 0)
		{
			data->ret += write(1, " ", 1);
			s--;
		}
		data->ret += write(1, "%", 1);
	}
}
