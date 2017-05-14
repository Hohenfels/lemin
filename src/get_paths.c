/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:01:49 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/15 00:38:40 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	path_to_env(t_env *env, t_track *new_path, int size)
{
	t_path		*tmp;

	if (env->paths == NULL)
		env->paths = new_paths(new_path, size);
	else
	{
		tmp = env->paths;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_paths(new_path, size);
	}
}

void	save_path(t_track *track_tmp, t_env *env)
{
	t_track		*new_path;
	t_track		*new_tmp;
	int			i;

	if (track_tmp == NULL || env == NULL)
		return ;
	new_path = NULL;
	new_tmp = NULL;
	i = 0;
	while (track_tmp)
	{
		++i;
		if (new_path == NULL)
		{
			new_path = new_tracks(track_tmp->room);
			new_tmp = new_path;
		}
		else
			new_tmp->next = new_tracks(track_tmp->room);
		track_tmp = track_tmp->next;
		if (new_tmp->next != NULL)
			new_tmp = new_tmp->next;
	}
	path_to_env(env, new_path, i);
}

int		is_already_inside(t_track *trail, t_room *room)
{
	t_track		*tmp;

	tmp = trail;
	if (tmp == NULL)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->room->name, room->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	cut_last(t_track *trail)
{
	t_track		*tmp;

	tmp = trail;
	if (tmp == NULL)
		return ;
	if (!tmp->next)
	{
		tmp->room = NULL;
		free(tmp);
		return ;
	}
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->room = NULL;
	free(tmp->next);
	tmp->next = NULL;
}

int		get_paths(t_env *env, t_track *trail, t_room *room, t_link *tmp2)
{
	t_track		*tmp;

	tmp = trail;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp == NULL)
		trail = new_tracks(room);
	else
		tmp->next = new_tracks(room);
	if (ft_strcmp(room->name, env->end->name) == 0)
	{
		save_path(trail, env);
		return (1);
	}
	tmp2 = room->link;
	while (tmp2)
	{
		if (is_already_inside(trail, tmp2->room) == 0)
		{
			get_paths(env, trail, tmp2->room, NULL);
			cut_last(trail);
		}
		tmp2 = tmp2->next;
	}
	return (0);
}
