/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:55:40 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 16:42:23 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			g_free;

static void	init(int *i, int *cmp)
{
	g_free = 0;
	*i = -1;
	*cmp = 0;
}

static void	normalprint(int *cmp, int i, const char *tab)
{
	(*cmp)++;
	write(1, &tab[i], 1);
}

static int	end(int cmp, char *tab, va_list valist)
{
	if (g_free > 0)
		free((char *)tab);
	va_end(valist);
	return (cmp);
}

static int	ifcontinue(int res)
{
	int	k;

	if (res == 0)
		k = 0;
	else if (res == -1)
	{
		g_free++;
		k = 0;
	}
	else
		k = 1;
	return (k);
}

int	ft_printf(const char *tab, ...)
{
	va_list		valist;
	int			cmp;
	int			res;
	int			i;
	int			x;

	init(&i, &cmp);
	va_start(valist, tab);
	while (tab[++i])
	{
		if (tab[i] == '%')
		{
			i++;
			x = i;
			tab = ft_checkstar((char *)tab, &i, valist, &g_free);
			if (x > i)
				continue ;
			res = ft_procesprint(&cmp, &i, tab, valist);
			if (ifcontinue(res) == 0)
				continue ;
		}
		else
			normalprint(&cmp, i, tab);
	}
	return (end(cmp, (char *)tab, valist));
}
