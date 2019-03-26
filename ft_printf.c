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

#include "libftprintf.h"

void	ft_branch(t_args *args, va_list ap, const char *format)
{
	if (format[args->i] == '%')
		distribute_percent(args, ap);
	if (format[args->i] == 'c')
		distribute_c(args, ap);
	if (format[args->i] == 's')
		distribute_s(args, ap);
	if (format[args->i] == 'p')
		distribute_p(args, ap);
	if (format[args->i] == 'd' || format[args->i] == 'i')
		distribute_di(args, ap);
	if (format[args->i] == 'x')
		distribute_x(args, ap);
	if (format[args->i] == 'X')
		distribute_xx(args, ap);
	if (format[args->i] == 'u')
		distribute_u(args, ap);
	if (format[args->i] == 'o')
		distribute_o(args, ap);
	if (format[args->i] == 'f')
		distribute_f(args, ap);
}

void	ft_moveft(const char *format, t_args *args)
{
	if (format[args->i] == ' ')
		args->space = 'y';
	if (format[args->i] == '-')
		args->sign = '-';
	if (format[args->i] == '0')
		args->pref = '0';
	if (format[args->i] == '+')
		args->plus = '+';
	if (format[args->i] == '#')
		args->hash = '#';
	if (format[args->i] == 'h' && format[(args->i + 1)] != 'h')
		args->h = 1;
	if (format[args->i] == 'h' && format[(args->i + 1)] == 'h')
		HH(args->hh, args->i);
	if (format[args->i] == 'l' && format[(args->i + 1)] != 'l')
		args->l = 1;
	if (format[args->i] == 'l' && format[(args->i + 1)] == 'l')
		LL(args->ll, args->i);
	if (format[args->i] == 'L')
		args->bigl = 1;
	ft_width(format, args);
	ft_precision(format, args);
}

void	ft_find_arg(const char *format, va_list ap, t_args *args)
{
	while ((format[args->i] != '\0') && (format[args->i] == '%' || \
		format[args->i] == ' ' || format[args->i] == '-' || \
		format[args->i] == '0' || format[args->i] == '+' || \
		format[args->i] == '#' || format[args->i] == 'h' || \
		format[args->i] == 'l' || format[args->i] == 'L' || \
		(format[args->i] >= '1' && format[args->i] <= '9') || \
		format[args->i] == '.' || format[args->i] == '\n' || \
		format[args->i] == 'c' || format[args->i] == 's' || \
		format[args->i] == 'p' || format[args->i] == 'd' || \
		format[args->i] == 'i' || format[args->i] == 'x' || \
		format[args->i] == 'X' || format[args->i] == 'u' || \
		format[args->i] == 'o' || format[args->i] == 'f'))
	{
		IF(format[args->i], args->percent, args, ap, format);
		ft_moveft(format, args);
		BRANCH(format[args->i], args, ap, format, args->percent);
		SLASHN(format[args->i], args->i, args->endin, args->percent);
		EXIT(format[args->i], args->i, args->percent, args->endin);
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_args	*args;
	int		i;

	i = 0;
	if (!(args = malloc(sizeof(t_args))))
		return (0);
	CHARSS(args->pref, args->dot, args->plus, args->hash, args->sign);
	CHARRS(args->percent, args->space, args->ind, args->fsign, args->remnum);
	CHAARS(args->forf, args->dott, args->chrn, args->num, args->i);
	CHHARS(args->endin, args->h, args->hh, args->l, args->ll, args->bigl);
	va_start(ap, format);
	while (format[args->i] != '\0')
	{
		ft_print_to_procent(format, args);
		if (format[args->i] == '%')
			ft_find_arg(format, ap, args);
	}
	va_end(ap);
	free(args);
	return (args->endin);
}
