/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkstar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:05:44 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 10:51:30 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*init(int *k, int *j, char *tab, char *tmp)
{
	char	*res;

	res = malloc(sizeof(char) * ft_strlen(tab) + ft_strlen(tmp) + 1);
	if (res == NULL)
		return (0);
	*j = -1;
	*k = -1;
	return (res);
}

static char	*replace(char *tab, char *tmp, int ii, int *g_free)
{
	int		j;
	int		k;
	char	*res;

	res = init(&k, &j, tab, tmp);
	while (tab[++j])
	{		
		if (j == ii)
		{
			ii = -1;
			while (tmp[++ii])
				res[++k] = tmp[ii];
			ii = 0;
		}
		else
			res[++k] = tab[j];
	}
	res[++k] = '\0';
	if (*g_free > 0)
	{
		(*g_free)--;
		free(tab);
	}
	return (res);
}

char	*ft_checkstar(char *tab, int *i, va_list valist, int *g_free)
{
	char	*tmp;
	char	*res;
	int		ii;

	ii = *i;
	while (tab[ii] != 'u' && tab[ii] != 'd' && tab[ii] != 'i' && tab[ii] != 'x'
		&& tab[ii] != 'X' && tab[ii] != 'c' && tab[ii] != 's'
		&& tab[ii] != '%' && tab[ii] != 'p')
	{
		if (tab[ii] == '*')
		{
			tmp = ft_itoa(va_arg(valist, int));
			res = replace(tab, tmp, ii, g_free);
			while (res[ii] != '%')
				ii--;
			(*g_free)++;
			(*i) = ii - 1;
			if (*i < 0)
				(*i) = -1;
			free(tmp);
			return (res);
		}
		ii++;
	}
	return (tab);
}
