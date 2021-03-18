/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:09:59 by mkomadin          #+#    #+#             */
/*   Updated: 2021/02/03 14:12:19 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*res;

	if (!(res = malloc(sizeof(char) * ft_strlen(s1))))
		return (0);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[++i] = '\0';
	return (res);
}
