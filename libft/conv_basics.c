/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:07:23 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:17 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_bis(t_data *data)
{
	if (data->type == 'O')
		conv_llo(data);
	else if (data->type == 'C')
		conv_lc(data);
	else if (data->type == 'S')
		conv_ls(data);
	else if (data->type == 'D')
		conv_lld(data);
	else if (data->type == 'U')
		conv_llu(data);
	else if (data->type == '%')
		conv_percent(data);
	else
		return ;
}

void		conv_basic(t_data *data)
{
	if (data->type == 's')
		conv_s(data);
	else if (data->type == 'd' || data->type == 'i')
		conv_d(data);
	else if (data->type == 'c')
		conv_c(data);
	else if (data->type == 'p')
		conv_p(data);
	else if (data->type == 'x' || data->type == 'X')
		conv_x(data);
	else if (data->type == 'u')
		conv_u(data);
	else if (data->type == 'o')
		conv_o(data);
	else
		conv_bis(data);
}
