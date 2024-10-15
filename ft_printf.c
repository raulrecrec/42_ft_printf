/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:25 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/15 19:06:24 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	aargs;
	size_t	cont;
	size_t	i;
	
	va_start(aargs, format);
	i = 0;
	cont = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			cont = cont + ft_putchar(format[i]);
		else
			ft_type(format[i + 1], aargs, &cont);
		i++;
	}
	va_end(aargs);
	return 0;
}
