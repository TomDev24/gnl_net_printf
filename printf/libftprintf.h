/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:47:10 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/03 15:00:25 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_info
{
	char	flag;
	int		width;
	char	dot;
	int		precision;
	char	type;
	int		length;
}				t_params;

char			*x_convert(long int val, char flag);
int				is_flag(char c);
int				clean_params(t_params *p);
void			fill_char(int len, char fill);
int				ic(t_params *p, int amount);

int				ft_printf(const char *format, ...);
int				init_struct(char *format, va_list args, t_params *p);
int				format_print(t_params *p, va_list args);
void			replace_star(char *format, t_params *p, va_list args);

void			handle_str(t_params *p, va_list args);
void			handle_int(t_params *p, va_list args);
void			handle_hex(t_params *p, va_list args);
void			handle_pointer(t_params *p, va_list args);
void			handle_char(t_params *p, va_list args);
void			handle_percent(t_params *p);

#endif
