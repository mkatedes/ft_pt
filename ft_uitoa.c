/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:07:42 by mkomadin          #+#    #+#             */
/*   Updated: 2020/12/18 14:43:19 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*ft_uitoa(unsigned int n)
{
	int				count;
	long			tmp;
	char			*res;

	tmp = n;
	count = 1;
	while ((tmp /= 10) > 0)
		count++;
	if (!(res = malloc(sizeof(*res) * count + 1)))
		return (0);
	res[count] = '\0';
	tmp = n;
	if (tmp == 0)
		res[0] = '0';
	while (tmp > 0)
	{
		res[--count] = (char)(48 + tmp % 10);
		tmp /= 10;
	}
	return (res);
}
