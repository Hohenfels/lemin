/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 12:56:56 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/08 12:05:59 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		get_ants(t_env *env, char *line)
{
	int		ants;
	char	*n_ants;

	ants = ft_atoi(line);
	n_ants = ft_itoa(ants);
	if (get_flag(line))
		return (0);
	if (ft_strcmp(line, n_ants) || ants <= 0)
	{
		free(n_ants);
		return (-1);
	}
	free(n_ants);
	env->ants = ants;
	return (1);
}
