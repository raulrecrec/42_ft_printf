/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:07:09 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/17 19:13:17 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_format(const char c, va_list value, int *cont)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(value, int), 1);
		(*cont)++;
		printf("\n%d\n", *cont);
	}
	else if (c == 's')
	{
		char *str = va_arg(value, char *);
		ft_putstr_fd(str, 1);
		*cont = (*cont) + ft_strlen(str);
		printf("\n%d\n", *cont);
	}
	else if (c == 'd')
	{
		int num = va_arg(value, int);
		ft_putnbr_fd(num, 1);
		*cont = (*cont) + ft_numlen(num);
		printf("\n%d\n", *cont);
	}
}
