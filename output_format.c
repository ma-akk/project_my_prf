/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:35:09 by gtresa            #+#    #+#             */
/*   Updated: 2020/12/25 11:58:10 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	output_sim(char c, int len, t_prf *prf)
{
	int i;

	i = 0;
	while (i++ < prf->width - len)
		ft_putchar_fd(c, 1);
	prf->len = (prf->width > len) ? prf->len + prf->width : prf->len + len;
}

static void	output_prefix(char *str, t_prf *prf)
{
	int len;

	len = ft_strlen(str);
	if (prf->pref == 1)
		ft_putchar_fd('-', 1);
	if (prf->pref == 2)
		ft_putstr_fd("0x", 1);
	if (prf->flag == 0)
		return ;
	ft_putnstr(str, len);
}

void		output_width_nbr(char *str_arg, t_prf *prf)
{
	int	len;

	len = ft_strlen(str_arg);
	if (prf->pref != 0)
		len = len + prf->pref;
	if (prf->flag == 1)
	{
		output_prefix(str_arg, prf);
		output_sim(' ', len, prf);
	}
	else if (prf->flag == 0)
	{
		output_prefix(str_arg, prf);
		output_sim('0', len, prf);
		ft_putnstr(str_arg, ft_strlen(str_arg));
	}
	else
	{
		output_sim(' ', len, prf);
		output_prefix(str_arg, prf);
	}
}

void		output_width_str(int len, char *str_arg, t_prf *prf)
{
	if (prf->flag == 1)
	{
		ft_putnstr(str_arg, len);
		output_sim(' ', len, prf);
	}
	else
	{
		if (prf->flag == 0)
			output_sim('0', len, prf);
		else
			output_sim(' ', len, prf);
		ft_putnstr(str_arg, len);
	}
}

char		*output_prec(char *str_arg, t_prf *prf)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	if (prf->prec != -1)
	{
		prf->flag = (prf->flag == 0) ? 2 : prf->flag;
		if ((len = (int)(prf->prec - ft_strlen(str_arg))) > 0)
		{
			res = malloc(sizeof(char) * (prf->prec + 1));
			ft_memset(res, 48, len);
			while (str_arg[i] != '\0')
				res[len++] = str_arg[i++];
			res[len] = '\0';
			free(str_arg);
			return (res);
		}
		else if (prf->prec == str_arg[0] - 48 && ft_strlen(str_arg) == 1)
			ft_strcpy(str_arg, (str_arg + 1));
	}
	return (str_arg);
}
