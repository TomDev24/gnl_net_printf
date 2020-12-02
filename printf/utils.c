/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:19:00 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/02 15:59:45 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//test
void	print_params(Params p)
{
	printf("\n =======\n");
	printf("Flag is %c\n", p.flag);	
	printf("Width is %d\n", p.width);	
	printf("Percision is %d\n", p.precision);
	printf("Type is %c", p.type);
	printf("\n =======\n");
}	

int	is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	else 
		return (0);
}

int	clean_params(Params *p)
{
	//if (!p)
		//return (0);
	p->width = -1;
	p->precision = -1;
	p->type = -1;
	p->flag = -1;
	p->dot = 0;
	return (1);
}

void	fill_char(int len, char fill)
{
	int i;

	i = 0;
	while (i++ < len)
		write(1, &fill, 1);
}

void	ft_putstr_print(char *s, int len)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (*s && i++ < len)
	{
		if (ft_isprint(*s))
			ft_putchar_fd(*s, 1);
		s++;
	}
}
