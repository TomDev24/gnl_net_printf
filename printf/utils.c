/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:19:00 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/03 15:00:59 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	else
		return (0);
}

int		clean_params(t_params *p)
{
	p->width = -1;
	p->precision = -1;
	p->type = -1;
	p->flag = -1;
	p->dot = 0;
	return (1);
}

int		ic(t_params *p, int amount)
{
	if (amount < 0)
		amount = 0;
	p->length += amount;
	return (1);
}

void	fill_char(int len, char fill)
{
	int i;

	i = 0;
	while (i++ < len)
		write(1, &fill, 1);
}
