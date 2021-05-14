/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:25:34 by gtresa            #+#    #+#             */
/*   Updated: 2020/12/19 11:30:31 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenstr(size_t n, int base)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static int	fill_str(size_t n, int base, char *str)
{
	int mod;
	int i;

	str[0] = '0';
	i = (n == 0) ? 1 : 0;
	while (n > 0)
	{
		mod = n % base;
		if (mod > 9)
			str[i] = mod + 87;
		else
			str[i] = mod + 48;
		n = n / base;
		i++;
	}
	str[i] = '\0';
	return (i);
}

static void	rev_str(char *str, int len)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < len)
	{
		len--;
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
	}
}

char		*ft_itoa_bs(size_t n, int base)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc((lenstr(n, base) + 1) * sizeof(char))))
		return (NULL);
	fill_str(n, base, str);
	rev_str(str, lenstr(n, base));
	return (str);
}
