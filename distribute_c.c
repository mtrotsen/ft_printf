/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:54:44 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/21 16:54:45 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_xcut(unsigned long long x, t_args *args)
{
	if (x == 0 && args->dott == 0 && args->dot == '.')
	{
		args->chrn--;
		args->endin--;
	}
	args->num = args->num - args->chrn;
	if (args->dot == '.')
	{
		args->dott = args->dott - args->chrn;
		if (args->dott < 0)
			args->dott = 0;
		args->num = args->num - args->dott;
	}
	if (args->hash == '#')
		args->num = args->num - 2;
	if (args->num < 0)
		args->num = 0;
}

void	ft_xxwrite(unsigned long long x, char *s, t_args *args)
{
	if (args->dot != '.' && args->pref == '0')
		args->pref = '0';
	else
		args->pref = ' ';
	if (args->hash == '#' && x > 0 && args->dott == 0 && args->pref == '0')
	{
		ft_putchar('0');
		ft_putchar('X');
		args->endin = args->endin + 2;
		ft_putspaces(args);
	}
	else if (args->hash == '#' && x > 0)
	{
		ft_putspaces(args);
		ft_putchar('0');
		ft_putchar('X');
		args->endin = args->endin + 2;
	}
	else
		ft_putspaces(args);
	args->pref = '0';
	ft_putdot(args);
	ft_puts(s, args);
}

void	ft_xwrite(unsigned long long x, char *s, t_args *args)
{
	if (args->dot != '.' && args->pref == '0')
		args->pref = '0';
	else
		args->pref = ' ';
	if (args->hash == '#' && x > 0 && args->dott == 0 && args->pref == '0')
	{
		ft_putchar('0');
		ft_putchar('x');
		args->endin = args->endin + 2;
		ft_putspaces(args);
	}
	else if (args->hash == '#' && x > 0)
	{
		ft_putspaces(args);
		ft_putchar('0');
		ft_putchar('x');
		args->endin = args->endin + 2;
	}
	else
		ft_putspaces(args);
	args->pref = '0';
	ft_putdot(args);
	ft_puts(s, args);
}

void	ft_writec(t_args *args, char c)
{
	if (args->sign == '-')
	{
		args->pref = ' ';
		ft_putchar(c);
		ft_putdot(args);
		ft_putspaces(args);
	}
	else
	{
		ft_putspaces(args);
		ft_putdot(args);
		ft_putchar(c);
	}
}

void	distribute_c(t_args *args, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	args->chrn++;
	args->num = args->num - args->chrn;
	if (args->dot == '.')
	{
		args->dott = args->dott - args->chrn;
		if (args->dott < 0)
			args->dott = 0;
		if (c == 0)
			args->dott = 0;
		args->num = args->num - args->dott;
	}
	if (args->num < 0)
		args->num = 0;
	ft_writec(args, c);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}
