/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:35:38 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/08 13:35:08 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	checkzero(t_print *res, int *i, const char *tab, int *k)
{
	while (ft_isdigit(tab[++(*i)]))
		(*k)++;
	if (*k == 0)
	{
		--(*i);
		if (res->padding_char == '.')
		{
			++(*i);
			if (tab[*i] == '-')
			{
				res->padding = 1;
				res->precision = 1;
				return (2);
			}
			else
				res->padding = 0;
		}
		else if (res->padding_char == '0' && tab[(*i) + 1] == '-')
		{
			(*i) += 2;
			res->precision = 1;
			res->padding_char = '-';
			return (0);
		}
		else
			res->padding = -1;
		return (1);
	}
	else
		return (0);
}

int			ft_getpadding(const char *tab, int *i, t_print *res)
{
	int		p;
	int		k;
	char	*tmp;

	k = 0;
	res->padding_char = tab[(*i)];
	if (ft_isdigit(tab[(*i)]) && tab[(*i)] != '0')
	{
		res->padding_char = '1';
		(*i)--;
	}
	if ((p = checkzero(res, i, tab, &k)) > 0)
	{
		if (p == 2)
		{
			(*i)++;
			while (ft_isdigit(tab[(*i)]))
				(*i)++;
		}
		return (p);
	}
	if (!(tmp = malloc(sizeof(char) * k + 1)))
		return (0);
	p = -1;
	*i -= k;
	while (ft_isdigit(tab[(*i)]))
		tmp[++p] = tab[(*i)++];
	tmp[++p] = '\0';
	k = ft_atoi(tmp);
	free(tmp);
	res->padding = k;
	return (1);
}
