/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:54:40 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/28 11:54:43 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_lowc(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = s[i] + 32;
		i++;
	}
	return (s);
}

char			*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	*res;

	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	res = malloc(sizeof(char) * len);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[i] = str[len];
		len--;
		i++;
	}
	free(str);
	return (res);
}

static int		length(unsigned long long n, int base)
{
	int l;

	l = 0;
	if (n == 0)
		l++;
	if (n < 1 && n != 0)
	{
		n = n * -1;
		l++;
	}
	while (n > 0)
	{
		n = n / base;
		l++;
	}
	return (l);
}

char			*itoa_base(unsigned long long n, int base)
{
	char	*str;
	long	nb;
	int		len;
	int		i;
	char	*ret;

	BASE(i, n, nb, len, base);
	str = malloc(sizeof(char) * (len + 1));
	str[(len + 1)] = '\0';
	while (i <= len)
	{
		if (nb % base < 10)
			str[i] = nb % base + '0';
		else
			str[i] = nb % base + 'A' - 10;
		NB(nb, base, i);
	}
	str = ft_strrev(str);
	if (str[0] == '0')
	{
		ret = ft_strdup(&str[1]);
		free(str);
		return (ret);
	}
	return (str);
}
