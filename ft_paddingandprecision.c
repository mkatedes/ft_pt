/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddingandprecision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:49:52 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/26 13:52:02 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	tmp0(t_print *tmp)
{
	if (tmp->precision > 0 && tmp->type != '%')
		tmp->str = ft_precision(*tmp);
}

int	ft_paddingandprecision(int *x, int *cmp, t_print *tmp)
{
	if (tmp->padding_char == '0')
		tmp->str = ft_conv0(*tmp);
	else if (tmp->padding_char == '1')
		tmp->str = ft_paddingleft(*tmp, tmp->padding, 0);
	else if (tmp->padding_char == '-')
		tmp->str = ft_paddingright(*tmp, tmp->padding);
	else if (tmp->padding_char == '.')
		tmp->str = ft_conv0(*tmp);
	tmp0(tmp);
	if (tmp->precision == 0 && tmp->padding > 0 && tmp->type == 'd')
	{
		if (tmp->str[0] == '0')
		{
			*x = -1;
			while (++(*x) < tmp->padding)
				write(1, " ", 1);
			free(tmp->str);
			*cmp += *x;
			return (0);
		}
		else
			tmp->precision++;
	}
	return (1);
}
