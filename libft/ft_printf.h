/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenaud <frenaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:18:30 by frenaud           #+#    #+#             */
/*   Updated: 2017/03/24 11:58:26 by frenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE 0
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include "libft.h"

typedef char	t_bool;

typedef struct	s_data
{
	va_list		*ap;
	int			ret;
	int			index;
	int			len_frmt;
	int			len_nb;
	char		c;
	char		type;
	char		*frmt;
	char		*cnv;
	t_bool		l;
	t_bool		ll;
	t_bool		h;
	t_bool		hh;
	t_bool		j;
	t_bool		z;
	t_bool		sharp;
	t_bool		moins;
	t_bool		plus;
	t_bool		prec;
	t_bool		spaces;
}				t_data;

/*
** Sources
**---------------------------
*/

int				ft_printf(char const *format, ...);
void			reset_struct(t_data *data);
void			color_parser(t_data *data);
int				width_nb(t_data *data, long long int nb);
int				check_precision_int(t_data *data, long long int nb);
void			ft_putnbr_l(long int n);
void			ft_putnbr_ll(long long n);
int				ft_nblen(int n);
int				ft_nblen_ll(long long n);
int				ft_nblen_l(long int n);
char			*check_precision_str(t_data *data, char *arg);
void			check_plus(t_data *data);
void			check_moins(t_data *data);
void			check_hashtag(t_data *data);
void			check_spaces(t_data *data);
void			print_d(t_data *data, int s, int a, int n);
void			print_o(t_data *data, int s, int a, long long int nb);
void			print_u(t_data *data, int s, int a, long long int nb);
void			print_x(t_data *data, int s, int a, long long int nb);
void			print_xx(t_data *data, int s, int a, long long int nb);

/*
** Parsers
**--------------------------
*/

void			parser(t_data *data);

/*
** Converters
**--------------------------
*/

void			conv_ls(t_data *data);
void			conv_ll(t_data *data);
void			conv_ls(t_data *data);
void			conv_lc(t_data *data);
void			conv_jd(t_data *data);
void			conv_jx(t_data *data);
void			conv_ju(t_data *data);
void			conv_jo(t_data *data);
void			conv_zd(t_data *data);
void			conv_zx(t_data *data);
void			conv_zu(t_data *data);
void			conv_zo(t_data *data);
void			conv_hhd(t_data *data);
void			conv_hhx(t_data *data);
void			conv_hho(t_data *data);
void			conv_hhu(t_data *data);
void			conv_lld(t_data *data);
void			conv_llx(t_data *data);
void			conv_llu(t_data *data);
void			conv_llo(t_data *data);
void			conv_flag(t_data *data);
void			conv_basic(t_data *data);
void			conv_l(t_data *data);
void			conv_j(t_data *data);
void			conv_z(t_data *data);
void			conv_h(t_data *data);
void			conv_s(t_data *data);
void			conv_d(t_data *data);
void			conv_c(t_data *data);
void			conv_p(t_data *data);
void			conv_x(t_data *data);
void			conv_u(t_data *data);
void			conv_o(t_data *data);
void			conv_percent(t_data *data);

#endif
