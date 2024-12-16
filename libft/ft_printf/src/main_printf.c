/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:00:29 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/16 18:18:02 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int n1 = -2147483648;
	unsigned int n2 = 4000000000;
	int n3 = 8945;
	int	n4 = 8945;
	int count;

	printf("Test of zeros:\n");
	count = ft_printf("%d, %u, %x, %X \n", 0, 0, 0, 0);
	printf("Return: %d\n", count);
	printf("Witness:\n");
	count = printf("%d, %u, %x, %X \n", 0, 0, 0, 0);
	printf("Return: %d\n", count);
	printf("\n");

	printf("Test of my ft_printf:\n");
	count = ft_printf("%% %d, %u, %p \n", n1, n2, &n1);
	printf("Le retour vaut: %d\n", count);
	printf("Witness:\n");
	count = printf("%% %d, %u, %p \n", n1, n2, &n1);
	printf("Le retour vaut: %d\n", count);
	printf("\n");

	printf("Test avec des valeurs NULL et des entiers limites:\n");
	printf("Test of my ft_printf:\n");
	count = ft_printf("%s %d %x %X %p\n", (char *) NULL, n1, 0, 0, NULL);
	printf("Witness:\n");
	printf("Le retour vaut: %d\n", count);
	count = printf("%s %d %x %X %p\n", (char *) NULL, n1, 0, 0, NULL);
	printf("Le retour vaut: %d\n", count);
	printf("\n");

	printf("Test avec des erreurs:\n");
	ft_printf("Test of my ft_printf:\n");
	count = ft_printf("% what? %r \n");
	printf("Le retour vaut: %d\n", count);
	printf("Witness:\n");
	count = printf("% what? %r \n");
	printf("Le retour vaut: %d\n", count);
	printf("\n");
/*
	printf("Test avec des hexa:\n");
	ft_printf("Test of my ft_printf:\n");
	count = ft_printf("%x , %#x \n", 255, 255);
	printf("Le retour vaut: %d\n", count);
	printf("Witness:\n");
	count = printf("%x , %#x \n", 255, 255);
	printf("Le retour vaut: %d\n", count);
*/

	return (0);
}

