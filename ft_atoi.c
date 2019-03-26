/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:52:21 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/11/14 16:00:47 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_atoi(const char *str)
{
	long long int	neg;
	long long int	res;
	int				i;

	neg = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (res * neg);
		else
			res = (res * 10) + (long long int)(str[i] - '0');
		i++;
	}
	return (res * neg);
}

void		ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s != '\0')
		write(1, s++, 1);
}

void		ft_putnbr(int n, t_args *args)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		args->endin = args->endin + 11;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n, args);
		args->endin++;
	}
	else if (n >= 10)
	{
		ft_putnbr((n / 10), args);
		ft_putchar(n % 10 + '0');
		args->endin++;
	}
	else
	{
		ft_putchar(n + '0');
		args->endin++;
	}
}

static int	length(long n)
{
	int l;

	l = 0;
	if (n == 0)
		l++;
	if (n < 0)
	{
		n = n * -1;
		l++;
	}
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = length(n);
	if ((str = malloc(i + 1)) == NULL)
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	str[--i] = (nb % 10) + '0';
	while (nb /= 10)
	{
		str[--i] = (nb % 10) + '0';
	}
	return (str);
}
