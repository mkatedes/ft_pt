/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:55:40 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 14:07:50 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			g_free;

static int	fristcheck(t_print *tmp, int *i, va_list valist, const char *tab)
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

static void	secondcheck(t_print *tmp, int *x, va_list valist)
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

static int	thirdcheck(int *x, int *cmp, int *i, t_print *tmp)
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

int	ft_printf(const char *tab, ...)
{
	va_list		valist;
	int			i;
	int			cmp;
	int			x;
	t_print		tmp;

	i = -1;
	g_free = 0;
	cmp = 0;
	tmp.precision = 0;
	tmp.typeb = '0';
	va_start(valist, tab);
	while (tab[++i])
	{
		if (tab[i] == '%')
		{
			x = i;
			i++;
			tab = ft_checkstar((char *)tab, &i, valist, &g_free);
			if (tab[i] == '%')
			{
				cmp++;
				ft_putstr("%");
				continue ;
			}
			if (tab[i] == ' ' && i >= x)
			{
				write(1, " ", 1);
				i++;
				cmp++;
			}
			if (i < x)
			{
				g_free++;
				continue ;
			}
			if (ft_getpadding(tab, &i, &tmp) != 2)
				tmp.precision = ft_getprecision(tab, &i);
			else
				x = -7;
			if (fristcheck(&tmp, &i, valist, tab) == 0)
				continue ;
			tmp.type = tab[i];
			tmp.str = ft_vatochar(valist, tab[i], &tmp);
			if (x == -7 && tmp.type == 's')
				tmp.padding_char = '-';
			secondcheck(&tmp, &x, valist);
			if (thirdcheck(&x, &cmp, &i, &tmp) == 0)
				continue ;
			ft_checkandprint(&cmp, &x, tmp);
			ft_endfree(tmp);
		}
		else
		{
			cmp++;
			write(1, &tab[i], 1);
		}
	}
	if (g_free > 0)
		free((char *)tab);
	va_end(valist);
	return (cmp);
}
