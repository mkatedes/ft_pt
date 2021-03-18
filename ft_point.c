/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:24:23 by mkomadin          #+#    #+#             */
/*   Updated: 2021/02/22 13:32:56 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	fillchar(char **res, int j)
{
	if (j == 5)
	{
		(*res)[0] = '0';
		(*res)[1] = 'x';
		(*res)[2] = '7';
		(*res)[3] = 'f';
		(*res)[4] = 'f';
		(*res)[5] = 'e';
	}
	else
	{
		(*res)[0] = '0';
		(*res)[1] = 'x';
		(*res)[2] = '1';
		(*res)[3] = '0';
	}
}

static int	initlen(int a)
{
	int len;

	if (a < 0)
		len = ft_strlen(ft_convertbase(a)) + 4;
	else
		len = ft_strlen(ft_convertbase3(a)) + 6;
	return (len);
}

static char	*case2(int *j, char **res, int a)
{
	char *str;

	*j = 3;
	fillchar(res, *j);
	str = ft_convertbase(a);
	if (a == 0)
	{
		(*res)[2] = '0';
		(*res)[3] = '\0';
		return (*res);
	}
	return (str);
}

char		*ft_point(int a)
{
	char			*res;
	char			*str;
	int				i;
	int				j;
	int				len;

	len = initlen(a);
	if (!(res = malloc(sizeof(char) * len)))
		return (0);
	i = -1;
	if (a < 0)
	{
		j = 5;
		fillchar(&res, j);
		str = ft_convertbase3(a);
	}
	else
		str = case2(&j, &res, a);
	while (str[++i])
		res[++j] = str[i];
	res[++j] = '\0';
	return (res);
}
