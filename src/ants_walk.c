/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_walk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:05:56 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/17 16:53:52 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_ant		*create_ant(int id)
{
	t_ant	*ant;

	ant = (t_ant *)malloc(sizeof(t_ant));
	ant->id = id;
	ant->cur_path = NULL;
	ant->cur_track = NULL;
	ant->next = NULL;
	return (ant);
}

int			ant_loop(t_path *path_it, t_path *cur)
{
	int			n;
	int			ret;

	n = cur->size - 1;
	ret = 0;
	while (path_it != cur)
	{
		ret += (n - (path_it->size - 2));
		path_it = path_it->next;
	}
	return (ret);
}

int			select_path(t_ant *ant, t_env *env)
{
	t_path		*path_it;
	int			ant_left;

	ant_left = env->ants - ant->id + 1;
	path_it = env->final_path;
	while (path_it && path_it->visited)
		path_it = path_it->next;
	if (path_it == NULL)
		return (0);
	if (ant_left <= ant_loop(env->final_path, path_it))
		return (0);
	ant->cur_path = path_it;
	ant->cur_track = path_it->tracks->next;
	path_it->visited = 1;
	ft_putstr("L");
	ft_putnbr(ant->id);
	ft_putstr("-");
	ft_putstr(ant->cur_track->room->name);
	ft_putstr(" ");
	return (1);
}

int			ants_step_foreward(t_ant *ants_save, t_ant *last_ant)
{
	t_ant		*tmp;
	int			ret;

	ret = 0;
	tmp = ants_save;
	ft_putstr("\n");
	while (tmp != last_ant)
	{
		tmp->cur_path->visited = 0;
		if (tmp->cur_track->next)
		{
			tmp->cur_track = tmp->cur_track->next;
			ret = 1;
			ft_putstr("L");
			ft_putnbr(tmp->id);
			ft_putstr("-");
			ft_putstr(tmp->cur_track->room->name);
			ft_putstr(" ");
		}
		tmp = tmp->next;
	}
	return (ret);
}

void		ants_march(t_env *env)
{
	int			i;
	t_ant		*ant;
	t_ant		*ant_save;

	i = 0;
	while (++i <= env->ants)
	{
		if (i == 1)
		{
			ant = create_ant(i);
			ant_save = ant;
		}
		else
		{
			ant->next = create_ant(i);
			ant = ant->next;
		}
		if (select_path(ant, env) == 0)
		{
			ants_step_foreward(ant_save, ant);
			select_path(ant, env);
		}
	}
	while (ants_step_foreward(ant_save, NULL))
		;
}
