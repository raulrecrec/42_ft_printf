/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:54:34 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/17 17:58:49 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
	int cont;
	char *a = "Hola, mundo!";
    ft_printf("String: %s\n", a);
    ft_printf("El número es: %d\n", 42);
    ft_printf("Caracter: %c\n", 'A');

	cont = printf("String: %s\n", a);
	printf("%d\n", cont);
    cont = printf("El número es: %d\n", 42);
	printf("%d\n", cont);
    cont = printf("Caracter: %c\n", 'A');
	printf("%d\n", cont);
    return 0;
}