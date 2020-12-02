/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:29:13 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/02 13:28:01 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void	replace_star(char *format, Params *p, va_list args)
{
	int holder;
	
	holder = va_arg(args, unsigned int);
	if (holder < 0)
		p->flag = '-';
	if (p->dot && *(format - 1) == '.')
	{
		if (holder < 0)
			p->precision = -1;
		else
			p->precision = holder;
	}
	if (p->width == -1 && !p->dot)
	{
		if (holder < 0)
			holder *= -1;
		p->width = holder;
	}
}

void	format_print(Params p, va_list args)
{
	if (p.type == 'c')
		handle_char(&p, args);
	if (p.type == 's')
		handle_str(&p, args);
	if (p.type == 'p')
		handle_pointer(&p, args);
	if (p.type == '%')
		handle_percent(&p);
	if (p.type == 'x' || p.type == 'X')
		handle_hex(&p, args);		
	if (p.type == 'd' || p.type == 'i' || p.type == 'u')
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
		if (*format == ' ')
		{
			ft_putchar_fd(' ', 1);
			format++;
			offset++;
			continue ;
		}
		if (*format == '.')
		{
			p.dot = 1;
			p.precision = 0;
			if (ft_isdigit(*(format+1)))
				p.precision	= ft_atoi(format+1);
		}
		if (*format == '*')
			replace_star(format, &p, args);
		if (is_flag(*format) && !p.dot && p.flag != '-' && p.width == -1)
		{
			p.flag = *format++;
			offset++;
			continue ;	
		}
		if (ft_isdigit(*format)  && p.width == -1 && !p.dot)
			p.width = ft_atoi(format);
		offset++;
		if (*(format) == '%')
			break;
		format++;		
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
			i += init_struct((char*)&format[i+1], args);
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
