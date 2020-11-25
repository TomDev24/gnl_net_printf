/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:29:13 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/25 18:35:45 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

//test
void	print_params(Params p)
{

}	

int	is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	else 
		return (0);
}

void	get_start(char *format)
{

}

int	init_struct(const char *format)
{
	int offset;
	char types[10];

	types = "cspdiuxX%";
	offset = 0;
	Params p;
	while (!ft_strchr(types, *format))
	{
		//check if flag and add
		if (is_flag(*format))
			p.flag = *format;
		//check if width and add
		if (ft_isdigit(*format))
			p.width = ft_atoi(format);
		//check	if precision and add
		//if (*format == '.')
		format++;
	}
	p.type = *format;
	//add type after all
}

void	print(const char *format)
{
	int offset;

	offset = 1;
	while (*format != 0)
	{
		if (format == '%')
			offset = init_struct(format);
		format += offset;
		ft_putchar_fd(1, format);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	char *res;

	va_start(args, format);
	
	res =va_arg(args, char *);
	va_end(args);
	return (0);
}
