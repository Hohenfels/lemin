/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:41:28 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/13 17:55:48 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_link	*add_link(t_room *room)
{
	t_link	*link;

	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
		return (NULL);
	link->room = room;
	link->next = NULL;
	return (link);
}

t_link	*fill_link(t_link *link, t_room *room)
{
	t_link	*ret;

	ret = link;
	if (ret == NULL)
		ret = add_link(room);
	else
	{
		ret->next = add_link(room);
	}
	return (ret);
}

t_link	*create_links(t_env *env, t_room *room)
{
	t_link	*link;
	t_pipe	*pipe;

	link = room->link;
	pipe = env->pipes;
	while (pipe)
	{
		if (ft_strcmp(pipe->room_a->name, room->name) == 0)
			link = fill_link(link, pipe->room_b);
		if (ft_strcmp(pipe->room_b->name, room->name) == 0)
			link = fill_link(link, pipe->room_a);
		pipe = pipe->next;
	}
	return (link);
}

void	get_links(t_env *env)
{
	t_room	*room;

	room = env->rooms;
	while (room)
	{
		room->link = create_links(env, room);
		room = room->next;
	}
}
