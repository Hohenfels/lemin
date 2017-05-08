/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 14:58:04 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/08 22:33:41 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMMIN_H
# define LEMMIN_H

# include "../libft/libft.h"

#define NOT 0
#define IS 1
#define UKNW 20
#define START 21
#define END 22

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct	s_room	*next;

}					t_room;

typedef struct		s_pipe
{
	t_room 			*room_a;
	t_room			*room_b;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_env
{
	int				ants;
	t_room			*start;
	t_room			*end;
	t_room			*rooms;
	t_pipe			*pipes;
}					t_env;

int		get_ants(t_env *env, char *line);
int		get_rooms(t_env *env, char *line);
int		get_pipes(t_env *env, char *line);
int		get_flag(char *line);
int		check_format(char *line);
int		check_int(char *nb);
void	free_array(char **array);
void	error(char *str);

#endif
