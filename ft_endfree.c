/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:16:22 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 14:18:48 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	checkandprint2(t_print tmp, int *cmp, int *x)
{
	if (tmp.str[0] != '0' && tmp.typeb == 'x' && tmp.padding == 0
		&& tmp.precision == -1 && tmp.in_len == 1 && !ft_isdigit(tmp.str[0]))
		(*cmp)++;
	if ((tmp.padding == 0 && tmp.precision == -1 && ft_atoi(tmp.str) == 0)
		|| (tmp.str[0] == '0' && tmp.typeb == 'x' && tmp.padding == 0
			&& tmp.precision == -1))
		return ;
	(*cmp) += ft_strlen(tmp.str);
	if (tmp.type == 'c' && tmp.str[tmp.padding] == 0
		&& tmp.padding_char != '-' && *x == -10)
	{
		(*cmp)++;
		write(1, "\0", 1);
	}
}

void	ft_checkandprint(int *cmp, int *x, t_print tmp)
{
	if (tmp.type == 'c' && tmp.str[tmp.padding] == 0
		&& tmp.padding_char == '-' && *x == -10)
	{
		(*cmp)++;
		write(1, "\0", 1);
	}
	if (((tmp.precision != 0 && !(tmp.type == 'd'
					&& ft_atoi(tmp.str) == 0 && tmp.padding == 0))
			|| (tmp.str[0] != '0' && tmp.typeb == 'x'))
		&& !(tmp.padding_char == '.' && tmp.padding == 0
			&& tmp.type == 's'))
		ft_putstr(tmp.str);
	else
	{
		if (tmp.padding > 0)
		{
			*x = -1;
			while (++(*x) < tmp.padding)
				write(1, " ", 1);
		}
	}
	checkandprint2(tmp, cmp, x);
}

static void	endfreecases(t_print *tmp)
{
	if (tmp->padding_char != '%')
	{
		if (tmp->padding < tmp->in_len && tmp->precision >= tmp->in_len)
			return ;
		if ((tmp->padding > tmp->in_len)
			|| (tmp->padding != -1 && tmp->precision != -1
				&& tmp->in_len != tmp->padding)
			|| (tmp->padding_char == '.' && tmp->padding <= tmp->in_len
				&& tmp->padding > 0) || tmp->padding == -2
			|| (tmp->precision > tmp->in_len && tmp->precision > 0)
			|| (tmp->precision > 0 && tmp->precision != tmp->in_len))
			free(tmp->str);
	}
}

void	ft_endfree(t_print *tmp)
{
	if (tmp->type == 's')
		endfreecases(tmp);
	else
	{
		if (tmp->padding != 0 || tmp->type == 'p'
			|| (tmp->padding == 0 && tmp->padding_char == '-')
			|| ft_atoi(tmp->str) > 0
			|| (tmp->typeb == 'x' && tmp->precision > 0
				&& tmp->padding > 0)
			|| (tmp->typeb == 'x' && tmp->str[0] != '0' && tmp->padding == 0
				&& tmp->precision == -1))
			free(tmp->str);
	}
}
