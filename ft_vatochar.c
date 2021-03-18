/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vatochar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:54:17 by mkomadin          #+#    #+#             */
/*   Updated: 2021/02/24 11:43:01 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*casec(t_print *tmp, va_list valist)
{
	char	*a;
	int		t;

	if (!(a = malloc(sizeof(char) * 2)))
		return (0);
	t = va_arg(valist, int);
	a[0] = t;
	a[1] = '\0';
	if (!tmp->padding)
		tmp->padding = 1;
	return (a);
}

static char		*casepercent(t_print *tmp)
{
	char	*a;

	if (!(a = malloc(sizeof(char) * 2)))
		return (0);
	a[0] = '%';
	a[1] = '\0';
	if (!tmp->padding)
		tmp->padding = 1;
	tmp->precision = 1;
	return (a);
}

static char		*caselowerx(va_list valist)
{
	int		res;

	res = va_arg(valist, int);
	if ((unsigned)res > 2147483647)
		return (ft_convertbase3(res));
	return (ft_convertbase(res));
}

static char		*caseupperx(va_list valist)
{
	int		res;

	res = va_arg(valist, int);
	if ((unsigned)res > 2147483647)
		return (ft_convertbase4(res));
	return (ft_convertbase2(res));
}

char			*ft_vatochar(va_list valist, char c, t_print *tmp)
{
	if (c == 'c')
		return (casec(tmp, valist));
	else if (c == '%')
		return (casepercent(tmp));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(valist, int)));
	else if (c == 's')
		return (va_arg(valist, char *));
	else if (c == 'p')
		return (ft_point(va_arg(valist, int)));
	else if (c == 'u')
		return (ft_uitoa(va_arg(valist, unsigned int)));
	else if (c == 'x')
		return (caselowerx(valist));
	else if (c == 'X')
		return (caseupperx(valist));
	return (0);
}
