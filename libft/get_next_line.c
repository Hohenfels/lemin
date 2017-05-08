/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:24:02 by frenaud           #+#    #+#             */
/*   Updated: 2017/01/05 10:50:17 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*init_list(int fd)
{
	t_gnl			*fresh;

	fresh = ft_memalloc(sizeof(t_gnl));
	fresh->fd = fd;
	fresh->save = NULL;
	fresh->next = NULL;
	return (fresh);
}

t_gnl	*new_list(t_gnl *list, int fd)
{
	t_gnl			*fresh;

	fresh = list;
	while (fresh && fresh->next)
		fresh = fresh->next;
	fresh->next = init_list(fd);
	return (fresh->next);
}

t_gnl	*get_fd(t_gnl *list, int fd)
{
	t_gnl			*temp;

	if (!list)
		list = init_list(fd);
	temp = list;
	while (temp && temp->next && temp->fd != fd)
		temp = temp->next;
	if (temp->fd != fd)
		temp = new_list(temp, fd);
	return (temp);
}

int		check_gnl(char *buff, char **save, char **line, int option)
{
	char			*tmp;

	if (option == 1)
	{
		if ((tmp = ft_strchr(*save, '\n')))
		{
			*tmp = '\0';
			*line = ft_strdup(*save);
			*save = ft_strdup(tmp + 1);
			return (1);
		}
	}
	if (option == 2)
	{
		if ((tmp = ft_strchr(buff, '\n')))
		{
			*tmp = '\0';
			*line = ft_strjoin_ultimate(*save, buff, 1);
			*save = ft_strdup(tmp + 1);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_gnl			*temp;
	static t_gnl	*list = NULL;

	if (!list && (list = get_fd(list, fd)))
		temp = list;
	else
		temp = get_fd(list, fd);
	if (temp->save && check_gnl(buff, &temp->save, line, 1))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (check_gnl(buff, &temp->save, line, 2))
			return (1);
		temp->save = ft_strjoin_ultimate(temp->save, buff, 1);
	}
	if (ret == -1)
		return (-1);
	if (temp->save == NULL || *temp->save == '\0')
		return (0);
	*line = ft_strdup(temp->save);
	ft_strdel(&temp->save);
	return (1);
}
