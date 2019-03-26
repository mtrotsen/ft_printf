/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:43:38 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/27 14:43:41 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pprint(char *s, t_args *args)
{
	if (args->sign == '-')
	{
		ft_putchar('0');
		ft_putchar('x');
		args->pref = '0';
		ft_putdot(args);
		ft_puts(s, args);
		args->pref = ' ';
		ft_putspaces(args);
	}
	else
	{
		args->pref = ' ';
		ft_putspaces(args);
		ft_putchar('0');
		ft_putchar('x');
		args->pref = '0';
		ft_putdot(args);
		ft_puts(s, args);
	}
}

void	distribute_p(t_args *args, va_list ap)
{
	char		*s;
	long long	p;

	p = (long long)va_arg(ap, void*);
	s = itoa_base(p, 16);
	args->chrn = ft_strlen(s);
	args->num = args->num - args->chrn;
	if (args->dot == '.')
	{
		args->dott = args->dott - args->chrn;
		if (args->dott < 0)
			args->dott = 0;
		args->num = args->num - args->dott;
	}
	args->num = args->num - 2;
	if (args->num < 0)
		args->num = 0;
	s = ft_lowc(s);
	ft_pprint(s, args);
	args->endin = args->endin + 2;
	free(s);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}
