/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:03:57 by mkomadin          #+#    #+#             */
/*   Updated: 2021/03/17 17:08:14 by mkomadin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

typedef struct		s_printable
{
	char	*str;
	char	padding_char;
	char	type;
	char	typeb;
	int		precision;
	int		padding;
	int		in_len;
}					t_print;

void				ft_putchar(char a);
void				ft_putstr(char *a);
void				ft_bzero(void *a);

int					ft_printf(const char *a, ...);
int					ft_atoi(char *a);
int					ft_isdigit(int c);
int					ft_strlcat(char *dst, const char *src, int i);
int					ft_getprecision(const char *tab, int *i);
int					ft_getpadding(const char *tab, int *i, t_print *res);

char				*ft_vatochar(va_list valist, char c, t_print *tmp);
char				*ft_convertbase(int i);
char				*ft_convertbase2(int i);
char				*ft_convertbase3(unsigned int u);
char				*ft_convertbase4(unsigned int u);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
char				*ft_point(int a);
char				*ft_conv0(t_print tmp);
char				*ft_paddingleft(t_print tmp, int padding, int f);
char				*ft_paddingright(t_print tmp, int paddinga);
char				*ft_precision(t_print res);
char				*ft_strdup(char *s1);
char				*ft_checkstar(char *tab, int *i, va_list valist, int *g_free);
char				*ft_displate(t_print tmp);

int					ft_strlcpy(char *dst, char *src, int dstsize);
int					ft_strlen(char *a);

#endif
