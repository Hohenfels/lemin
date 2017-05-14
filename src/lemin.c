/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 20:03:22 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/14 21:54:28 by frenaud          ###   ########.fr       */
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
	(*env)->paths = NULL;
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

void	print_pat(t_env *env)
{
	int		i;
	t_path 	*tmp;
	t_track *tmp2;

	tmp = env->final_path;
	i = 1;
	if (tmp == NULL)
	{
		ft_putendl("NO PATHS");
		return ;
	}
	while (tmp != NULL)
	{
		tmp2 = tmp->tracks;
		ft_printf("Path [n.%d] | ", i);
		while (tmp2)
		{
			ft_putstr(tmp2->room->name);
			if (tmp2->next)
				ft_putstr(" -> ");
			tmp2 = tmp2->next;
		}
		ft_putstr("\n");
		++i;
		tmp = tmp->next;
	}
}

int			main(void)
{
	t_env 	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		error("Malloc error");
	env = parse_data();
	algo_this(env);
	print_pat(env);
}
