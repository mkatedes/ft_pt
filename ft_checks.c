/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:26:12 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 16:30:21 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_fristcheck(t_print *tmp, int *i, va_list valist, const char *tab)
{
	if (tmp->padding == -2 && tmp->precision)
	{
		va_arg(valist, int);
		return (0);
	}
	if (tmp->padding_char == '0' && tab[*i] == '0')
	{
		if (tab[*i + 1] == 'd' || tab[*i + 1] == 'i' || tab[*i + 1] == 'x'
			|| tab[*i + 1] == 'X' || tab[*i + 1] == 'c')
			tmp->type = tab[++(*i)];
	}
	if (tmp->padding_char == '-' && tab[*i] == '-')
	{
		(*i)++;
		ft_getpadding(tab, i, tmp);
		if (tab[*i] == '.')
		{
			(*i)++;
			if (tab[*i] == '-')
				(*i)++;
			while (ft_isdigit(tab[*i]))
				(*i)++;
		}
	}
	return (1);
}

void	ft_secondcheck(t_print *tmp, int *x, va_list valist)
{
	if (tmp->type == 'c' && tmp->str[0] == 0)
	{
		if (tmp->padding > 0)
			tmp->padding--;
		if (tmp->precision > 0)
			tmp->precision--;
		*x = -10;
	}
	if (tmp->type == 'i' || tmp->type == 'u'
		|| tmp->type == 'x' || tmp->type == 'X')
	{
		tmp->typeb = tmp->type;
		if (tmp->typeb == 'X')
			tmp->typeb = 'x';
		tmp->type = 'd';
	}
	if (!tmp->str)
	{
		free(tmp->str);
		tmp->str = "(null)";
		if (tmp->type == '.')
			va_arg(valist, int);
	}
}

int	ft_thirdcheck(int *x, int *cmp, int *i, t_print *tmp)
{
	if (*x == -5)
	{
		tmp->padding = -1;
		tmp->precision = -1;
	}
	if (tmp->type == '.')
	{
		while (tmp->padding--)
		{
			write(1, " ", 1);
			(*cmp)++;
		}
		(*i)++;
		return (0);
	}
	if (ft_paddingandprecision(x, cmp, tmp) == 0)
		return (0);
	return (1);
}
