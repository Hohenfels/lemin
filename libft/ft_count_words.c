/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:43:27 by frenaud           #+#    #+#             */
/*   Updated: 2016/11/16 11:02:51 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *str, char c)
{
	size_t word;

	word = 0;
	while (*str)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			word++;
		str++;
	}
	return (word);
}
