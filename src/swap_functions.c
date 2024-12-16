/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:45 by christophed       #+#    #+#             */
/*   Updated: 2024/12/16 16:19:00 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to swap the first two elements of stack_a
int	sa(t_stack **stack_a)
{
	int	result;

	write(1, "sa\n", 3);
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (-1);
	result = dclst_swap_nodes(stack_a, *stack_a, (*stack_a)->next);
	return (result);
}

// Function to swap the first two elements of stack b
int	sb(t_stack **stack_b)
{
	int	result;

	write(1, "sb\n", 3);
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (-1);
	result = dclst_swap_nodes(stack_b, *stack_b, (*stack_b)->next);
	return (result);
}

// Function to swap the first two elements of stack_a
// and swap the first two elements of swap_b
int	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	result;

	write(1, "ss\n", 3);
	result = 0;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		result += -1;
	else
		result += dclst_swap_nodes(stack_a, *stack_a, (*stack_a)->next);
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		result += -1;
	else
		result += dclst_swap_nodes(stack_b, *stack_b, (*stack_b)->next);
	return (result);
}
