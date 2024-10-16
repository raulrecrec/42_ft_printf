/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:08:58 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/16 19:34:30 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include "../42_Libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_format(const char c, va_list value, int *cont);
int		ft_putchar(char c);

#endif