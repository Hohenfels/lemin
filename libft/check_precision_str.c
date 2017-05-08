/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:53:28 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:29 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*inner(t_data *data, int digit, char *arg)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strnew(sizeof(char) * digit + 1);
	while (data->cnv[i++] && j == 0)
	{
		if (data->cnv[i] == '.')
		{
			i++;
			while (ft_isdigit(data->cnv[i]))
				str[j++] = data->cnv[i++];
		}
	}
	str[j] = '\0';
	j = ft_atoi(str);
	free(str);
	str = ft_strnew(j);
	ft_strncpy(str, arg, j);
	return (str);
}

char			*check_precision_str(t_data *data, char *arg)
{
	int		i;
	int		stop;
	size_t	digit;

	i = 0;
	stop = 0;
	digit = 0;
	while (data->cnv[i++] && stop == 0)
	{
		if (data->cnv[i] == '.')
		{
			stop = 1;
			i++;
			while (ft_isdigit(data->cnv[i]))
			{
				i++;
				digit++;
			}
		}
	}
	if (stop == 1)
		arg = inner(data, digit, arg);
	return (arg);
}
