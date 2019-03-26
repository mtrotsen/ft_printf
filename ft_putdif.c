/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:24:53 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/03/01 13:24:54 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puth(short n, t_args *args)
{
	if (n < 0)
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
	else if (n < 10)
	{
		ft_putchar(n + '0');
		args->endin++;
	}
	else
	{
		ft_putchar('0');
		args->endin++;
	}
}

void	ft_puthh(signed char n, t_args *args)
{
	if (n < 0)
		ft_putnbr(-n, args);
	else if (n >= 10)
	{
		ft_putnbr((n / 10), args);
		ft_putchar(n % 10 + '0');
		args->endin++;
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
		args->endin++;
	}
	else
	{
		ft_putchar('0');
		args->endin++;
	}
}

void	ft_putl(long n, t_args *args)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putl(-n, args);
		args->endin++;
	}
	else if (n >= 10)
	{
		ft_putl((n / 10), args);
		ft_putchar(n % 10 + '0');
		args->endin++;
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
		args->endin++;
	}
	else
	{
		ft_putchar('0');
		args->endin++;
	}
}

void	ft_putll(unsigned long long n, t_args *args)
{
	if (n >= 10)
	{
		ft_putl((n / 10), args);
		ft_putchar(n % 10 + '0');
		args->endin++;
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
		args->endin++;
	}
	else
	{
		ft_putchar('0');
		args->endin++;
	}
}
