/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:59 by christophed       #+#    #+#             */
/*   Updated: 2024/12/18 22:54:51 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (check_input(args) == -1)
		return (write(2, "Error\n", 6), 2);
	stack_a = dclst_load(args);
	if (ac == 2)
	{
		i = 0;
		while(args[i])
			free(args[i++]);
	}
	if (stack_a == NULL || push_swap(&stack_a, &stack_b) < 0)
		return (write(2, "Error\n", 6), 2);
	return (0);
}
