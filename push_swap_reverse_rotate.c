/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:29 by christophed       #+#    #+#             */
/*   Updated: 2024/12/14 08:59:33 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to shift all the elements of stack a down by one position
int	rra(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || *stack_a == (*stack_a)->previous)
		return (-1);
	*stack_a = (*stack_a)->previous;
	return (0);
}

// Function to shift all the elements of stack b down by one position
int	rrb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || *stack_b == (*stack_b)->previous)
		return (-1);
	*stack_b = (*stack_b)->previous;
	return (0);
}

// Function to shift all the elements of stack a down by one position
// and shift all the elements of stack b down by one position
int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	result;

	result = 0;
	result += rra(stack_a);
	result += rrb(stack_b);
	return (result);
}
