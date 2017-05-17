/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:07:23 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/17 13:48:18 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_track	*new_tracks(t_room *room)
{
	t_track	*ret;

	if (!(ret = (t_track *)ft_memalloc(sizeof(t_track))))
		return (NULL);
	ret->room = room;
	ret->next = NULL;
	return (ret);
}

t_path	*new_paths(t_track *track, int size)
{
	t_path 	*ret;

	if (!(ret = (t_path *)ft_memalloc(sizeof(t_path))))
		return (NULL);
	ret->tracks = track;
	ret->size = size;
	ret->visited = 0;
	ret->next = NULL;
	return (ret);
}

int		get_size_link(t_link *link)
{
	int		i;

	i = 0;
	while (link)
	{
		++i;
		link = link->next;
	}
	return (i);
}

void	print_path(t_env *env)
{
	int		i;
	t_path 	*tmp;
	t_track *tmp2;

	tmp = env->final_path;
	i = 1;
	if (tmp == NULL)
	{
		error("NO PATHS");
		return ;
	}
	while (tmp != NULL)
	{
		tmp2 = tmp->tracks;
		ft_printf("Path [n.%d] | ", i);
		while (tmp2)
		{
			ft_putstr(tmp2->room->name);
			if (tmp2->next)
				ft_putstr(" -> ");
			tmp2 = tmp2->next;
		}
		ft_putstr("\n");
		++i;
		tmp = tmp->next;
	}
}
