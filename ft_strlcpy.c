/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:19:36 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/24 12:22:08 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlcpy(char *dst, char *src, int len)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(src);
	if (len == 0)
		return (j);
	while (src[++i] && i < len - 1)
		dst[i] = src[i];
	if (len < 0)
	{
		i = -1;
		while (++i < ft_strlen(src))
			dst[i] = src[i];
	}
	dst[i] = '\0';
	return (j);
}
