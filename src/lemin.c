/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 20:03:22 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/08 22:34:04 by frenaud          ###   ########.fr       */
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
		ft_putendl(line);
		if ((flag = (*parse[step])(env, line)) == 1)
			++step;
		else if (ft_strlen(line) == 0 || flag == -1)
			break;
	}
	return (env);
}

int			main(void)
{
	t_env 	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		error("Malloc error");
	env = parse_data();
	ft_putendl(env->start->name);
	ft_putendl(env->end->name);
}
