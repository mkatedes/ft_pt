/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:21:59 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/24 14:27:42 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init(int n, long tmp, int *count)
{
	tmp = n;
	if (n >= 0)
		*count = 0;
	else
		*count = 1;
	if (n < 0)
		(tmp) *= -1;
	while ((tmp) > 0)
	{
		tmp /= 10;
		(*count)++;
	}
}

char	*ft_itoa(int n)
{
	int		count;
	long	tmp;
	char	*res;

	tmp = 0;
	init(n, tmp, &count);
	res = malloc(sizeof(*res) * count + 1);
	if (!res)
		return (0);
	res[count] = '\0';
	tmp = n;
	if (tmp < 0)
	{
		tmp *= -1;
		res[0] = '-';
	}
	if (tmp == 0)
		res[0] = '0';
	while (tmp > 0)
	{
		res[--count] = (char)(48 + tmp % 10);
		tmp /= 10;
	}
	return (res);
}
