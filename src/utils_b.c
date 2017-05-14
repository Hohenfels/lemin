/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:07:23 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/14 21:23:43 by frenaud          ###   ########.fr       */
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
