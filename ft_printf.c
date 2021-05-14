/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:33:04 by gtresa            #+#    #+#             */
/*   Updated: 2020/12/25 12:03:03 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_prf		*init_struct(void)
{
	t_prf *prf;

	prf = (t_prf*)malloc(sizeof(t_prf));
	if (prf != NULL)
	{
		prf->flag = 2;
		prf->width = 0;
		prf->prec = -1;
		prf->type = 0;
		prf->len = 0;
		prf->pref = 0;
	}
	return (prf);
}

static void	start_struct(t_prf *prf, char *format)
{
	prf->flag = 2;
	prf->width = 0;
	prf->prec = -1;
	prf->type = 0;
	prf->pref = 0;
	output_start(&(*format), prf);
}

static int	free_data(char *format, t_prf *prf)
{
	int res;

	res = prf->len;
	if (format != NULL)
		free(format);
	if (prf != NULL)
	{
		res = prf->len;
		free(prf);
	}
	return (res);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	t_prf	*prf;
	char	*format;

	if ((prf = init_struct()) == NULL)
		return (-1);
	format = ft_strdup(str);
	va_start(ap, str);
	while (format)
	{
		start_struct(prf, &(*format));
		if (check_format(&(*format), prf, ap) == -1)
			return (free_data(format, prf));
		if (prf->type == 99 || prf->type == 115 || prf->type == 37)
			output_str(prf, ap);
		if (prf->type == 100 || prf->type == 105 || prf->type == 117)
			output_nbr(prf, ap);
		if (prf->type == 120 || prf->type == 88 || prf->type == 112)
			output_hex(prf, ap);
	}
	write(1, &"\0", 1);
	va_end(ap);
	return (free_data(format, prf));
}
