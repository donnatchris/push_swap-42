/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:39 by christophed       #+#    #+#             */
/*   Updated: 2024/12/14 08:59:41 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to shift all the elements of stack a up by one position
int	ra(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || *stack_a == (*stack_a)->next)
		return (-1);
	*stack_a = (*stack_a)->next;
	return (0);
}

// Function to shift all the elements of stack b up by one position
int	rb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || *stack_b == (*stack_b)->next)
		return (-1);
	*stack_b = (*stack_b)->next;
	return (0);
}

// Function to shift all the elements of stack a up by one position
// and shift all the elements of stack b up by one position
int	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	result;

	result = 0;
	result += ra(stack_a);
	result += rb(stack_b);
	return (result);
}
