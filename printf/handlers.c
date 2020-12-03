/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:17:56 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/03 15:00:27 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		handle_hex(t_params *p, va_list args)
{
	char	fill;
	char	*s;
	int		str_len;
	int		counter;

	fill = ' ';
	s = x_convert(va_arg(args, long int), p->type - 23);
	if ((p->precision == 0) && *s == '0')
		*s = '\0';
	str_len = ft_strlen(s);
	if (p->flag == '0')
		fill = '0';
	counter = p->width - str_len;
	if (p->precision > str_len)
		counter = p->width - p->precision;
	if (p->precision != -1)
		fill = ' ';
	if (p->flag != '-')
		fill_char(counter, fill * ic(p, counter));
	fill_char(p->precision - str_len, '0' * ic(p, p->precision - str_len));
	write(1, s, str_len * ic(p, str_len));
	if (p->flag == '-')
		fill_char(counter, fill * ic(p, counter));
}

static void	chose_int(t_params *p, long int *res, va_list args)
{
	if (p->type == 'd' || p->type == 'i')
		*res = va_arg(args, int);
	else
		*res = va_arg(args, unsigned int);
}

static void	write_minus(long int *res, char fill, int *str_len, t_params *p)
{
	if (*res < 0 && fill == '0')
	{
		ft_putchar_fd('-', 1 * ic(p, 1));
		*res *= -1;
		*str_len -= 1;
	}
}

void		handle_int(t_params *p, va_list args)
{
	long int	res;
	char		fill;
	char		*s;
	int			len;
	int			counter;

	chose_int(p, &res, args);
	s = ft_itoa(res);
	if ((p->precision == 0) && *s == '0')
		*s = '\0';
	len = ft_strlen(s);
	fill = (p->flag == '0') ? '0' : ' ';
	counter = p->precision > len ? p->width - p->precision : p->width - len;
	fill = p->precision != -1 ? ' ' : fill;
	if (res < 0 && p->precision > len)
		counter--;
	write_minus(&res, fill, &len, p);
	if (p->flag != '-')
		fill_char(counter, fill * ic(p, counter));
	write_minus(&res, '0', &len, p);
	s = ft_itoa(res);
	fill_char(p->precision - len, '0' * ic(p, p->precision - len));
	write(1, s, len * ic(p, len));
	if (p->flag == '-')
		fill_char(counter, ' ' * ic(p, counter));
}

void		handle_str(t_params *p, va_list args)
{
	char	*s;
	int		str_len;
	int		i;
	int		spaces;

	i = 0;
	spaces = 0;
	s = va_arg(args, char *);
	if (s == NULL)
	{
		p->type = 'f';
		s = ft_strdup("(null)");
	}
	str_len = ft_strlen(s);
	if (p->precision >= 0)
		str_len = p->precision < str_len ? p->precision : str_len;
	if (p->width != -1 && p->width - str_len > 0)
		spaces = p->width - str_len;
	if (p->flag != '-')
		fill_char(spaces, ' ' * ic(p, spaces));
	write(1, s, str_len * ic(p, str_len));
	if (p->flag == '-')
		fill_char(spaces, ' ' * ic(p, spaces));
	if (p->type == 'f')
		free(s);
}
