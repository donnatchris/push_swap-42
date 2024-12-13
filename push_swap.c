/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:08 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/13 09:40:49 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to load the doubly circular linked list with the input values
t_stack *dclst_load(char **av, int ac)
{
    t_stack *head;
    t_stack *new;
    int     data;
    int     i;

    head = NULL;
    i = 1;
    while (i < ac)
    {
        data = ft_atoi_long(av[i]);
        if (data < -2147483648 || data > 2147483647)
            return (ft_free_stack(head), NULL);
        new = clst_insert_node_end(&head, data);
        if (!new)
            return (ft_free_stack(head), NULL);
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
	stack_a = dclst_load(av, ac);
	if (stack_a == NULL)
		return (write(2, "Error\n", 6), 2);
}
