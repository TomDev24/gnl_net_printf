/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:20:47 by dbrittan          #+#    #+#             */
/*   Updated: 2020/11/26 18:43:58 by dbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

int main (int argc, char **argv)
{
	int a;
	if (argc == 10 && argv)
		a = 1;

	ft_printf("The letter:%-*c and \n", 10, 'c');
	ft_printf("The letter:%-*c and \n", 10, 'c');
	return (0);
}
