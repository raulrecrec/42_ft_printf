/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:36:50 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/22 18:43:05 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlnbr_base_mm(long long nbr, char *base, int printed_chars)
{
	int			leng_base;
	long long	c;
	char		aux;

	c = nbr;
	leng_base = 0;
	while (base[leng_base] != '\0')
		leng_base++;
	if (c < 0)
	{
		write(1, "-", 1);
		c = -c;
		printed_chars++;
	}
	if (c >= leng_base)
		printed_chars = ft_putlnbr_base_mm(c / leng_base, base, printed_chars);
	aux = base[c % leng_base];
	printed_chars++;
	write(1, &aux, 1);
	return (printed_chars);
}
int	ft_putlnbr_base_x_X(const char c, long long nbr)
{
	int	printed_chars;

	printed_chars = 0;
	if (c == 'x')
		printed_chars = ft_putlnbr_base_mm(nbr, "0123456789abcdef", printed_chars);
	else
		printed_chars = ft_putlnbr_base_mm(nbr, "0123456789ABCDEF", printed_chars);
	return (printed_chars);
}
