/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:55:11 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 12:02:00 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_j(t_data *data)
{
	if ((data->type == 'd' || data->type == 'i') && data->j == TRUE)
		conv_jd(data);
	else if ((data->type == 'x' || data->type == 'X') && data->j == TRUE)
		conv_jx(data);
	else if (data->type == 'u' && data->j == TRUE)
		conv_ju(data);
	else if (data->type == 'o' && data->j == TRUE)
		conv_jo(data);
}

void	conv_z(t_data *data)
{
	if ((data->type == 'd' || data->type == 'i') && data->z == TRUE)
		conv_zd(data);
	else if ((data->type == 'x' || data->type == 'X') && data->z == TRUE)
		conv_zx(data);
	else if (data->type == 'u' && data->z == TRUE)
		conv_zu(data);
	else if (data->type == 'o' && data->z == TRUE)
		conv_zo(data);
}

void	conv_h(t_data *data)
{
	if (data->hh != TRUE)
	{
		if ((data->type == 'd' || data->type == 'i') && data->h == TRUE)
			conv_hhd(data);
		else if ((data->type == 'x' || data->type == 'X') && data->h == TRUE)
			conv_hhx(data);
		else if (data->type == 'u' && data->h == TRUE)
			conv_hhu(data);
		else if (data->type == 'o' && data->h == TRUE)
			conv_hho(data);
		else if (data->type == 'U' && data->h == TRUE)
			conv_hhu(data);
	}
	else
	{
		if ((data->type == 'd' || data->type == 'i') && data->hh == TRUE)
			conv_hhd(data);
		else if ((data->type == 'x' || data->type == 'X') && data->hh == TRUE)
			conv_hhx(data);
		else if (data->type == 'u' && data->hh == TRUE)
			conv_hhu(data);
		else if (data->type == 'o' && data->hh == TRUE)
			conv_hho(data);
	}
}

void	conv_ll(t_data *data)
{
	if ((data->type == 'd' || data->type == 'i') && data->ll == TRUE)
		conv_lld(data);
	else if ((data->type == 'x' || data->type == 'X') && data->ll == TRUE)
		conv_llx(data);
	else if (data->type == 'u' && data->ll == TRUE)
		conv_llu(data);
	else if (data->type == 'o' && data->ll == TRUE)
		conv_llo(data);
}

void	conv_l(t_data *data)
{
	if (data->type == 's' && data->l == TRUE)
		conv_ls(data);
	else if ((data->type == 'd' || data->type == 'i') && data->l == TRUE)
		conv_lld(data);
	else if (data->type == 'c' && data->l == TRUE)
		conv_lc(data);
	else if ((data->type == 'x' || data->type == 'X') && data->l == TRUE)
		conv_llx(data);
	else if (data->type == 'u' && data->l == TRUE)
		conv_llu(data);
	else if (data->type == 'o' && data->l == TRUE)
		conv_llo(data);
	else if (data->type == 'O' && data->l == TRUE)
	{
		data->ll = TRUE;
		conv_llo(data);
	}
	else if (data->type == 'D' && data->l == TRUE)
	{
		data->ll = TRUE;
		conv_lld(data);
	}
	else if (data->type == 'U' && data->l == TRUE)
		conv_llu(data);
}
