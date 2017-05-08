/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:13:03 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/08 20:04:07 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		check_format(char *line)
{
	int		nb;
	char	*s_nb;

	nb = ft_atoi(line);
	s_nb = ft_itoa(nb);
	if (ft_strcmp(s_nb, line) == 0)
	{
		free(s_nb);
		return (-1);
	}
	free(s_nb);
	return (0);
}

int		check_int(char *str)
{
	int			n;
	char		*n_str;

	n = ft_atoi(str);
	n_str = ft_itoa(n);
	if (ft_strcmp(str, n_str))
	{
		free(n_str);
		return (0);
	}
	free(n_str);
	return (1);
}

void	free_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		++i;
	}
	array = NULL;
}
