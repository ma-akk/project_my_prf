/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:36:37 by gtresa            #+#    #+#             */
/*   Updated: 2020/12/25 12:00:09 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		output_start(char *str_start, t_prf *prf)
{
	int i;

	i = 0;
	while (str_start[i] != '%' && str_start[i] != '\0')
		write(1, &str_start[i++], 1);
	prf->len = prf->len + i;
	ft_strcpy(str_start, (str_start + i));
	if (str_start[0] != '\0' && str_start[1] == '%')
	{
		write(1, &"%", 1);
		prf->len++;
		ft_strcpy(str_start, (str_start + 2));
		output_start(str_start, prf);
	}
}

static int	output_char(t_prf *prf, va_list ap)
{
	char	c;

	if (prf->type == 37)
		output_width_str(1, "%", prf);
	if (prf->type == 99)
	{
		c = va_arg(ap, int);
		if (prf->flag == 0 || prf->prec != -1)
			return (-1);
		output_width_str(1, &c, prf);
	}
	return (0);
}

int			output_str(t_prf *prf, va_list ap)
{
	int		len;
	char	*s;

	if (prf->type == 99 || prf->type == 37)
		return (output_char(prf, ap));
	if (prf->type == 115)
	{
		s = va_arg(ap, char*);
		len = (s == NULL) ? ft_strlen("(null)") : ft_strlen(s);
		if (prf->prec != -1 && prf->prec < len)
			len = prf->prec;
		if (s != NULL)
			output_width_str(len, s, prf);
		else
			output_width_str(len, "(null)", prf);
	}
	return (0);
}

void		output_nbr(t_prf *prf, va_list ap)
{
	char	*str_arg;
	long	nbr;

	if (prf->type == 100 || prf->type == 105)
	{
		if ((nbr = va_arg(ap, int)) < 0)
		{
			prf->pref = 1;
			nbr = nbr * (-1);
		}
		str_arg = output_prec(ft_itoa_bs(nbr, 10), prf);
	}
	if (prf->type == 117)
		str_arg = output_prec(ft_itoa_bs(va_arg(ap, unsigned int), 10), prf);
	output_width_nbr(str_arg, prf);
	free(str_arg);
}

void		output_hex(t_prf *prf, va_list ap)
{
	char	*str_arg;
	void	*p;
	int		i;

	i = 0;
	if (prf->type == 120 || prf->type == 88)
	{
		str_arg = output_prec(ft_itoa_bs(va_arg(ap, unsigned int), 16), prf);
		if (prf->type == 88)
			while (str_arg[i] != '\0')
			{
				str_arg[i] = (char)ft_toupper(str_arg[i]);
				i++;
			}
	}
	if (prf->type == 112)
	{
		prf->pref = 2;
		p = va_arg(ap, void *);
		str_arg = output_prec(ft_itoa_bs((unsigned long)p, 16), prf);
	}
	output_width_nbr(str_arg, prf);
	free(str_arg);
}
