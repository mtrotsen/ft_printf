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
		ft_putchar(' ');
		i++;
	}
}

void	ft_print_to_procent(const char *format, t_args *args)
{
	int		i;
	char	*chr;

	chr = (char *)format;
	i = 0;
	while (chr[i] != '%' && chr[i] != '\0' && chr[i] != '\n')
	{
		ft_putchar(chr[i]);
		i++;
	}
	args->i = i;
}

void	ft_find_arg(const char *format, va_list ap, t_args *args)
{
	char	c;
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
		ft_putspaces(args);
		printf("%c\n", format[args->i]);
	}
	if (format[args->i] == 'c')
	{
		c = (char) va_arg(ap, int);
		ft_putchar(c);
		args->i++;
	}
	if (format[args->i] == '\n')
		ft_putchar('\n');
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_args	*args;
	char	*count;
	int		i;

	i = 0;
	va_start(ap, format);
	ft_print_to_procent(format, args);
	ft_find_arg(format, ap, args);
	while (format[i] != '\0')
		i++;
	va_end(ap);
	return (i);
}