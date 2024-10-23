/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:36:50 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/23 14:20:07 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlnbr_base(long long nbr, char *base, int printed_chars)
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
		printed_chars = ft_putlnbr_base(c / leng_base, base, printed_chars);
	aux = base[c % leng_base];
	printed_chars++;
	write(1, &aux, 1);
	return (printed_chars);
}

int	ft_putlnbr_base_xup(const char c, long long nbr)
{
	int	print_crs;

	print_crs = 0;
	if (c == 'x')
		print_crs = ft_putlnbr_base(nbr, "0123456789abcdef", print_crs);
	else if (c == 'X')
		print_crs = ft_putlnbr_base(nbr, "0123456789ABCDEF", print_crs);
	else if (c == 'u')
		print_crs = ft_putlnbr_base(nbr, "0123456789", print_crs);
	else if (c == 'p')
	{
		if (nbr == 0)
			print_crs = write(1, "(null)", 6);
		else
		{
			print_crs = write(1, "0x", 2);
			print_crs = ft_putlnbr_base(nbr, "0123456789abcdef", print_crs);
		}
	}
	return (print_crs);
}
