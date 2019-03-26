/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:42:56 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/03/07 13:42:57 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	lengthu(unsigned long long n)
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

char		*ft_itoau(unsigned long long n)
{
	char				*str;
	unsigned long long	nb;
	int					i;

	nb = n;
	i = lengthu(n);
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

void		ft_uplace(char *s, t_args *args)
{
	if (args->sign == '-')
	{
		args->pref = '0';
		ft_putdot(args);
		ft_puts(s, args);
		args->pref = ' ';
		ft_putspaces(args);
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
		ft_puts(s, args);
	}
}

void		ft_ulook(unsigned long long u, char *s, t_args *args)
{
	if (u == 0 && args->dott == 0 && args->dot == '.')
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
	if (args->num < 0)
		args->num = 0;
	s = ft_lowc(s);
	ft_uplace(s, args);
}

void		distribute_u(t_args *args, va_list ap)
{
	char				*s;
	unsigned long long	u;

	if (args->h == 1 && args->hh == 0 && args->l == 0 && args->ll == 0)
		u = (unsigned short)va_arg(ap, unsigned int);
	else if (args->hh == 1 && args->l == 0 && args->ll == 0)
		u = (unsigned char)va_arg(ap, unsigned int);
	else if (args->l == 1 && args->ll == 0)
		u = (unsigned long)va_arg(ap, unsigned long);
	else if (args->ll == 1)
		u = (unsigned long long)va_arg(ap, unsigned long long);
	else
		u = va_arg(ap, unsigned int);
	s = ft_itoau(u);
	args->chrn = ft_strlen(s);
	ft_ulook(u, s, args);
	free(s);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}
