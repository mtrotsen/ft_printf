/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:18:14 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/11/19 13:42:26 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		f;
	int		j;
	int		i;
	int		len;

	f = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	f = ft_strlen(s1);
	j = ft_strlen(s2);
	len = f + j;
	if ((res = malloc(sizeof(res) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		res[i++] = *s1++;
	while (*s2 != '\0')
	{
		res[i++] = *s2++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_dicheck(long long d, t_args *args)
{
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

void	ft_fnof(t_args *args)
{
	args->num = args->num - 3;
	if (args->space == 'y' && args->plus == ' ')
	{
		ft_putchar(' ');
		args->endin++;
		args->num--;
	}
	if (args->plus == '+')
		args->num--;
	if (args->sign == '-')
	{
		ft_putstr("nan");
		ft_putspaces(args);
	}
	else
	{
		ft_putspaces(args);
		ft_putstr("nan");
	}
	args->endin = args->endin + 2;
}

void	ft_fonezero(t_args *args)
{
	args->num = args->num - 3;
	if (args->space == 'y' && args->plus == ' ')
	{
		ft_putchar(' ');
		args->endin++;
		args->num--;
	}
	if (args->plus == '+')
		args->num--;
	if (args->sign == '-')
	{
		INF(args->plus, args->endin, args);
	}
	else
	{
		ft_putspaces(args);
		if (args->plus == '+')
		{
			ft_putchar('+');
			args->endin++;
		}
		ft_putstr("inf");
	}
	args->endin = args->endin + 2;
}

void	ft_inf(long double f, t_args *args)
{
	args->pref = ' ';
	if (f == 1.0 / 0.0)
		ft_fonezero(args);
	if (f != f)
		ft_fnof(args);
	if (f == -1.0 / 0.0)
	{
		args->num = args->num - 4;
		if (args->sign == '-')
		{
			ft_putstr("-inf");
			ft_putspaces(args);
		}
		else
		{
			ft_putspaces(args);
			ft_putstr("-inf");
		}
		args->endin = args->endin + 3;
	}
}
