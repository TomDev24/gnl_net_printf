/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:02:41 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/30 15:33:20 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_percent(Params *p)
{
	int spaces;
	int i;
	char fill;

	i = 0;
	spaces = 0;
	fill = ' ';
	if (p->width != -1 && p->width - 1 > 0) 
		spaces = p->width - 1;
	if (p->flag == '0')
		fill = '0';
	if (p->flag !='-')
		while (i++ < spaces)
			ft_putchar_fd(fill, 1);	
	ft_putchar_fd('%', 1);	
	if (p->flag =='-')
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);	

}

void	handle_char(Params *p, va_list args)
{
	int spaces;
	int i;

	i = 0;
	spaces = 0;
	if (p->width != -1 && p->width - 1 > 0) 
		spaces = p->width - 1;
	
	if (p->flag !='-')
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);	
	ft_putchar_fd(va_arg(args, int), 1);
	if (p->flag =='-')
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);	
}

void	handle_pointer(Params *p, va_list args)
{
	long long int res;	
	char *s;
	size_t str_len;
	int spaces;
	int i;
	char fill;

	i = 0;
	spaces = 0;
	fill = ' ';
	res = va_arg(args, long long int);
	//leaks
	s = ft_strjoin("0x", x_convert(res,'a'));
	str_len = ft_strlen(s);
	if (p->width != -1 && p->width - str_len > 0) 
		spaces = p->width - str_len;
	if (p->flag == '0')
		fill = '0';
	if (p->flag !='-')
		while (i++ < spaces)
			ft_putchar_fd(fill, 1);	
	write(1, s, str_len);
	if (p->flag =='-')
		while (i++ < spaces)
			ft_putchar_fd(' ', 1);
}

