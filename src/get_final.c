/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:41:26 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/19 12:13:19 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			check_duplicate_room(t_path *p1, t_path *p2, char *sn, char *en)
{
	t_track		*tmp1;
	t_track		*tmp2;

	tmp1 = p1->tracks;
	while (tmp1)
	{
		tmp2 = p2->tracks;
		while (tmp2)
		{
			if (!ft_strcmp(tmp1->room->name, tmp2->room->name))
			{
				if (ft_strcmp(tmp1->room->name, sn)
					&& ft_strcmp(tmp1->room->name, en))
					return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int			check_duplicate_array(t_path *p, t_path **array, int size, t_env *env)
{
	int			i;
	t_path		*tmp;

	i = -1;
	tmp = array[0];
	while (++i < size)
	{
		if (array[i] == NULL)
			return (0);
		if (check_duplicate_room(p, array[i], env->start->name, env->end->name))
			return (1);
	}
	return (0);
}

void		reset_array(t_path **arr, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		arr[i] = NULL;
}

t_path		*create_new_paths(t_path **array, int size)
{
	int		i;
	t_path	*ret;
	t_path	*ret_fin;

	i = -1;
	while (++i < size)
	{
		if (i == 0)
		{
			ret = new_paths((array[i])->tracks, (array[i])->size);
			ret_fin = ret;
		}
		else
		{
			ret->next = new_paths((array[i])->tracks, (array[i])->size);
			ret = ret->next;
		}
	}
	return (ret_fin);
}

t_path		*get_final_paths(t_env *env, int max)
{
	t_path		*new_p[max];
	t_path		*tmp_p;
	int			i;

	i = 0;
	reset_array(new_p, max);
	if ((tmp_p = env->paths) == NULL || max == 0)
		return (NULL);
	while (i < max)
	{
		if (!check_duplicate_array(tmp_p, new_p, max, env))
			new_p[i++] = tmp_p;
		tmp_p = tmp_p->next;
		if (tmp_p == NULL)
		{
			if (i >= max)
				break ;
			tmp_p = (new_p[0])->next;
			if (tmp_p == NULL && --max > -1)
				tmp_p = env->paths;
			reset_array(new_p, max);
			i = 0;
		}
	}
	return (create_new_paths(new_p, max));
}
