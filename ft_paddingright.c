/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddingright.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:43:45 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/24 12:35:38 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*padinflen(t_print tmp)
{
	if (tmp.precision > 0)
		return (ft_strdup(tmp.str));
	else
		return (tmp.str);
}

char	*ft_paddingright(t_print tmp, int padding)
{
	int		k;
	int		l;
	char	*res;

	k = -1;
	if (padding > ft_strlen(tmp.str))
	{
		res = malloc(sizeof(char) * (padding + 2));
		if (!res)
			return (0);
		l = -1;
		if (tmp.in_len == 1 && tmp.str[0] == '0' && tmp.precision == 0)
			l = -5;
		while (tmp.str[++l] && l != -5)
			res[++k] = tmp.str[l];
		while (++k < padding)
			res[k] = ' ';
		res[k] = '\0';
		if (tmp.type != 's')
			free(tmp.str);
	}
	else
		res = padinflen(tmp);
	return (res);
}
