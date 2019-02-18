/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:45:07 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/07 17:45:10 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_args
{
	int			i;
	int			num;
	int			bum;
}				t_args;

int				ft_printf(const char *format, ...);
void			ft_print_to_procent(const char *format, t_args *args);

#endif