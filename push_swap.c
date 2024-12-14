/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:59 by christophed       #+#    #+#             */
/*   Updated: 2024/12/14 10:05:27 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to load the doubly circular linked list with the input values
t_stack	*dclst_load(char **av, int ac)
{
	t_stack	*head;
	t_stack	*new;
	long	data;
	int		i;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		data = ft_atoi_long(av[i]);
		if (is_int(data) == 0 || has_double(head, (int) data) != 0)
			return (dclst_clear(&head), NULL);
		new = dclst_insert_node_end(&head, (int) data);
		if (!new)
			return (dclst_clear(&head), NULL);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (check_input(av, ac) == -1)
		return (write(2, "Error\n", 6), 2);
	if (ac == 2)
	{
		if (is_int(ft_atoi_long(av[1])) == 0)
			return (write(2, "Error\n", 6), 2);
		return (0);
	}
	stack_a = dclst_load(av, ac);
	if (stack_a == NULL)
		return (write(2, "Error\n", 6), 2);
	// TESTS TO REMOVE BEFORE SUBMITTING
	printf("Original list:\n");
	dclst_print(stack_a);
	dclst_print(stack_b);
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
	printf("After sa:\n");
	sa(&stack_a);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After sa:\n");
	sa(&stack_a);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After rra:\n");
	rra(&stack_a);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After ra:\n");
	ra(&stack_a);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After pb:\n");
	pb(&stack_a, &stack_b);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After pb:\n");
	pb(&stack_a, &stack_b);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After sb:\n");
	sb(&stack_b);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After sb:\n");
	sb(&stack_b);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After rrb:\n");
	rrb(&stack_b);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After rb:\n");
	rb(&stack_b);
	dclst_print(stack_a);
	dclst_print(stack_b);
	printf("After pa:\n");
	pa(&stack_a, &stack_b);
	dclst_print(stack_a);
	dclst_print(stack_b);
	


	return (0);
}
