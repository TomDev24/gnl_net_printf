/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:02:41 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/29 20:19:46 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


void	handle_pointer(Params *p, va_list args)
{
	long long int res;	
	char *s;
	size_t str_len;

	res = va_arg(args, long int);
	if (p->width)
		p->width = p->width;
	//leaks
	s = ft_strjoin("0x", x_convert(res,'a'));
	str_len = ft_strlen(s);
	write(1, s, str_len);
}

