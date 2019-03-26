/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:59:09 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/25 15:59:10 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	distribute_percent(t_args *args, va_list ap)
{
	args->chrn++;
	args->num = args->num - args->chrn;
	if (args->num < 0)
		args->num = 0;
	if (args->sign == '-')
	{
		args->pref = ' ';
		ft_putchar('%');
		ft_putspaces(args);
	}
	else
	{
		ft_putspaces(args);
		ft_putchar('%');
	}
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}
