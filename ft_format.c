/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:07:09 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/22 18:37:16 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char c, va_list value)
{
	int	printed_chars;

	if (c == 'c')
	{
		printed_chars = ft_putlchar(va_arg(value, int));
	}
	else if (c == 's')
	{
		printed_chars = ft_putlstr(va_arg(value, char *));
	}
	else if (c == 'd' || c == 'i')
	{
		printed_chars = ft_putlnbr(va_arg(value, int));
	}
	else if (c == 'x' || c == 'X')
	{
		printed_chars = ft_putlnbr_base_x_X(c, va_arg(value, long long));
	}
	return (printed_chars);
}
