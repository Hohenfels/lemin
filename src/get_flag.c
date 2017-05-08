/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:55:32 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/08 16:34:37 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/*
** 	Return values :
**
**		0 = Not a comment
**		1 = Is a comment
**		20 = Is unknown command
**		21 = Is start command
**		22 = Is end command
*/

int		which_one(char *line)
{
	if (ft_strcmp(line, "##start"))
		return (START);
	if (ft_strcmp(line, "##end"))
		return (END);
	return (UKNW);
}

int		get_flag(char *line)
{
	if (ft_strncmp(line, "#", 1) == 0)
	{
		if (ft_strncmp(line, "##", 2) == 0)
			return (which_one(line));
		return (IS);
	}
	return (NOT);
}
