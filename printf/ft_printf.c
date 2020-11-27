/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:29:13 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/27 18:56:32 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void	replace_star(char *format, Params *p, va_list args)
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
		handle_hex(&p, args);		
	}
	if (p.type == 'd')
		handle_int(&p, args);
}

int	init_struct(char *format, va_list args)
{
	int offset;
	char types[10] = "cspdiuxX%";
		
	offset = 2;
	Params p;
	clean_params(&p);
	while (!ft_strchr(types, *format))
	{
		if (*format == '*')
			replace_star(format, &p, args);
		if (is_flag(*format) && offset == 2)
			p.flag = *format;
		if (ft_isdigit(*format) && p.width == -1 && p.dot == 0)
			p.width = ft_atoi(format);	
		if (*format == '.')
		{
			p.dot = 1;
			p.precision = 0;
			if (ft_isdigit(*(format+1)))
				p.precision	= ft_atoi(format+1);
		}
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
		{
			i += init_struct((char*)&format[i+1], args); //after percent
			continue ;
		}
		if (i >= len)
			break;
		ft_putchar_fd(format[i++], 1);
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
