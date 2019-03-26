/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:17:51 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/03/04 18:17:52 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_xxmake(unsigned long long x, char *s, t_args *args)
{
	ft_xcut(x, args);
	if (args->sign == '-')
	{
		if (args->hash == '#' && x > 0)
		{
			ft_putchar('0');
			ft_putchar('X');
			args->endin = args->endin + 2;
		}
		args->pref = '0';
		ft_putdot(args);
		ft_puts(s, args);
		args->pref = ' ';
		ft_putspaces(args);
	}
	else
		ft_xxwrite(x, s, args);
}

void	ft_xmake(unsigned long long x, char *s, t_args *args)
{
	ft_xcut(x, args);
	s = ft_lowc(s);
	if (args->sign == '-')
	{
		if (args->hash == '#' && x > 0)
		{
			ft_putchar('0');
			ft_putchar('x');
			args->endin = args->endin + 2;
		}
		args->pref = '0';
		ft_putdot(args);
		ft_puts(s, args);
		args->pref = ' ';
		ft_putspaces(args);
	}
	else
		ft_xwrite(x, s, args);
}

void	distribute_x(t_args *args, va_list ap)
{
	char				*s;
	unsigned long long	x;

	if (args->h == 1 && args->hh == 0 && args->l == 0 && args->ll == 0)
		x = (unsigned short)va_arg(ap, unsigned int);
	else if (args->hh == 1 && args->l == 0 && args->ll == 0)
		x = (unsigned char)va_arg(ap, unsigned int);
	else if (args->l == 1 && args->ll == 0)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (args->ll == 1)
		x = (unsigned long long)va_arg(ap, unsigned long long);
	else
		x = va_arg(ap, unsigned int);
	s = itoa_base(x, 16);
	args->chrn = ft_strlen(s);
	ft_xmake(x, s, args);
	free(s);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}

void	distribute_xx(t_args *args, va_list ap)
{
	char				*s;
	unsigned long long	x;

	if (args->h == 1 && args->hh == 0 && args->l == 0 && args->ll == 0)
		x = (unsigned short)va_arg(ap, unsigned int);
	else if (args->hh == 1 && args->l == 0 && args->ll == 0)
		x = (unsigned char)va_arg(ap, unsigned int);
	else if (args->l == 1 && args->ll == 0)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (args->ll == 1)
		x = (unsigned long long)va_arg(ap, unsigned long long);
	else
		x = va_arg(ap, unsigned int);
	s = itoa_base(x, 16);
	args->chrn = ft_strlen(s);
	ft_xxmake(x, s, args);
	free(s);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}
