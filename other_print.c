/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:12:02 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/22 13:12:03 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putdot(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->dott)
	{
		ft_putchar(args->pref);
		i++;
		args->endin++;
	}
}

void		ft_puts(char *s, t_args *args)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && i < args->chrn)
	{
		ft_putchar(s[i]);
		i++;
		args->endin++;
	}
	if (s[i] == '\0')
		args->endin--;
}

char		*ft_memchr(char *fs, int dott, char c)
{
	int i;

	i = 0;
	fs = malloc(sizeof(dott + 1));
	while (i < dott)
	{
		fs[i] = c;
		i++;
	}
	fs[dott] = '\0';
	return (fs);
}

static int	lengthf(unsigned long long n)
{
	int l;

	l = 0;
	if (n == 0)
		l++;
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char		*ft_itoaf(unsigned long long n)
{
	char				*str;
	unsigned long long	nb;
	int					i;

	nb = n;
	i = lengthf(n);
	if ((str = malloc(i + 1)) == NULL)
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	str[--i] = (nb % 10) + '0';
	while (nb /= 10)
	{
		str[--i] = (nb % 10) + '0';
	}
	return (str);
}
