/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddingleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:49:42 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 11:54:03 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*fill(char *res, t_print tmp, int k, int l)
{
	while (++k < tmp.padding - ft_strlen(tmp.str))
		res[k] = ' ';
	while (k < tmp.padding && l != -5)
		res[k++] = tmp.str[l++];
	res[k] = '\0';
	return (res);
}

static char	*padsuptypes(int k, t_print tmp)
{
	char	*res;

	if (tmp.precision >= tmp.in_len)
	{
		tmp.precision = tmp.padding;
		return (ft_paddingleft(tmp, tmp.padding, 0));
	}
	res = ft_strdup(tmp.str);
	k = tmp.precision;
	while (k < tmp.in_len)
		res[k++] = '\0';
	return (res);
}

static char	*padsuplen(t_print tmp, int k, int l, int f)
{
	char	*res;

	if (tmp.precision > 0 && tmp.precision < tmp.padding && tmp.type == 's')
		return (padsuptypes(k, tmp));
	else
	{
		res = malloc(sizeof(char) * tmp.padding + 2);
		if (!res)
			return (0);
	}
	if (tmp.in_len == 1 && tmp.str[0] == '0' && tmp.precision == 0)
	{
		tmp.padding++;
		l = -5;
	}
	res = fill(res, tmp, k, l);
	if (f == 1 || tmp.type != 's')
		free(tmp.str);
	return (res);
}

char	*ft_paddingleft(t_print tmp, int padding, int f)
{
	int		k;
	int		l;
	char	*res;

	k = -1;
	l = 0;
	if (padding > ft_strlen(tmp.str))
		res = padsuplen(tmp, k , l, f);
	else
		return (tmp.str);
	return (res);
}