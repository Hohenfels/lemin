/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 11:53:59 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/14 22:57:12 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	swap_paths(t_path *p1, t_path *p2)
{
	int		t_size;
	t_track	*tmp;

	tmp = p1->tracks;
	t_size = p1->size;
	p1->tracks = p2->tracks;
	p1->size = p2->size;
	p2->tracks = tmp;
	p2->size = t_size;
}

int		sort_paths(t_env *env)
{
	int		i;
	int		nb;
	t_path	*tmp;

	i = 0;
	nb = 0;
	if (env->paths == NULL || env->paths->next == NULL)
		return (0);
	tmp = env->paths;
	while (tmp && ++nb > 0)
		tmp = tmp->next;
	while (++i < nb)
	{
		tmp = env->paths;
		while (tmp && tmp->next)
		{
			if (tmp->size > tmp->next->size)
				swap_paths(tmp, tmp->next);
			tmp = tmp->next;
		}
	}
	return (1);
}


void	algo_this(t_env *env)
{
	int		s_link;
	int		e_link;
	int		max;

	if (get_paths(env, NULL, env->start, NULL) == 1)
		return ;
	if (sort_paths(env) == 0)
		return;
	s_link = get_size_link(env->start->link);
	e_link = get_size_link(env->end->link);
	if (s_link < e_link)
		max = s_link;
	else
		max = e_link;
	env->final_path = get_final_paths(env, max);
}
