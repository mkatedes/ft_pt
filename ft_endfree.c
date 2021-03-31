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

void	ft_checkandprint(int *cmp, int *x, t_print tmp)
{
	if (tmp.type == 'c' && tmp.str[tmp.padding] == 0
		&& tmp.padding_char == '-' && *x == -10)
	{
		(*cmp)++;
		write(1, "\0", 1);
	}
	if (tmp.precision != 0 && !(tmp.type == 'd'
			&& ft_atoi(tmp.str) == 0 && tmp.padding == 0))
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
	if (tmp.padding == 0 && tmp.precision == -1 && ft_atoi(tmp.str) == 0)
		return ;
	(*cmp) += ft_strlen(tmp.str);
	if (tmp.type == 'c' && tmp.str[tmp.padding] == 0
		&& tmp.padding_char != '-' && *x == -10)
	{
		(*cmp)++;
		write(1, "\0", 1);
	}
}

void	ft_endfree(t_print *tmp)
{
	if (tmp->type == 's')
	{
		if (tmp->padding_char != '%')
		{
			if ((tmp->padding > tmp->in_len)
				|| (tmp->padding != -1 && tmp->precision != -1 && tmp->in_len != tmp->padding)
				|| (tmp->padding_char == '.' && tmp->padding <= tmp->in_len
					&& tmp->padding > 0) || tmp->padding == -2
				|| (tmp->precision > tmp->in_len && tmp->precision > 0)
				|| (tmp->precision > 0 && tmp->precision != tmp->in_len))
				free(tmp->str);
		}
	}
	else
	{
		if (tmp->padding != 0
			|| (tmp->padding == 0 && tmp->padding_char == '-')
			|| ft_atoi(tmp->str) > 0
			|| (tmp->typeb == 'x' && tmp->precision > 0
				&& tmp->padding > 0))
			free(tmp->str);
	}
}
