/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:07:42 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/24 12:18:52 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init(long *tmp, int *count, unsigned int n)
{
	*tmp = n;
	*count = 0;
}

static void	tmp0(char **res)
{
	(*res)[0] = '0';
	(*res)[1] = '\0';
}

char	*ft_uitoa(unsigned int n)
{
	int				count;
	long			tmp;
	char			*res;

	init(&tmp, &count, n);
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	res = malloc(sizeof(*res) * count + 1);
	if (!res)
		return (0);
	res[count] = '\0';
	tmp = n;
	if (tmp == 0)
		tmp0(&res);
	while (tmp > 0)
	{
		res[--count] = (char)(48 + tmp % 10);
		tmp /= 10;
	}
	return (res);
}
