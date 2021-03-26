/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:49:15 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 12:16:24 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*padcharnum(int x, t_print tmp)
{
	x = tmp.padding - tmp.precision - 1;
	if (tmp.str[tmp.padding - tmp.in_len] == '-')
	{
		if (tmp.in_len > tmp.precision)
			return (tmp.str);
		tmp.str[x] = '-';
		tmp.padding++;
	}
	while (++x < tmp.padding - tmp.in_len)
		tmp.str[x] = '0';
	return (tmp.str);
}

static char	*precisioninf(t_print tmp, int p, int x)
{
	if (tmp.padding_char == '0')
	{
		if (tmp.str[0] == '-')
		{
			if (tmp.in_len <= p)
				tmp.str[ft_strlen(tmp.str) - p - 1] = '-';
			else
				tmp.str[ft_strlen(tmp.str) - tmp.in_len] = '-';
			p++;
		}
		if (tmp.in_len <= p)
			while (++x < ft_strlen(tmp.str) - p)
				tmp.str[x] = ' ';
		else
			while (++x < ft_strlen(tmp.str) - tmp.in_len)
				tmp.str[x] = ' ';
	}
	else if (tmp.padding_char == '1')
		tmp.str = padcharnum(x, tmp);
	else if (tmp.padding_char == '-')
		tmp.str = ft_displate(tmp);
	return (tmp.str);
}

static char	*precisionsuptyped(int p, int x, t_print tmp)
{
	char	*res;

	if (tmp.padding > tmp.in_len && tmp.padding_char != '-')
		p = tmp.padding - tmp.in_len;
	else
		p = 0;
	res = malloc(sizeof(char) * tmp.precision + 2);
	if (!res)
		return (0);
	if (tmp.str[p] == '-' || tmp.str[0] == '-')
	{
		res[++x] = '-';
		p++;
		tmp.precision++;
		while (++x <= tmp.precision - tmp.in_len)
			res[x] = '0';
	}
	else
		while (++x < tmp.precision - tmp.in_len)
			res[x] = '0';
	while (x < tmp.precision)
		res[x++] = tmp.str[p++];
	res[x] = '\0';
	free(tmp.str);
	return (res);
}

static char	*precisionsup(int p, int x, t_print tmp)
{
	if (p <= tmp.padding && tmp.type == 's' && p < tmp.in_len
		&& tmp.padding_char == '1')
	{
		tmp.str = ft_displate(tmp);
		while (++x < tmp.padding - tmp.precision)
			tmp.str[x] = ' ';
		tmp.str[tmp.padding] = '\0';
	}
	else if (p < tmp.padding && tmp.type == 's' && p < tmp.in_len
		&& tmp.padding_char == '-')
	{
		x = tmp.precision - 1;
		while (++x < tmp.padding)
			tmp.str[x] = ' ';
		tmp.str[tmp.padding] = '\0';
	}
	else if (tmp.type == 'd')
		tmp.str = precisionsuptyped(p, x, tmp);
	return (tmp.str);
}

char	*ft_precision(t_print tmp)
{
	int		p;
	int		x;

	p = tmp.precision;
	x = -1;
	if (ft_strlen(tmp.str) == tmp.precision && tmp.type != 'd')
	{
		tmp.precision = tmp.padding;
		return (ft_paddingleft(tmp, tmp.padding, 0));
	}
	if (p >= ft_strlen(tmp.str) || tmp.type == 's')
		return (precisionsup(p, x, tmp));
	else
		return (precisioninf(tmp, p, x));
}
