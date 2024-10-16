/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:07:09 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/16 19:49:47 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char c, va_list value, int *cont)
{
	if (c == 'c')
		{
			cont++;
			ft_putchar(va_arg(value, int));
		}
	else if (c == 's')
		ft_putstr_fd(va_arg(value, char *), 1);
	
}