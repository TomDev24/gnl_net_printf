/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:47:10 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/02 21:04:02 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

# include <stdio.h>
typedef	struct	info
{
	char flag;
	int width;
	char dot;
	int precision;
	char type;
}	Params;

char	*x_convert(long int val, char flag);

int		ft_printf(const char *format, ...);
void	print(const char *format, va_list args);
int		init_struct(char *format, va_list args);
void	format_print(Params p, va_list args);
void	replace_star(char *format, Params *p, va_list args);

//test delete later
void	print_params(Params p);

int		is_flag(char c);
int		clean_params(Params *p);
void	fill_char(int len, char fill);

void	ft_putstr_print(char *s, int len);
void	handle_str(Params *p, va_list args);
void	handle_int(Params *p, va_list args);
void	handle_hex(Params *p, va_list args);
void	handle_pointer(Params *p, va_list args);
void	handle_char(Params *p, va_list args);
void	handle_percent(Params *p);

#endif
