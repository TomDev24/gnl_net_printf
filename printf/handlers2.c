/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:02:41 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/03 15:00:24 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_percent(t_params *p)
{
	int		spaces;
	int		i;
	char	fill;

	i = 0;
	spaces = 0;
	fill = ' ';
	if (p->width != -1 && p->width - 1 > 0)
		spaces = p->width - 1;
	if (p->flag == '0')
		fill = '0';
	if (p->flag != '-')
		fill_char(spaces, fill * ic(p, spaces));
	ft_putchar_fd('%', 1 * ic(p, 1));
	if (p->flag == '-')
		fill_char(spaces, ' ' * ic(p, spaces));
}

void	handle_char(t_params *p, va_list args)
{
	int spaces;
	int i;

	i = 0;
	spaces = 0;
	if (p->width != -1 && p->width - 1 > 0)
		spaces = p->width - 1;
	if (p->flag != '-')
		fill_char(spaces, ' ' * ic(p, spaces));
	ft_putchar_fd(va_arg(args, int), 1 * ic(p, 1));
	if (p->flag == '-')
		fill_char(spaces, ' ' * ic(p, spaces));
}

void	handle_pointer(t_params *p, va_list args)
{
	char	*s;
	size_t	str_len;
	int		spaces;
	int		i;
	char	fill;

	i = 0;
	spaces = 0;
	fill = ' ';
	s = x_convert(va_arg(args, long long int), 'a');
	if ((p->precision == 0) && *s == '0')
		*s = '\0';
	str_len = ft_strlen(s) + 2;
	if (p->width != -1 && p->width - str_len > 0)
		spaces = p->width - str_len;
	if (p->flag == '0')
		fill = '0';
	if (p->flag != '-')
		fill_char(spaces, fill * ic(p, spaces));
	ft_putstr_fd("0x", 1 * ic(p, 2));
	write(1, s, str_len - 2 * ic(p, str_len - 2));
	if (p->flag == '-')
		fill_char(spaces, ' ' * ic(p, spaces));
}
