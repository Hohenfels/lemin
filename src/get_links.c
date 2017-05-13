/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:41:28 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/13 23:09:45 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_link	*create_link(t_room *room)
{
	t_link	*link;

	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
		return (NULL);
	link->room = room;
	link->next = NULL;
	return (link);
}

void	fill_link(t_room *r1, t_room *r2)
{
	t_link	*link;

	if ((link = r2->link) == NULL)
	{
		r2->link = create_link(r1);
		return ;
	}
	while (link->next != NULL)
		link = link->next;
	link->next = create_link(r1);
}

void	get_links(t_env *env)
{
	t_pipe	*pipe;

	pipe = env->pipes;
	while (pipe)
	{
		fill_link(pipe->room_a, pipe->room_b);
		fill_link(pipe->room_b, pipe->room_a);
		pipe = pipe->next;
	}
}
