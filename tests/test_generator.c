/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:02:03 by christophed       #+#    #+#             */
/*   Updated: 2024/12/20 23:29:35 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Program to generate random numbers separated by space without doubles
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int	main(void)
{
	int		i;
	int		n;
	int		*arr;
	int		rand_num;
	int		j;

	srand(time(NULL));
	n = 500;
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (1);
	i = 0;
	while (i < n)
	{
		rand_num = rand() % 1000;
		j = 0;
		while (j < i)
		{
			if (arr[j] == rand_num)
				break ;
			j++;
		}
		if (j == i)
		{
			arr[i] = rand_num;
			i++;
		}
	}
	i = 0;
	while (i < n)
	{
		printf("%d", arr[i]);
		if (i < n - 1)
			printf(" ");
		i++;
	}
	free(arr);
	return (0);
}