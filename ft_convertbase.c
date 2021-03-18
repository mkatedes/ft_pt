/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:41:42 by mkomadin          #+#    #+#             */
/*   Updated: 2021/02/10 15:22:47 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_itoahex(long nb, int len, char **res)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb < 0)
	{
		(*res)[0] = '-';
		nb *= -1;
	}
	(*res)[--len] = hex[nb % 16];
	nb /= 16;
	if (nb > 0)
		ft_itoahex(nb, len, res);
}

char		*ft_convertbase(int nbr)
{
	char	*res;
	int		i;
	long	tmp;

	tmp = nbr;
	i = 0;
	if (tmp <= 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp > 0)
	{
		tmp /= 16;
		i++;
	}
	if (!(res = malloc(sizeof(char) * i)))
		return (0);
	ft_itoahex((long)nbr, i, &res);
	res[i] = '\0';
	return (res);
}

char		*ft_convertbase3(unsigned int nbr)
{
	char	*res;
	int		i;
	long	tmp;

	tmp = nbr;
	i = 0;
	if (tmp < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp > 0)
	{
		tmp /= 16;
		i++;
	}
	if (!(res = malloc(sizeof(char) * i)))
		return (0);
	ft_itoahex((long)nbr, i, &res);
	res[i] = '\0';
	return (res);
}
