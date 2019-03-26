/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:35:29 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/22 13:35:34 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_writes(t_args *args, char *s)
{
	if (args->dot == '.')
	{
		args->dott = args->dott - args->chrn;
		args->num = args->num - args->dott;
		args->dot = ' ';
	}
	if (args->num < 0)
		args->num = 0;
	if (args->sign == '-')
	{
		args->pref = ' ';
		ft_puts(s, args);
		ft_putdot(args);
		ft_putspaces(args);
	}
	else
	{
		ft_putspaces(args);
		ft_putdot(args);
		ft_puts(s, args);
	}
}

void	distribute_s(t_args *args, va_list ap)
{
	char	*s;

	if ((s = va_arg(ap, char*)) == NULL)
		s = "(null)";
	while (s[args->chrn] != '\0')
		args->chrn++;
	if (args->dot == '.')
	{
		if (args->dott < 0)
			args->dott = 0;
		if ((ft_strcmp(s, "") == 0))
		{
			args->dott = 0;
			args->endin++;
		}
		args->chrn = args->dott;
		args->endin--;
	}
	args->num = args->num - args->chrn;
	ft_writes(args, s);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}
