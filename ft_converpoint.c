/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converpoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:38:28 by mkomadin          #+#    #+#             */
/*   Updated: 2021/04/06 17:38:30 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_uitoahex(unsigned long long nb, int len, char **res)
{
	char	*hex;

	hex = "0123456789abcdef";
	(*res)[--len] = hex[nb % 16];
	nb /= 16;
	if (nb > 0)
		ft_uitoahex(nb, len, res);
}

char	*ft_converpoint(unsigned long long nbr)
{
	char				*res;
	int					i;
	unsigned long long	tmp;

	tmp = nbr;
	i = 0;
	while (tmp > 0)
	{
		tmp /= 16;
		i++;
	}
	res = malloc(sizeof(char) * i);
	if (!res)
		return (0);
	ft_uitoahex(nbr, i, &res);
	res[i] = '\0';
	return (res);
}
