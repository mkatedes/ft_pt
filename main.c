/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:38:24 by mkomadin          #+#    #+#             */
/*   Updated: 2021/04/01 12:02:11 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main()
{

	unsigned int a;
	a = 4294967295;

	//ft_printf(" %c%%c%%s%%p%%d%%i%%u%%x%%X%%p%p\n", 0, (void *)42);
/*	ft_printf(" %10p \n", (void *)(-214));
	printf(" %10p \n", (void *)(-214));*/
	printf("%-5.0x\n", 0);
	ft_printf("%-5.0x\n", 0);
	/*while (1)
		;*/
	return 0;
}
