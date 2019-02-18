/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:40:09 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/07 14:40:13 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	//char str[] = "kek";
	//char rts[] = "lol";
	char tst;

	tst = 75;
	/*while (tst <= 100)
	{
		printf("ASCII number: %d Character: %c\n", tst, tst);
		tst++;
	}*/
	/*printf("%-#012.12hd\n", 1);
	printf("%d\n", ft_printf("Print this %-#012.12hd\n ", 1));
	printf("%d\n", printf("Print this %-#012.12hd\n ", 1));
	printf("%12.12c\n", 'c');*/
	//printf("%%");
	//printf("%.2d\n", 123456);
	/*printf("%5d\n", 1);
	printf("%5c\n", 'c');*/
	printf("Print this boi %\n");
	ft_printf("Print this boi %\n");
	printf("Print this boi %%\n");
	ft_printf("Print this boi %%\n");
	printf("Print this boi %c\n", 'c');
	ft_printf("Print this boi %c\n", 'c');
	printf("Print this boi %010c\n", 'c');
	ft_printf("Print this boi %010c\n", 'c');
	printf("Print this boi %-010c\n", 'c');
	ft_printf("Print this boi %-010c\n", 'c');
	printf("Print this boi %-10c\n", 'c');
	ft_printf("Print this boi %-10c\n", 'c');
	printf("Print this boi %10c\n yeah boiiiiiii\n", 'c');
	ft_printf("Print this boi %10c\n yeah boiiiiiii\n", 'c');
	/*printf("\n");
	printf("\n");
	printf("Print this boi %-10c\n yeah boiiiiiii", 'c');
	printf("Print this boi %-10c\n yeah boiiiiiii", 'c');
	printf("\n");
	printf("\n");
	ft_printf("Print this boi %c\n yeah boiiiiiii", 'c');
	ft_printf("Print this boi %c\n yeah boiiiiiii", 'c');*/
	/*printf("%12d\n", tst);
	printf("%012d\n", tst);
	printf("% 012d\n", tst);
	printf("%+12d\n", tst);
	printf("%+012d\n", tst);
	printf("%-12d\n", tst);
	printf("%- 12d\n", tst);
	printf("%-+12d\n", tst);
	printf("%12.4d\n", tst);
	printf("%-12.4d\n", tst);*/
	return (0);
}
