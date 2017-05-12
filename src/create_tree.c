/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:41:28 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/12 17:04:42 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_tree	*

t_tree	*create_tree(t_env *env)
{
	t_room	*room;
	t_tree	*tree;

	room = env->rooms;
	if (!(tree = (t_tree *)ft_memalloc(sizeof(t_tree))))
		return (NULL);
	tree->parent = NULL;
	while (room)
	{
		tree->room = room;
		tree->sons[i] = get_sons(env, tree, room);
		room = room->next;
	}
	return (tree);
}
