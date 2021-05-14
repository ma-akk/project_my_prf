/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:52:56 by gtresa            #+#    #+#             */
/*   Updated: 2020/12/20 21:08:44 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_prf
{
	int flag;
	int width;
	int prec;
	int type;
	int len;
	int pref;
}				t_prf;

int				ft_printf(const char *str, ...);
t_prf			*init_struct();
int				check_flags(char *str, t_prf *prf);
int				check_prec(char *str, t_prf *prf, va_list ap);
int				check_type(char *str, t_prf *prf);
int				check_width(char *str, t_prf *prf, va_list ap);
int				check_format(char *str, t_prf *prf, va_list ap);
void			output_start(char *str_start, t_prf *prf);
void			output_width_nbr(char *str_arg, t_prf *prf);
void			output_width_str(int len, char *str_arg, t_prf *prf);
char			*output_prec(char *str_arg, t_prf *prf);
int				output_str(t_prf *prf, va_list ap);
void			output_nbr(t_prf *prf, va_list ap);
void			output_hex(t_prf *prf, va_list ap);

#endif
