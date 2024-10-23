/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:54:34 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/23 13:44:58 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
	int cont;
	char *a = "Hola, mundo!";
    cont = ft_printf("String: %s\n", a);
	printf("%d\n", cont);
    cont = ft_printf("El número es: %d\n", 42);
	printf("%d\n", cont);
    cont = ft_printf("Caracter: %c\n", 'A');
	printf("%d\n", cont);
    cont = ft_printf("El número es: %i\n", 423);
	printf("%d\n", cont);
    cont = ft_printf("El número hex es: %x\n", 255);
	printf("%d\n", cont);
    cont = ft_printf("El número hex es: %X\n", 255);
	printf("%d\n", cont);
    cont = ft_printf("El número unsigned es: %u\n", 42);
	printf("%d\n", cont);
    cont = ft_printf("El procentaje de 42 es: %d%%\n", 42);
	printf("%d\n\nPRINTF ORIGINAL:\n\n", cont);

	cont = printf("String: %s\n", a);
	printf("%d\n", cont);
    cont = printf("El número es: %d\n", 42);
	printf("%d\n", cont);
    cont = printf("Caracter: %c\n", 'A');
	printf("%d\n", cont);
    cont = printf("El número es: %i\n", 423);
	printf("%d\n", cont);
    cont = printf("El número hex es: %x\n", 255);
	printf("%d\n", cont);
    cont = printf("El número hex es: %X\n", 255);
	printf("%d\n", cont);
    cont = printf("El número unsigned es: %u\n", 42);
	printf("%d\n", cont);
    cont = printf("El procentaje de 42 es: %d%%\n", 42);
	printf("%d\n", cont);
    return 0;
}