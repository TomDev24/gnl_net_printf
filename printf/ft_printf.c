/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:29:13 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/26 18:43:57 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

//test
void	print_params(Params p)
{
	printf("\n =======\n");
	printf("Flag is %c\n", p.flag);	
	printf("Width is %d\n", p.width);	
	printf("Percision is %d\n", p.precision);
	printf("Type is %c", p.type);
	printf("\n =======\n");
}	

int	is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	else 
		return (0);
}

int	clean_params(Params *p)
{
	//if (!p)
		//return (0);
	p->width = 0;
	p->precision = 0;
	p->type = 0;
	p->flag = 0;
	return (1);
}


void	handle_char(Params *p, va_list args)
{

}

void	handle_str(Params *p, va_list args)
{
	char *s;
	int str_len;
	int i;
	int spaces;
	
	i = 0;
	str_len = 0;
	s = va_arg(args, char *);
	//printf("%s", s);
	str_len = ft_strlen(s);	
	//stick to left
	if (p->width - str_len > 0) 
		spaces = p->width - str_len;
	if (p->flag == '-')
	{
		ft_putstr_fd(s, 1);
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);	
		ft_putstr_fd(s, 1);
	}
}

void	format_print(Params p, va_list args)
{
	//va arg
	// lets handle char and string
	if (p.type == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (p.type == 's')
		handle_str(&p, args);
	if (p.type == 'x' || p.type == 'X')
	{
		if (p.type == 'x')
			ft_putstr_fd(x_convert(va_arg(args, int), 'a'), 1);
		else
			ft_putstr_fd(x_convert(va_arg(args, int), 'A'), 1);
	}
}

void	handle_star(char *format, Params *p, va_list args)
{
	int holder;
	
	//percision or width ?????
	holder = va_arg(args, int);
	//if there is dot then percision
	if (*(format - 1) == '.')
		p->precision = holder;
	else
		p->width = holder;
}

int	init_struct(char *format, va_list args)
{
	int offset;
	char types[10] = "cspdiuxX%";
		
	offset = 2;
	format++;
	Params p;
	clean_params(&p);
	while (!ft_strchr(types, *format))
	{
		if (*format == '*')
			handle_star(format, &p, args);
		//check if flag and add
		if (is_flag(*format))
			p.flag = *format;
		//check if width and add
		if (ft_isdigit(*format) && p.width == 0)
			p.width = ft_atoi(format);	
		//check	if precision and add
		//if (*format == '.')
		format++;
		offset++;
	}
	p.type = *format;
	//print_params(p);
	format_print(p, args);
	clean_params(&p);
	return (offset);
}

void	print(const char *format, va_list args)
{
	int offset;
	size_t len;
	size_t i;

	len = ft_strlen(format);
	i = 0;
	offset = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
			i += init_struct((char*)&format[i], args); //after percent
		if (i >= len)
			break;
		ft_putchar_fd(format[i], 1);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	
	print(format, args);	
	va_end(args);
	return (0);
}
