/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:21:34 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 11:21:51 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_getprecision(const char *tab, int *i)
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
	tmp = malloc(sizeof(char) * p + 1);
	if (!tmp)
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
