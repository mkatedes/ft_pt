/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:35:38 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 11:15:00 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

static int	padcharzero(t_print *res, int *i)
{
	(*i) += 2;
	res->precision = 1;
	res->padding_char = '-';
	return (0);
}

static int	padcharpoint(const char *tab, t_print *res, int *i)
{
	++(*i);
	if (tab[*i] == '-')
	{
		res->padding = 1;
		res->precision = 1;
		return (2);
	}
	else if (!ft_isdigit(tab[(*i) + 1]))
		res->padding = -2;
	else
		res->padding = 0;
	return (0);
}

static int	checkzero(t_print *res, int *i, const char *tab, int *k)
{
	while (ft_isdigit(tab[++(*i)]))
		(*k)++;
	if (*k != 0)
		return (0);
	--(*i);
	if (res->padding_char == '.')
	{
		if (padcharpoint(tab, res, i) > 0)
			return (2);
	}
	else if (res->padding_char == '0' && tab[(*i) + 1] == '-')
		return (padcharzero(res, i));
	else if (res->padding_char == '0' && tab[(*i) + 1] == '.')
	{
		if (ft_isdigit(tab[(*i) + 2]))
			return (0);
		(*i) += 2;
		res->padding = -2;
		res->precision = -2;
	}
	else
		res->padding = -1;
	return (1);
}

static int	getatoi(int k, int p, int *i, const char *tab)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * k + 1);
	if (!tmp)
		return (0);
	p = -1;
	*i -= k;
	while (ft_isdigit(tab[(*i)]))
		tmp[++p] = tab[(*i)++];
	tmp[++p] = '\0';
	k = ft_atoi(tmp);
	free(tmp);
	return (k);
}

int	ft_getpadding(const char *tab, int *i, t_print *res)
{
	int	p;
	int	k;

	k = 0;
	res->padding_char = tab[(*i)];
	if (ft_isdigit(tab[(*i)]) && tab[(*i)] != '0')
	{
		res->padding_char = '1';
		(*i)--;
	}
	p = checkzero(res, i, tab, &k);
	if (p > 0)
	{
		if (p == 2)
		{
			(*i)++;
			while (ft_isdigit(tab[(*i)]))
				(*i)++;
		}
		return (p);
	}
	res->padding = getatoi(k, p, i, tab);
	return (1);
}
