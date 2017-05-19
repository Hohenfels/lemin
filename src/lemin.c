/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 20:03:22 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/19 15:48:14 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_env	*init(void)
{
	t_env *env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	env->ants = 0;
	env->start = NULL;
	env->end = NULL;
	env->rooms = NULL;
	env->pipes = NULL;
	env->paths = NULL;
	return (env);
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
	env = init();
	while ((get_next_line(0, &line) > 0))
	{
		ft_putendl(line);
		if ((flag = (*parse[step])(env, line)) == 1)
			++step;
		else if (ft_strlen(line) == 0 || flag == -1)
			break;
	}
	ft_putchar('\n');
	get_links(env);
	return (env);
}

void		manage_error(t_env *env)
{
	if (env == NULL)
		error("Error");
	else if (env->ants == 0)
		error("No ants found");
	else if (env->start == NULL || env->end == NULL)
		error("No start nor end");
	else if (env->rooms == NULL)
		error("No rooms");
	else if (env->pipes == NULL)
		error("No pipes");
}

void		print_links(t_env *env)
{
	t_link	*link;
	t_room 	*room;

	room = env->rooms;
	ft_printf("LINKS BETWEEN ROOMS\n\
----------------------------------\n");
	while (room)
	{
		link = room->link;
		ft_putstr("ROOM : ");
		ft_putendl(room->name);
		while (link)
		{
			ft_putstr(link->room->name);
			ft_putchar(' ');
			link = link->next;
		}
		room = room->next;
		ft_putchar('\n');
	}
}

int			main(void)
{
	t_env 	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		error("Malloc error");
	env = parse_data();
	manage_error(env);
	algo_this(env);
	print_path(env);
	ants_march(env);
	return (0);
}
