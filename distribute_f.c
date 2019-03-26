/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:03:08 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/03/08 12:03:20 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_ftoother(t_args *args, char *is, char *fs)
{
	args->chrn = args->chrn + ft_strlen(is);
	if (args->plus == '+' && args->fsign == 0)
		args->chrn++;
	if (args->space == 'y' && args->plus != '+' && args->fsign == 0)
	{
		ft_putchar(' ');
		args->chrn++;
		args->endin++;
	}
	if ((args->dot == '.' && args->dott > 0) || (args->dot == ' '))
		args->chrn++;
	args->num = args->num - args->chrn;
	if (args->num < 0)
		args->num = 0;
	if (args->sign == '-')
		ft_writeminusf(args, fs, is);
	else
		ft_writeelsef(args, fs, is);
	free(is);
	if (args->dott > 0)
	{
		free(fs);
		free(args->fs);
	}
	FREEF(args->dott, args->fs);
}

void	ft_dottzero(t_args *args, long double f, char *is)
{
	if (args->fsign == 1)
		f = f * -1;
	f = f * 10;
	args->z = (unsigned long long)f;
	args->fs = ft_itoaf(args->z);
	args->forf = (unsigned long long)f % 10;
	if (args->forf >= 5 && args->forf <= 9)
	{
		args->z++;
		args->p = ft_itoaf(args->z);
		if (ft_strlen(args->fs) < ft_strlen(args->p))
		{
			ZERO(args->remnum, is);
		}
		else if (args->forf >= 5)
		{
			f = f * 10;
			args->forf = (long long)f % 10;
			if (args->forf >= 4)
				ZERO(args->remnum, is);
		}
		free(args->p);
	}
	args->iscp = is;
}

void	ft_dottmore(t_args *args, long double f, char *fs, char *is)
{
	long long	j;

	DD(j, args->dott, args->fsign, f, args->z, args->fs, args->forf);
	if (args->z == 0 && args->forf < 5)
		fs = ft_memchr(fs, args->dott, '0');
	else if (args->forf >= 5 && args->forf <= 9)
	{
		ELSZ(args->z, args->p);
		if (ft_strlen(args->fs) < ft_strlen(args->p))
		{
			MORE(args->remnum, is, fs, args->dott);
		}
		else
			fs = ft_itoaf(args->z);
		free(args->p);
	}
	else
		fs = ft_itoaf(args->z);
	if (ft_strlen(fs) < args->dott)
	{
		IFP(args->p, args->z, fs);
		fs = ft_memchr(fs, (args->dott - (ft_strlen(args->p))), '0');
		IFI(args->ind, args->chrn, args->p);
	}
	MORF(args->chrn, fs, args->fscp, args->iscp, is);
}

void	ft_fdismove(long double f, t_args *args)
{
	char		*fs;
	char		*is;
	long long	i;

	args->fsign = ((*(((char*)&f) + 9)) >> 7) ? 1 : 0;
	i = (long long)f;
	f = f - i;
	if (args->fsign == 1)
	{
		i = i * -1;
		args->chrn--;
	}
	args->remnum = i;
	is = ft_itoa(i);
	if (args->dott > 0)
	{
		ft_dottmore(args, f, fs, is);
		fs = args->fscp;
		is = args->iscp;
	}
	else if (args->dott == 0)
	{
		DISMOVE(args, f, is, args->iscp);
	}
	ft_ftoother(args, is, fs);
}

void	distribute_f(t_args *args, va_list ap)
{
	long double	f;

	if (args->dot == ' ')
		args->dott = 6;
	if (args->l == 1)
		f = va_arg(ap, double);
	else if (args->bigl == 1)
		f = va_arg(ap, long double);
	else
		f = va_arg(ap, double);
	if ((f == 1.0 / 0.0) || f != f || f == -1.0 / 0.0)
		ft_inf(f, args);
	else
		ft_fdismove(f, args);
	DISC(args->plus, args->hash, args->sign, args->pref, args->space);
	DISCI(args->dot, args->ind, args->fsign, args->remnum, args->forf);
	DISI(args->z, args->chrn, args->num, args->dott, args->h, args->hh);
	DISII(args->l, args->ll, args->bigl, args->i, args->endin);
}
