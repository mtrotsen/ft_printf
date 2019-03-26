/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:10:12 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/03/07 14:10:15 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_owrite(unsigned long long o, char *s, t_args *args)
{
	if (args->sign == '-')
	{
		args->pref = '0';
		ft_putdot(args);
		if (args->hash == '#' && o != 0)
		{
			args->chrn--;
			ft_putchar('0');
		}
		WOIF(s, args, args->pref);
	}
	else
	{
		if (args->dot != '.' && args->pref == '0')
			args->pref = '0';
		else
			args->pref = ' ';
		ft_putspaces(args);
		args->pref = '0';
		ft_putdot(args);
		if (args->hash == '#' && o != 0)
			ft_putchar('0');
		ft_puts(s, args);
	}
}

void	ft_ooo(unsigned long long o, char *s, t_args *args)
{
	if (args->hash == '#' && o == 0)
	{
		args->chrn++;
		args->endin++;
	}
	else if (args->hash == '#' && o != 0)
	{
		args->chrn++;
		args->endin++;
	}
	if (o == 0 && args->dott == 0 && args->dot == '.')
		OIF(args->chrn, args->endin);
	args->num = args->num - args->chrn;
	if (args->dot == '.')
	{
		args->dott = args->dott - args->chrn;
		if (args->dott < 0)
			args->dott = 0;
		args->num = args->num - args->dott;
	}
	if (args->num < 0)
		args->num = 0;
	ft_owrite(o, s, args);
}

void	distribute_o(t_args *args, va_list ap)
{
	char				*s;
	unsigned long long	o;

	if (args->h == 1 && args->hh == 0 && args->l == 0 && args->ll == 0)
		o = (unsigned short)va_arg(ap, unsigned int);
	else if (args->hh == 1 && args->l == 0 && args->ll == 0)
		o = (unsigned char)va_arg(ap, unsigned int);
	else if (args->l == 1 && args->ll == 0)
		o = (unsigned long)va_arg(ap, unsigned long);
	else if (args->ll == 1)
		o = (unsigned long long)va_arg(ap, unsigned long long);
	else
		o = va_arg(ap, unsigned int);
	s = itoa_base(o, 8);
	args->chrn = ft_strlen(s);
	ft_ooo(o, s, args);
	free(s);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}
