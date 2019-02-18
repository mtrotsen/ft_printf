/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:17:07 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/07 17:17:10 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspaces(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->num)
	{
		ft_putchar(args->pref);
		i++;
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
	}
}

void	ft_find_arg(const char *format, va_list ap, t_args *args)
{
	char	c = va_arg(ap, int);
	char	*str;
	int		j;

	j = 0;
	if (format[args->i] == '%')
	{
		if (format[(args->i + 1)] == '%')
		{
			args->i++;
			ft_putchar('%');
		}
		args->i++;
	}
	if (format[args->i] == '-')
	{
		args->sign = '-';
		args->i++;
	}
	if (format[args->i] == '0')
	{
		args->pref = '0';
		args->i++;
	}
	if (format[args->i] >= '0' && format[args->i] <= '9')
	{
		args->bum = args->i;
		while (format[args->i] >= '0' && format[args->i] <= '9')
		{
			args->i++;
			j++;
		}
		str = malloc(sizeof(char) * j);
		j = 0;
		while (args->bum < args->i)
		{
			str[j] = format[args->bum];
			args->bum++;
			j++;
		}
		str[j] = '\0';
		args->num = ft_atoi(str);
		//printf("%c\n", format[args->i]);
	}
	if (format[args->i] == 'c')
	{
		//ft_putendl("1");
		//ft_putchar((char)va_arg(ap, int));
		//printf("%c\n", format[args->i]);
		//c = va_arg(ap, int);
		//printf("%c\n", format[args->i]);
		//printf("%c\n", c);
		args->chrn++;
		args->num = args->num - args->chrn;
	if (args->num < 0)
		args->num = 0;
	if (args->sign == '-')
	{
		args->pref = ' ';
		ft_putchar(c);
		ft_putspaces(args);
	}
	else
	{
		ft_putspaces(args);
		ft_putchar(c);
	}
		args->i++;
		
	}
	if (format[args->i] == '\n')
	{
		ft_putchar('\n');
		args->i++;
	}
	if (format[args->i] != '\0')
	{
		ft_print_to_procent(format, args);
		if (format[args->i] != '\0')
			ft_find_arg(format, ap, args);
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_args	*args;
	char	*count;
	int		i;

	i = 0;
	args->pref = ' ';
	args->chrn = 0;
	args->i = 0;
	va_start(ap, format);
	ft_print_to_procent(format, args);
	ft_find_arg(format, ap, args);
	while (format[i] != '\0')
		i++;
	va_end(ap);
	return (i);
}