/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:55:40 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/24 14:25:28 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			g_free;

int			ft_printf(const char *tab, ...)
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
			if (tmp.padding == -2 && tmp.precision)
			{
				va_arg(valist, int);
				continue ;
			}
			if (tmp.padding_char == '0' && tab[i] == '0')
			{
				if (tab[i + 1] == 'd' || tab[i + 1] == 'i' || tab[i + 1] == 'x'
						|| tab[i + 1] == 'X' || tab[i + 1] == 'c')
					tmp.type = tab[++i];
			}
			if (tmp.padding_char == '-' && tab[i] == '-')
			{
				i++;
				ft_getpadding(tab, &i, &tmp);
				if (tab[i] == '.')
				{
					i++;
					if (tab[i] == '-')
						i++;
					while (ft_isdigit(tab[i]))
						i++;
				}
			}
			tmp.type = tab[i];
			tmp.str = ft_vatochar(valist, tab[i], &tmp);
			if (x == -7 && tmp.type == 's')
				tmp.padding_char = '-';
			if (tmp.type == 'c' && tmp.str[0] == 0)
			{
				if (tmp.padding > 0)
					tmp.padding--;
				if (tmp.precision > 0)
					tmp.precision--;
				x = -10;
			}
			if (x == -5)
			{
				tmp.padding = -1;
				tmp.precision = -1;
			}
			if (tmp.type == 'i' || tmp.type == 'u' || tmp.type == 'x' || tmp.type == 'X')
			{
				tmp.typeb = tmp.type;
				if (tmp.typeb == 'X')
					tmp.typeb = 'x';
				tmp.type = 'd';
			}
			if (!tmp.str)
			{
				free(tmp.str);
				tmp.str = "(null)";
				if (tmp.type == '.')
					va_arg(valist, int);
			}
			if (tmp.type == '.')
			{
				while (tmp.padding--)
				{
					write(1, " ", 1);
					cmp++;
				}
				i++;
				continue ;
			}
			tmp.in_len = ft_strlen(tmp.str);
			if (tmp.padding_char == '0')
				tmp.str = ft_conv0(tmp);
			else if (tmp.padding_char == '1')
				tmp.str = ft_paddingleft(tmp, tmp.padding, 0);
			else if (tmp.padding_char == '-')
				tmp.str = ft_paddingright(tmp, tmp.padding);
			else if (tmp.padding_char == '.')
				tmp.str = ft_conv0(tmp);
			if (tmp.precision > 0 && tmp.type != '%')
				tmp.str = ft_precision(tmp);
			if (tmp.precision == 0 && tmp.padding > 0 && tmp.type == 'd')
			{
				if (tmp.str[0] == '0')
				{
					x = -1;
					while (++x < tmp.padding)
						write(1, " ", 1);
					free(tmp.str);
					cmp += x;
					continue ;
				}
				else
					tmp.precision++;
			}
			if (tmp.type == 'c' && tmp.str[tmp.padding] == 0 && tmp.padding_char == '-'
					&& x == -10)
			{
				cmp++;
				write(1, "\0", 1);
			}
			if (tmp.precision != 0)
				ft_putstr(tmp.str);
			else
			{
				if (tmp.padding > 0)
				{
					x = -1;
					while (++x < tmp.padding)
						write(1, " ", 1);
				}
			}
			cmp += ft_strlen(tmp.str);
			if (tmp.type == 'c' && tmp.str[tmp.padding] == 0 && tmp.padding_char != '-'
					&& x == -10)
			{
				cmp++;
				write(1, "\0", 1);
			}
			if (tmp.type == 's')
			{
				if (tmp.padding_char != '%')
				{
					if ((tmp.padding > tmp.in_len) || 
							(tmp.padding != -1 && tmp.precision != -1) || 
							(tmp.padding_char == '.' && tmp.padding <= tmp.in_len && tmp.padding > 0)
							|| tmp.padding == -2)
					{
						free(tmp.str);
					}
				}
			}
			else
			{
				if (tmp.padding != 0 || (tmp.padding == 0 && tmp.padding_char == '-') || ft_atoi(tmp.str) > 0
						|| (tmp.typeb == 'x' && tmp.precision > 0 && tmp.padding > 0))
					free(tmp.str);
			}
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
