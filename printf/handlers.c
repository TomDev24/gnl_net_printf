/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:17:56 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/30 20:35:59 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_hex(Params *p, va_list args)
{
	char fill;
	char *s;
	int i;
	int str_len;
	int counter;

	i = 0;
	fill = ' ';
	s = x_convert(va_arg(args,long int), p->type - 23);
	//costell and mem leaks
	if ((p->precision == 0) && *s == '0')
		s = ft_strdup("");
	str_len = ft_strlen(s);
	if (p->flag == '0')
		fill = '0';
	counter = p->width - str_len;
	if (p->precision > str_len)
		counter =p->width - p->precision;
	if (p->precision != -1)
		fill = ' ';
	if (p->flag != '-')
		while (i++ < counter)
			ft_putchar_fd(fill, 1);	
	i = 0;
	while (i++ < p->precision - str_len)
			ft_putchar_fd('0', 1);
	i = 0;
	write(1, s, str_len);
	if (p->flag == '-')
		while (i++ < counter)
			ft_putchar_fd(fill, 1);
}

void	handle_int(Params *p, va_list args)
{
	int res;
	char fill;
	char *s;
	int i;
	int str_len;
	int counter;

	counter = 0;
	i = 0;
	res = va_arg(args, int);
	s = ft_itoa(res); 
	if ((p->precision == 0) && *s == '0')
		s = ft_strdup("");
	str_len = ft_strlen(s);
	fill = p->flag == 0 ? '0' : ' ';

	counter = p->precision > str_len ? p->width - p->precision : p->width - str_len;
	//fill = p->precision != -1 ? ' ' : fill;
	if (res < 0 && p->precision > str_len)
			counter--;
	if (p->flag != '-')
		while (i++ < counter)
			ft_putchar_fd(fill, 1);
	if (res < 0)
	{
		ft_putchar_fd('-', 1);	
		res *= -1;
		str_len--;
	}
	s = ft_itoa(res); 
	i = 0;
	while (i++ < p->precision - str_len)
			ft_putchar_fd('0', 1);
	i = 0;
	write(1, s, str_len);
	if (p->flag == '-')
		while (i++ < counter)
			ft_putchar_fd(' ', 1);
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
	str_len = ft_strlen(s);	
	if (p->precision >= 0)
		str_len = p->precision < str_len ? p->precision : str_len;
	if (p->width != -1 && p->width - str_len > 0) 
		spaces = p->width - str_len;
	if (p->flag != '-')
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);
	ft_putstr_print(s, str_len);
	if (p->flag == '-')	
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);	
	//free(s); in diff place
}
