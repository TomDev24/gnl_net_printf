/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:54:11 by dbrittan          #+#    #+#             */
/*   Updated: 2020/12/02 15:39:35 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

static char	convert_hex(long long int n, char flag)
{
	flag++;
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (n >= 0 && n < 16)
		return (n + (flag - 11));
	return (0);
}

char	*x_convert(long long int val, char flag)
{
	long long int orig_val;
	size_t len;
	char *res;

	len = 0;
	orig_val = val;
	while (len == 0 || (val / 16 != 0 || val % 16 != 0))
	{
		len++;
		val /= 16;
	}
	//printf("len %d\n", len);
	val = orig_val;
	res = (char *)ft_calloc(len, sizeof(char));
	while (len-- || (val / 16 != 0 ||  val % 16 != 0))
	{
		//printf("the val %d\n", val);
		//printf("Val %d\n", val % 16); 	
		res[len] = convert_hex(val % 16, flag);
		val /= 16;
	}
	return (res);
}
