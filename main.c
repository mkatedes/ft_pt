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
#include <limits.h>
#include <stdio.h>

int main()
{
	int e = ft_printf("%% *.5i 42 == |% *d|\n", 6, 4222);

	int r = printf("%% *.5i 42 == |% *d|\n", 6, 4222);
	printf("|%d %d|", e, r);


	/*while (1)
		;*/
	return 0;
}
