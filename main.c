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
	printf("%-#012.12hd\n", 1);
	printf("%d\n", ft_printf("%-#012.12hd\n", 1));
	printf("%d\n", printf("%-#012.12hd\n", 1));
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
