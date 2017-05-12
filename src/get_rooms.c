/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:45:07 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/12 14:04:33 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_room	*create_room(char **array)
{
	t_room	*room;

	room = (t_room *)ft_memalloc(sizeof(t_room));
	room->name = ft_strdup(array[0]);
	room->x = ft_atoi(array[1]);
	room->y = ft_atoi(array[2]);
	room->next = NULL;
	return (room);
}

int		room_to_env(t_env *env, t_room *room, int flag)
{
	t_room		*tmp;
	t_room		*tmp_b;

	if (flag == START)
		env->start = room;
	if (flag == END)
		env->end = room;
	if (env->rooms == NULL)
	{
		env->rooms = room;
		return (0);
	}
	tmp = env->rooms;
	while (tmp != NULL)
	{
		tmp_b = tmp;
		if (!ft_strcmp(tmp->name, room->name))
			return (-1);
		if (tmp->x == room->x && tmp->y == room->y)
			return (-1);
		tmp = tmp->next;
	}
	tmp_b->next = room;
return (0);
}

int		prepare_create(t_env *env, char *line, int flag)
{
	int			i;
	char		**array;
	t_room		*room;

	i = 0;
	array = ft_strsplit(line, ' ');
	while (array && array[i])
		i++;
	if (i != 3)
	{
		free_array(array);
		return (-1);
	}
	if (ft_strchr(array[0], '-') || ft_strchr(array[0], 'L'))
		return (-1);
	if (check_int(array[1]) == 0 || check_int(array[2]) == 0)
		return (-1);
	room = create_room(array);
	free_array(array);
	return (room_to_env(env, room, flag));
}

int		get_rooms(t_env *env, char *line)
{
	static int	flag = 0;
	int			last_flag;

	last_flag = flag;
	flag = get_flag(line);
	if (flag > 0)
	{
		if (flag > 20 && last_flag > 20)
			return (-1);
		if (last_flag > 20)
			flag = last_flag;
		if ((flag == START && env->start != NULL) ||
			(flag == END && env->end != NULL))
			return (-1);
		return (0);
	}
	if (get_pipes(env, line) == 0)
	{
		if (flag > 20)
			return (-1);
		return (1);
	}
	if (prepare_create(env, line, last_flag) == -1)
		return (-1);
	return (0);
}
