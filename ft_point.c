/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:24:23 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/24 12:37:23 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


static void	fillchar(char **res)
{
	(*res)[0] = '0';
	(*res)[1] = 'x';
}

char	*ft_point(uintmax_t a)
{
	char			*res;
	char			*str;
	int				i;
	int				j;

	str = ft_converpoint(a);
	res = malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!res)
		return (0);
	i = -1;
	j = 1;
	fillchar(&res);
	if (a == 0)
	{
		free(str);
		res[2] = '0';
		res[3] = '\0';
		return (res);
	}
	while (str[++i])
		res[++j] = str[i];
	res[++j] = '\0';
	free(str);
	return (res);
}
