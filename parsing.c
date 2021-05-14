/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:37:35 by gtresa            #+#    #+#             */
/*   Updated: 2020/12/20 21:03:15 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_type(char *str, t_prf *prf)
{
	int		i;
	char	*arr_types;

	i = 0;
	arr_types = "cspdiuxX";
	while (str[i] != '\0')
	{
		if (i > 0 && str[i] == 37)
			return ((prf->type = 37));
		if (ft_strchr(arr_types, str[i]))
			return ((prf->type = str[i]));
		i++;
	}
	return (prf->type);
}

int		check_flags(char *str, t_prf *prf)
{
	int	i;
	int fl;

	i = 0;
	fl = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (i > 0 && str[i] != str[i - 1])
			fl = 1;
		i++;
	}
	if (str[0] == '-' || fl == 1)
		prf->flag = 1;
	else if (str[0] == '0')
		prf->flag = 0;
	ft_strcpy(str, (str + i));
	return (prf->flag);
}

int		check_width(char *str, t_prf *prf, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == '*')
	{
		prf->width = va_arg(ap, int);
		if (prf->width < 0)
		{
			prf->width = prf->width * (-1);
			prf->flag = 1;
		}
		i++;
	}
	else
	{
		while (str[i] >= 48 && str[i] <= 57)
			i++;
		prf->width = ft_atoi(&str[0]);
	}
	if (str[i] != '.' && str[i] != prf->type && str[i] != '%')
		if (str[i] >= 48 && str[i] <= 57)
			return (-1);
	ft_strcpy(str, (str + i));
	return (1);
}

int		check_prec(char *str, t_prf *prf, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == '*')
	{
		prf->prec = va_arg(ap, int);
		if (prf->prec < 0)
			prf->prec = -1;
		i++;
	}
	else
	{
		while (str[i] >= 48 && str[i] <= 57)
			i++;
		prf->prec = ft_atoi(&str[0]);
	}
	ft_strcpy(str, (str + i));
	if (str[0] != prf->type && str[0] != '%')
		return (-1);
	return (1);
}

int		check_format(char *str, t_prf *prf, va_list ap)
{
	int i;

	i = 0;
	if (check_type(str, prf))
	{
		ft_strcpy(str, (str + 1));
		check_flags(str, prf);
		if (check_width(str, prf, ap) == -1)
			return (-1);
		if (str[i] == '.')
		{
			ft_strcpy(str, (str + 1));
			if (check_prec(str, prf, ap) == -1)
				return ((prf->len = -1));
		}
		ft_strcpy(str, (str + 1));
		return (1);
	}
	return (-1);
}
