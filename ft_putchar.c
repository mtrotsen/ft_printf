/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:08:54 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/11/15 15:09:35 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
		n++;
	}
	return (n);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc((ft_strlen(s)) + 1);
	if (dup == NULL)
		return (0);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_precision(const char *format, t_args *args)
{
	int		c;
	char	*rts;
	int		j;

	j = 0;
	if (format[args->i] == '.')
	{
		args->dot = '.';
		if (format[(args->i + 1)] >= '0' && format[(args->i + 1)] <= '9')
		{
			args->i++;
			c = args->i;
			while (format[args->i] >= '0' && format[args->i] <= '9')
			{
				args->i++;
				j++;
			}
			rts = malloc(sizeof(char) * j);
			j = 0;
			while (c < args->i)
				PRECC(rts, j, format, c);
			PRECN(rts, j, args->dott, args->i);
		}
	}
}

void	ft_width(const char *format, t_args *args)
{
	int		c;
	char	*str;
	int		j;

	j = 0;
	if (format[args->i] >= '1' && format[args->i] <= '9')
	{
		c = args->i;
		while (format[args->i] >= '0' && format[args->i] <= '9')
		{
			args->i++;
			j++;
		}
		str = malloc(sizeof(char) * j);
		j = 0;
		while (c < args->i)
		{
			str[j] = format[c];
			c++;
			j++;
		}
		str[j] = '\0';
		WTH(args->num, str, j, args->i);
	}
}
