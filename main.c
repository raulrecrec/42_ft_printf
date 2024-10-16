/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:54:34 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/16 19:47:07 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    ft_printf("String: %S" "Hola, mundo!\n");
    ft_printf("El número es: %d\n", 42);
    ft_printf("Caracter: %c\n", 'A');
    return 0;
}