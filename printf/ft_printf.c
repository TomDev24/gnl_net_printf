/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:29:13 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/03 15:00:28 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void		replace_star(char *format, t_params *p, va_list args)
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

int			format_print(t_params *p, va_list args)
{
	if (p->type == 'c')
		handle_char(p, args);
	if (p->type == 's')
		handle_str(p, args);
	if (p->type == 'p')
		handle_pointer(p, args);
	if (p->type == '%')
		handle_percent(p);
	if (p->type == 'x' || p->type == 'X')
		handle_hex(p, args);
	if (p->type == 'd' || p->type == 'i' || p->type == 'u')
		handle_int(p, args);
	return (1);
}

static void	chose_type(char **format, t_params *p, va_list args)
{
	if (**format == ' ')
	{
		ft_putchar_fd(' ', 1 * ic(p, 1));
		return ;
	}
	if (**format == '.')
	{
		p->dot = 1;
		p->precision = 0;
		if (ft_isdigit(*(*format + 1)))
			p->precision = ft_atoi(*format + 1);
	}
	if (**format == '*')
		replace_star(*format, p, args);
	if (is_flag(**format) && !p->dot && p->flag != '-' && p->width == -1)
	{
		p->flag = *(*format);
		return ;
	}
	if (ft_isdigit(**format) && p->width == -1 && !p->dot)
		p->width = ft_atoi(*format);
}

int			init_struct(char *format, va_list args, t_params *p)
{
	int			offset;
	char		types[10];

	ft_strlcpy(types, "cspdiuxX%", 10);
	offset = 2;
	while (!ft_strchr(types, *format))
	{
		if (*(format) == '%')
			break ;
		chose_type(&format, p, args);
		format += 1;
		offset += 1;
	}
	p->type = *format;
	return (format_print(p, args) * clean_params(p) * offset);
}

int			ft_printf(const char *format, ...)
{
	int			offset;
	size_t		len;
	size_t		i;
	va_list		args;
	t_params	p;

	va_start(args, format);
	len = ft_strlen(format);
	clean_params(&p);
	p.length = 0;
	i = 0;
	offset = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i += init_struct((char*)&format[i + 1], args, &p);
			continue ;
		}
		if (i >= len)
			break ;
		ft_putchar_fd(format[i++], 1 * ic(&p, 1));
	}
	va_end(args);
	return (p.length);
}
