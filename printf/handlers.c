/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:17:56 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/27 18:56:35 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
void	handle_char(Params *p, va_list args)
{
	int a;
	a = p->width +10;
}*/

void	handle_hex(Params *p, va_list args)
{
	//long int res;
	char fill;
	int spaces;	
	char *s;
	int i;
	int str_len;
	
	i = 0;
	spaces = 0;
	fill = ' ';
	if (p->type == 'x')
		s = x_convert(va_arg(args,long int), 'a');
	else 
		s = x_convert(va_arg(args,long int), 'A');
	str_len = ft_strlen(s);
	if (p->width != -1 && p->width - str_len > 0) 
		spaces = p->width - str_len;
	if (p->dot == 1)
	{
		if (p->precision - str_len > 0)
			spaces = p->precision - str_len;
		fill = '0';
	}
	if (p->flag == '-')
	{
		write(1, s, str_len);
		while (i++ < spaces)
			ft_putchar_fd(fill, 1);
	}
	else
	{
		while (i++ < spaces)
			ft_putchar_fd(fill, 1);	
		write(1, s, str_len);
	}
}

void	handle_int(Params *p, va_list args)
{
	int res;
	char fill;
	int spaces;	
	char *s;
	int i;
	int str_len;

	i = 0;
	spaces = 0;
	fill = ' ';
	res = va_arg(args, int);
	s = ft_itoa(res); 
	str_len = ft_strlen(s);
	if (p->width != -1 && p->width - str_len > 0) 
		spaces = p->width - str_len;
	if (p->dot == 1)
	{
		if (p->precision - str_len > 0)
			spaces = p->precision - str_len;
		fill = '0';
	}
	if (p->flag == '-')
	{
		write(1, s, str_len);
		while (i++ < spaces)
			ft_putchar_fd(fill, 1);
	}
	else
	{
		while (i++ < spaces)
			ft_putchar_fd(fill, 1);	
		write(1, s, str_len);
	}
}

void	handle_str(Params *p, va_list args)
{
	char *s;
	int str_len;
	int i;
	int spaces;	

	i = 0;
	str_len = 0;
	spaces = 0;
	s = va_arg(args, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	//printf("%s", s);
	str_len = ft_strlen(s);	
	if (p->precision >= 0)
		str_len = p->precision < str_len ? p->precision : str_len;
	if (p->width != -1 && p->width - str_len > 0) 
		spaces = p->width - str_len;
	if (p->flag == '-')
	{
		ft_putstr_print(s, str_len);
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);	
		ft_putstr_print(s, str_len);
	}
	//free(s); in diff place
}
