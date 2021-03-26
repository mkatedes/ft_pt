/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procesprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:39:13 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 16:43:49 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init(int *x, int *i, int *cmp, t_print *tmp)
{
	*x = *i;
	*cmp = 0;
	tmp->precision = 0;
	tmp->typeb = '0';
}

static int	checkempty(int *cmp, int *i, int *x, const char *tab)
{
	if (tab[*i] == '%')
	{
		(*cmp)++;
		ft_putstr("%");
		return (0);
	}
	if (tab[*i] == ' ' && *i >= *x)
	{
		write(1, " ", 1);
		(*i)++;
		(*cmp)++;
	}
	if (*i < *x)
		return (-1);
	return (1);
}

int	ft_procesprint(int *cmp, int *i, const char *tab, va_list valist)
{
	int		x;
	t_print	tmp;

	init(&x, i, cmp, &tmp);
	if (checkempty(cmp, i, &x, tab) == 0)
		return (0);
	if (ft_getpadding(tab, i, &tmp) != 2)
		tmp.precision = ft_getprecision(tab, i);
	else
		x = -7;
	if (ft_fristcheck(&tmp, i, valist, tab) == 0)
		return (0);
	tmp.type = tab[*i];
	tmp.str = ft_vatochar(valist, tab[*i], &tmp);
	if (x == -7 && tmp.type == 's')
		tmp.padding_char = '-';
	ft_secondcheck(&tmp, &x, valist);
	if (ft_thirdcheck(&x, cmp, i, &tmp) == 0)
		return (0);
	ft_checkandprint(cmp, &x, tmp);
	ft_endfree(tmp);
	return (1);
}
