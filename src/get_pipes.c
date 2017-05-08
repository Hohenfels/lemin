/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:26:57 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/08 20:07:43 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_pipe	*create_pipe(char *n1, char *n2, t_env *env)
{
	t_pipe		*pipe;
	t_room		*tmp;
	int			i;

	pipe = (t_pipe *)malloc(sizeof(t_pipe));
	tmp = env->rooms;
	i = 0;
	while (tmp != NULL && i != 2)
	{
		if (!ft_strcmp(tmp->name, n1) || !ft_strcmp(tmp->name, n2))
		{
			if (i == 0)
				pipe->room_a = tmp;
			else if (i == 1)
				pipe->room_b = tmp;
			++i;
		}
		tmp = tmp->next;
	}
	if (i != 2)
		return (NULL);
	pipe->next = NULL;
	return (pipe);
}

void	pipe_to_env(t_pipe *pipe, t_env *env)
{
	t_pipe		*tmp;
	t_pipe		*tmp2;

	if (env->pipes == NULL)
	{
		env->pipes = pipe;
		return ;
	}
	tmp = env->pipes;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		if ((!ft_strcmp(pipe->room_a->name, tmp->room_a->name)
			&& !ft_strcmp(pipe->room_b->name, tmp->room_b->name))
			|| (!ft_strcmp(pipe->room_a->name, tmp->room_b->name)
			&& !ft_strcmp(pipe->room_b->name, tmp->room_a->name)))
			return ;
		tmp = tmp->next;
	}
	tmp2->next = pipe;
	return ;
}

int		check_duplicate(char *name, t_env *env)
{
	t_room		*tmp;

	tmp = env->rooms;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		get_pipes(t_env *env, char *line)
{
	int			i;
	int			flag;
	t_pipe		*pipe;
	char		**array;

	if ((flag = get_flag(line)) > 1)
		return (flag);
	else if (flag == 1)
		return (0);
	array = ft_strsplit(line, '-');
	i = 0;
	while (array && array[i])
		i++;
	if (i != 2 || !check_duplicate(array[0], env)
		|| !check_duplicate(array[1], env))
	{
		free_array(array);
		return (-1);
	}
	pipe = create_pipe(array[0], array[1], env);
	pipe_to_env(pipe, env);
	free_array(array);
	return (0);
}
