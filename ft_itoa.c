/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:21:59 by mkomadin          #+#    #+#             */
/*   Updated: 2021/01/29 13:59:29 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa(int n)
{
	int		count;
	long	tmp;
	char	*res;

	tmp = n;
	count = (n >= 0) ? 1 : 2;
	if (n < 0)
		tmp *= -1;
	while ((tmp /= 10) > 0)
		count++;
	if (!(res = malloc(sizeof(*res) * count + 1)))
		return (0);
	res[count] = '\0';
	tmp = n;
	if (tmp < 0)
	{
		tmp *= -1;
		res[0] = '-';
	}
	tmp *= 10;
	if (tmp == 0)
		res[0] = '0';
	while ((tmp /= 10) > 0)
		res[--count] = (char)(48 + tmp % 10);
	return (res);
}
