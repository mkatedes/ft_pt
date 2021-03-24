/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:59:43 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/24 12:08:44 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*typed(t_print *tmp, char *res, int *i, int *p)
{
	if (tmp->str[0] == '-')
	{
		res[0] = '-';
		(*i)++;
		tmp->precision += 2;
		(*p)++;
	}
	while (++(*i) < tmp->precision - tmp->in_len)
		res[(*i)] = '0';
	return (res);
}

char	*ft_displate(t_print tmp)
{
	char	*res;
	int		i;
	int		p;

	i = -1;
	p = -1;
	res = malloc(sizeof(char) * ft_strlen(tmp.str));
	if (!res)
		return (0);
	if (tmp.type == 'd')
		res = typed(&tmp, res, &i, &p);
	else
		while (++i < tmp.padding - tmp.precision)
			res[i] = '0';
	while (i < ft_strlen(tmp.str))
	{
		res[i] = tmp.str[++p];
		i++;
	}
	res[i] = '\0';
	free(tmp.str);
	return (res);
}
