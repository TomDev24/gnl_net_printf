/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:47:10 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/25 18:35:48 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct	info
{
	char flag;
	int width;
	int precision
	char type;
}	Params;

int	ft_printf(const char *format, ...);

#endif
