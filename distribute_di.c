/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:55:35 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/28 13:55:37 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_neddi(long long d, t_args *args)
{
	args->pref = ' ';
	ft_putspaces(args);
	if (args->plus == '+' && d > -1)
	{
		ft_putchar('+');
		args->endin++;
	}
	else if (d < 0)
	{
		ft_putchar('-');
		d = (d * -1);
		args->endin++;
	}
	args->pref = '0';
	ft_putdot(args);
	if (args->h == 1)
		ft_puth(d, args);
	else if (args->hh == 1)
		ft_puthh(d, args);
	else if (args->l == 1)
		ft_putl(d, args);
	else if (args->ll == 1)
		ft_putll(d, args);
	else if (args->chrn > 0)
		ft_putnbr(d, args);
}

void	ft_eddi(long long d, t_args *args)
{
	if (args->plus == '+' && d > -1 && args->pref == '0')
	{
		EDDI(args->endin, args);
	}
	else if (args->plus == '+' && d > -1 && args->pref == ' ')
	{
		EEDDI(args->endin, args);
	}
	else if (d < 0 && args->pref == '0')
	{
		EDDII(d, args->endin, args);
	}
	else if ((d < 0 && args->ll == 1) || (d < 0 && args->hh == 1))
	{
		EEDDII(args, d, args->endin);
	}
	else
		ft_putspaces(args);
	ft_dicheck(d, args);
}

void	ft_md(long long d, t_args *args)
{
	if (args->plus == '+' && d > -1)
	{
		ft_putchar('+');
		args->endin++;
	}
	else if (d < 0 && args->h == 0 && args->hh == 0)
	{
		ft_putchar('-');
		d = (d * -1);
		args->endin++;
	}
	args->pref = '0';
	ft_putdot(args);
	args->pref = ' ';
	if (args->h == 1)
		ft_puth(d, args);
	else if (args->hh == 1)
		ft_puthh(d, args);
	else if (args->l == 1)
		ft_putl(d, args);
	else if (args->ll == 1)
		ft_putll(d, args);
	else if (args->chrn > 0)
		ft_putnbr(d, args);
	ft_putspaces(args);
}

void	ft_diput(long long d, t_args *args)
{
	if (args->space == 'y' && args->plus != '+' && d > -1)
	{
		ft_putchar(' ');
		args->num--;
		args->endin++;
	}
	args->num = args->num - args->chrn;
	if (args->dot == '.')
	{
		if ((args->plus == '+' && d > -1) || d < 0)
			args->chrn--;
		args->dott = args->dott - args->chrn;
		if (args->dott < 0)
			args->dott = 0;
		args->num = args->num - args->dott;
	}
	if (args->num < 0)
		args->num = 0;
	DIDI(args->sign, args->dot, args, d);
}

void	distribute_di(t_args *args, va_list ap)
{
	long long		d;
	char			*s;

	if (args->h == 1 && args->hh == 0 && args->l == 0 && args->ll == 0)
		d = (short)va_arg(ap, int);
	else if (args->hh == 1 && args->l == 0 && args->ll == 0)
		d = (signed char)va_arg(ap, int);
	else if (args->l == 1 && args->ll == 0)
		d = va_arg(ap, long);
	else if (args->ll == 1)
		d = va_arg(ap, long long);
	else
		d = (int)va_arg(ap, int);
	s = ft_itoa(d);
	args->chrn = ft_strlen(s);
	if (args->plus == '+' && d > -1)
		args->chrn++;
	if (d == 0 && args->dott == 0)
		args->chrn--;
	ft_diput(d, args);
	free(s);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISIID(args->l, args->ll, args->bigl, args->i);
}
