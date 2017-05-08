/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:10:03 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:37 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_hashtag(t_data *data)
{
	int		i;

	i = 0;
	data->sharp = FALSE;
	while (data->cnv[i] != '\0' && data->cnv[i - 1] != '#')
	{
		if (data->cnv[i] == '#')
			data->sharp = TRUE;
		i++;
	}
}

void		check_spaces(t_data *data)
{
	int		i;

	i = 0;
	data->spaces = FALSE;
	while (data->cnv[i] != '\0' && data->cnv[i - 1] != ' ')
	{
		if (data->cnv[i] == ' ')
			data->spaces = TRUE;
		i++;
	}
}

void		check_moins(t_data *data)
{
	int i;

	i = 0;
	data->moins = FALSE;
	while (data->cnv[i] != '\0')
	{
		if (data->cnv[i] == '-')
			data->moins = TRUE;
		i++;
	}
}

void		check_plus(t_data *data)
{
	int		i;

	i = 0;
	data->plus = FALSE;
	while (data->cnv[i] != '\0' && data->cnv[i - 1] != '+')
	{
		if (data->cnv[i] == '+')
			data->plus = TRUE;
		i++;
	}
}
