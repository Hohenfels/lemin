/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 20:03:22 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/12 15:56:28 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static void	init(t_env **env)
{
	(*env)->ants = 0;
	(*env)->start = NULL;
	(*env)->end = NULL;
	(*env)->rooms = NULL;
	(*env)->pipes = NULL;
}

t_env		*parse_data(void)
{
	int		flag;
	int		step;
	char 	*line;
	int 	(*parse[3]) (t_env *env, char *line);
	t_env	*env;

	step = 0;
	parse[0] = get_ants;
	parse[1] = get_rooms;
	parse[2] = get_pipes;
	init(&env);
	while ((get_next_line(0, &line) > 0))
	{
		if ((flag = (*parse[step])(env, line)) == 1)
			++step;
		else if (ft_strlen(line) == 0 || flag == -1)
			break;
	}
	return (env);
}

void		print_rooms(t_env *env)
{
	t_room *start;
	t_room *end;
	t_room *rooms;

	start = env->start;
	end = env->end;
	rooms = env->rooms;
	ft_printf("ROOMS :\n");
	while (rooms)
	{
		ft_printf("Name = %s\nX = %d\n\
Y = %d\n", rooms->name, rooms->x, rooms->y);
		rooms = rooms->next;
	}
	ft_printf("START : %s\nEND : %s\n", start->name, end->name);
}

void		print_pipes(t_env *env)
{
	t_pipe *pipes;

	pipes = env->pipes;
	while (pipes)
	{
		ft_putstr(pipes->room_a->name);
		ft_putchar('-');
		ft_putstr(pipes->room_b->name);
		ft_putendl("");
		pipes = pipes->next;
	}
}

int			main(void)
{
	t_env 	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		error("Malloc error");
	env = parse_data();
	env->tree = create_tree(env);
	print_rooms(env);
	print_pipes(env);
	ft_printf("%s\n", env->tree->room->name);
}
