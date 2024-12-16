/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:59 by christophed       #+#    #+#             */
/*   Updated: 2024/12/16 16:39:09 by christophed      ###   ########.fr       */
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
	if (stack_a == NULL)
		return (write(2, "Error\n", 6), 2);
		
	// TESTS TO REMOVE BEFORE SUBMITTING
	// printf("Original list:\n");
	// dclst_print(stack_a);
	if (sort_stack_a(&stack_a, &stack_b) == -1)
		return (write(2, "Error\n", 6), 2);
	// printf("Sorted list:\n");
	// dclst_print(stack_a);
	dclst_clear(&stack_a);
	dclst_clear(&stack_b);

	// printf("Switch 3 and 5\n");
	// dclst_swap_nodes(&stack_a, stack_a->next->next, stack_a->next->next->next->next);
	// dclst_print(stack_a);
	// printf("Switch 5 and 3\n");
	// dclst_swap_nodes(&stack_a, stack_a->next->next->next->next, stack_a->next->next);
	// dclst_print(stack_a);
	// printf("Switch 1 and 2\n");
	// dclst_swap_nodes(&stack_a, stack_a, stack_a->next);
	// dclst_print(stack_a);
	// printf("Switch 2 and 1\n");
	// dclst_swap_nodes(&stack_a, stack_a->next, stack_a);
	// dclst_print(stack_a);
	// printf("Switch 1 and 5\n");
	// dclst_swap_nodes(&stack_a, stack_a, stack_a->next->next->next->next);
	// dclst_print(stack_a);
	// printf("Switch 5 and 1\n");
	// dclst_swap_nodes(&stack_a, stack_a->next->next->next->next, stack_a);
	// dclst_print(stack_a);
	// printf("Switch 4 and 5\n");
	// dclst_swap_nodes(&stack_a, stack_a->next->next->next, stack_a->next->next->next->next);
	// dclst_print(stack_a);
	// printf("Switch 5 and 4\n");
	// dclst_swap_nodes(&stack_a, stack_a->next->next->next->next, stack_a->next->next->next);
	// dclst_print(stack_a);
	// printf("Switch 1 and 2\n");
	// dclst_swap_nodes(&stack_a, stack_a, stack_a->next);
	// dclst_print(stack_a);
	// printf("Switch 2 and 1\n");
	// dclst_swap_nodes(&stack_a, stack_a->next, stack_a);
	// dclst_print(stack_a);
	// printf("Switch 1 and 4\n");
	// dclst_swap_nodes(&stack_a, stack_a, stack_a->next->next->next);
	// dclst_print(stack_a);
	// printf("Switch 4 and 1\n");
	// dclst_swap_nodes(&stack_a, stack_a->next->next->next, stack_a);
	// dclst_print(stack_a);
	// printf("Switch 1 and 3\n");
	// dclst_swap_nodes(&stack_a, stack_a, stack_a->next->next);
	// dclst_print(stack_a);
	// printf("Switch 3 and 1\n");
	// dclst_swap_nodes(&stack_a, stack_a->next->next, stack_a);
	// dclst_print(stack_a);
	// printf("After sa:\n");
	// sa(&stack_a);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After sa:\n");
	// sa(&stack_a);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After rra:\n");
	// rra(&stack_a);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After ra:\n");
	// ra(&stack_a);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After pb:\n");
	// pb(&stack_a, &stack_b);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After pb:\n");
	// pb(&stack_a, &stack_b);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After sb:\n");
	// sb(&stack_b);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After sb:\n");
	// sb(&stack_b);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After rrb:\n");
	// rrb(&stack_b);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After rb:\n");
	// rb(&stack_b);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("After pa:\n");
	// pa(&stack_a, &stack_b);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("Remove node 2 in stack_a:\n");
	// dclst_remove_node(&stack_a, stack_a->next);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("Remove node 1 in stack_a:\n");
	// dclst_remove_node(&stack_a, stack_a);
	// dclst_print(stack_a);
	// dclst_print(stack_b);
	// printf("Remove node 1 in stack_b:\n");
	// dclst_remove_node(&stack_b, stack_b);
	// dclst_print(stack_a);
	// dclst_print(stack_b);


	return (0);
}
