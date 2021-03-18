/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:49:15 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/18 11:14:16 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_getprecision(const char *tab, int *i)
{
	char	*tmp;
	int		p;
	int		res;

	p = 0;
	while (ft_isdigit(tab[++(*i)]))
		p++;
	if (p == 0)
	{
		(*i)--;
		return (-1);
	}
	if (!(tmp = malloc(sizeof(char) * p + 1)))
		return (0);
	(*i) -= p + 1;
	p = -1;
	while (ft_isdigit(tab[++(*i)]))
		tmp[++p] = tab[(*i)];
	tmp[++p] = '\0';
	res = ft_atoi(tmp);
	free(tmp);
	return (res);
}

char		*ft_precision(t_print tmp)
{
	int		p;
	int		x;
	char	*res;

	p = tmp.precision;
	x = -1;
	if (ft_strlen(tmp.str) == tmp.precision && tmp.type != 'd')
	{
		tmp.precision = tmp.padding;
		return (ft_paddingleft(tmp, tmp.padding, 0));
	}
	if (p >= ft_strlen(tmp.str) || tmp.type == 's')
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
		{
			if (tmp.padding > tmp.in_len && tmp.padding_char != '-')
				p = tmp.padding - tmp.in_len;
			else
				p = 0;
			if (!(res = malloc(sizeof(char) * tmp.precision + 2)))
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
		return (tmp.str);
	}
	else
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
		}
		else if (tmp.padding_char == '-')
		{
			tmp.str = ft_displate(tmp);
		}
		return (tmp.str);
	}
}
