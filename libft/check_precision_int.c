/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:43:19 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:33 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	inner(t_data *data, size_t k, long long int nb, int i)
{
	char	*str;
	int		s;

	str = ft_strnew(k);
	s = 0;
	while (data->cnv[i++] != '\0' && s == 0)
	{
		if (data->cnv[i] == '.')
		{
			i++;
			while (data->cnv[i] >= '0' && data->cnv[i] <= '9')
				str[s++] = data->cnv[i++];
		}
	}
	str[s] = '\0';
	s = ft_atoi(str);
	free(str);
	if (nb < 0)
		s++;
	i = 0;
	while (s-- > ft_nblen_l(nb))
		i++;
	return (i);
}

int			check_precision_int(t_data *data, long long int nb)
{
	int		i;
	size_t	k;

	i = 0;
	k = 0;
	while (data->cnv[i] != '\0' && k == 0)
	{
		if (data->cnv[i] == '.')
		{
			data->prec = TRUE;
			i++;
			while (data->cnv[i] >= '0' && data->cnv[i] <= '9')
			{
				i++;
				k++;
			}
		}
		i++;
	}
	i = 0;
	return (inner(data, k, nb, i));
}
