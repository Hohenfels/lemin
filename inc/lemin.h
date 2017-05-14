/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 14:58:04 by frenaud           #+#    #+#             */
/*   Updated: 2017/05/14 21:25:18 by frenaud          ###   ########.fr       */
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
	int				w;
	int				x;
	int				y;
	struct	s_link	*link;
	struct	s_room	*next;

}					t_room;

typedef struct		s_link
{
	t_room			*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_track
{
	t_room			*room;
	struct s_track	*next;
}					t_track;

typedef struct		s_path
{
	t_track			*tracks;
	int				visited;
	int				size;
	struct s_path	*next;
}					t_path;

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
	t_path			*paths;
	t_path			*final_path;
}					t_env;

t_path	*get_final_paths(t_env *env, int max);
int		get_paths(t_env *env, t_track *trail, t_room *room, t_link *tmp2);
void	algo_this(t_env *env);
int		get_size_link(t_link *link);
t_path	*new_paths(t_track *track, int size);
t_track	*new_tracks(t_room *room);
void	get_links(t_env *env);
int		get_ants(t_env *env, char *line);
int		get_rooms(t_env *env, char *line);
int		get_pipes(t_env *env, char *line);
int		get_flag(char *line);
int		check_format(char *line);
int		check_int(char *nb);
void	free_array(char **array);
void	error(char *str);

#endif
