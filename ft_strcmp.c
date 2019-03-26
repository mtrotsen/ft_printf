/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:10:42 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/11/14 15:55:59 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putspaces(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->num)
	{
		ft_putchar(args->pref);
		i++;
		args->endin++;
	}
}

void	ft_print_to_procent(const char *format, t_args *args)
{
	char	*chr;

	chr = (char *)format;
	while (chr[args->i] != '%' && chr[args->i] != '\0')
	{
		ft_putchar(chr[args->i]);
		args->i++;
		args->endin++;
	}
}

void	ft_writeminusf(t_args *args, char *fs, char *is)
{
	args->pref = ' ';
	if (args->plus == '+' && args->fsign == 0)
	{
		ft_putchar('+');
		args->endin++;
	}
	else if (args->fsign == 1)
	{
		ft_putchar('-');
		args->endin++;
	}
	ft_puts(is, args);
	if (args->dott > 0)
	{
		ft_putchar('.');
		ft_puts(fs, args);
		if (args->ind == 1)
		{
			ft_puts(args->p, args);
			free(args->p);
			args->endin++;
		}
		args->endin = args->endin + 2;
	}
	ft_putspaces(args);
}

void	ft_writeelsef(t_args *args, char *fs, char *is)
{
	if (args->plus == '+' && args->fsign == 0 && args->pref == '0')
	{
		ELSEONE(args->endin, args);
	}
	else if (args->plus == '+' && args->fsign == 0 && args->pref == ' ')
	{
		ELSETWO(args->endin, args);
	}
	else if (args->fsign == 1 && args->pref == '0')
	{
		ELSETHREE(args->endin, args);
	}
	else if (args->fsign == 1 && args->pref == ' ')
	{
		ELSEFOUR(args->endin, args);
	}
	else
		ft_putspaces(args);
	ft_puts(is, args);
	if (args->dott > 0)
	{
		EDOTT(fs, args, args->ind, args->p, args->endin);
	}
}
