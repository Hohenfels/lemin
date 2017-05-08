/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:07:17 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:25 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		inner(t_data *data, int s, int i)
{
	while (s == 0 && data->cnv[i] && data->cnv[i] != '.')
	{
		if (data->cnv[i] >= '0' && data->cnv[i] <= '9')
		{
			if (data->cnv[i] == '0' && data->moins == FALSE)
				data->c = '0';
			else
				s++;
			while (data->cnv[i + s] >= '0' && data->cnv[i + s] <= '9')
			{
				s++;
			}
		}
		i++;
	}
	return (s);
}

static int		deeper(t_data *data, int s, int i, char *str)
{
	while (s == 0 && data->cnv[i] && data->cnv[i] != '.')
	{
		if (data->cnv[i] >= '1' && data->cnv[i] <= '9')
		{
			str[s] = data->cnv[i];
			i++;
			s++;
			while (data->cnv[i] >= '0' && data->cnv[i] <= '9')
			{
				str[s] = data->cnv[i];
				i++;
				s++;
			}
		}
		i++;
	}
	str[s] = '\0';
	s = ft_atoi(str);
	return (s);
}

int				width_nb(t_data *data, long long int nb)
{
	int		i;
	int		s;
	char	*str;

	i = 0;
	s = 0;
	data->c = ' ';
	check_plus(data);
	if (nb < 0)
		data->plus = FALSE;
	check_moins(data);
	s = inner(data, s, i);
	str = ft_strnew(s);
	i = 0;
	s = 0;
	s = deeper(data, s, i, str);
	free(str);
	return (s);
}
