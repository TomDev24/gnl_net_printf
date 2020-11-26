/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:29:13 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/26 14:56:56 by dbrittan         ###   ########.fr       */
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

/*
void	get_star(char *format)
{

}
*/

int	clean_params(Params p)
{
	//if (!p)
		//return (0);
	p.width = 0;
	p.precision = 0;
	p.type = 0;
	p.flag = 0;
	return (1);
}


void	format_print(Params p, va_list args)
{
	int trash;
	//va arg
	// lets handle char and string
	if (p.type == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (p.type == 's')
		ft_putstr_fd(va_arg(args, char*), 1);
	if (p.type == 'x' || p.type == 'X')
	{
		trash = va_arg(args, int); 
		printf("!!!%d",trash);
		printf("tyoe is %c", p.type);
		printf("\n original %s \n", x_convert(15, 'X'));
		printf("---%s", x_convert(trash, p.type));
		ft_putstr_fd(x_convert(trash, p.type), 1);
	}
}

int	init_struct(char *format, va_list args)
{
	int offset;
	char types[10] = "cspdiuxX%";
		
	offset = 2;
	format++;
	Params p;
	while (!ft_strchr(types, *format))
	{
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
	//clean_params(p);
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
