/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:25 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/17 13:14:34 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	aargs;
	int		cont;
	size_t	i;
	
	va_start(aargs, format);
	i = 0;
	cont = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			ft_format(format[++i], aargs, &cont);
		else
		{
			ft_putchar_fd(format[i], 1);
			cont++;
		}
		i++;
	}
	va_end(aargs);
	return (cont);
}
