/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:50:09 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/17 16:18:12 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*padsuplen(char *res, t_print tmp)
{
	int		k;
	int		l;
	int		j;

	k = -1;
	l = 0;
	j = tmp.padding;
	res[j] = '\0';
	if (tmp.str[0] == '-')
	{
		if (tmp.precision == 0 && tmp.type == 'd')
		{
			l--;
			j--;
		}
		else
			res[++k] = '-';
		l++;
		j++;
		if (tmp.padding_char == '.')
			j++;
	}
	if (tmp.precision == 0 && tmp.type == 'd')
		while (++k < j - ft_strlen(tmp.str))
			res[k] = ' ';
	else
	{
		while (++k < j - ft_strlen(tmp.str) && tmp.type != 's')
			res[k] = '0';
	}
	while (k < j)
		res[k++] = tmp.str[l++];
	if (tmp.precision == 0 && ((ft_atoi(tmp.str) == 0 && tmp.typeb != 'x')
		   	|| (tmp.typeb == 'x' && tmp.str[0] == '0')))
		res[k - 1] = ' ';
	res[k] = '\0';
	if (tmp.type != 's')
		free(tmp.str);
	return (res);
}

char		*ft_conv0(t_print tmp)
{
	char	*res;

	if (tmp.padding == 0)
	{
		if (ft_atoi(tmp.str) != 0)
			return (tmp.str);
		if (tmp.typeb == 'x' && tmp.str[0] != '0')
			return (tmp.str);
		if (tmp.type != 's')
			free(tmp.str);
		return ("");
	}
	if (tmp.padding > ft_strlen(tmp.str))
	{
		if (!(res = malloc(sizeof(char) * tmp.padding + 1)))
			return (0);
		res = padsuplen(res, tmp);
	}
	else
	{
		if (tmp.type == 's')
		{
			if (!(res = malloc(sizeof(char) * tmp.padding + 1)))
				return (0);
			ft_strlcpy(res, tmp.str, tmp.padding + 1);
			return (res);
		}
		return (tmp.str);
	}
	return (res);
}
