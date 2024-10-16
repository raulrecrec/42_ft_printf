/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:25 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/16 19:51:16 by rexposit         ###   ########.fr       */
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
		if (format[i] != '%')
			cont = cont + ft_putchar(format[i]);
		else
			ft_format(format[i + 1], aargs, &cont);
		i++;
	}
	va_end(aargs);
	return 0;
}
