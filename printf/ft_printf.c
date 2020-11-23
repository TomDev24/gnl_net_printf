/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:29:13 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/23 15:59:20 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	char *res;

	va_start(args, format);
	
	res =va_arg(args, char *);
	ft_putstr_fd(res, 1);
	va_end(args);
	return (0);
}
