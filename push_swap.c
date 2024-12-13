/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:08 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/13 22:07:24 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to load the doubly circular linked list with the input values
t_stack *dclst_load(char **av, int ac)
{
    t_stack *head;
    t_stack *new;
    long	data;
    int     i;

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
    printf("After sa:\n");
    sa(&stack_a);
    dclst_print(stack_a);
    printf("After reverse rotate:\n");
    rra(&stack_a);
    dclst_print(stack_a);
    printf("After rotate:\n");
    ra(&stack_a);
    dclst_print(stack_a);
    printf("After sa:\n");
    sa(&stack_a);
    dclst_print(stack_a);
    
    return (0);
}
