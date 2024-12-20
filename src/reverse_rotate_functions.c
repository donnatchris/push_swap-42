/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:29 by christophed       #+#    #+#             */
/*   Updated: 2024/12/20 23:24:28 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to shift all the elements of stack a down by one position
int	rra(t_stack **stack_a)
{
	write(1, "rra\n", 4);
	if (!stack_a || !*stack_a)
		return (-1);
	if (*stack_a == (*stack_a)->previous)
		return (0);
	*stack_a = (*stack_a)->previous;
	return (0);
}

// Function to shift all the elements of stack b down by one position
int	rrb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return (-1);
	write(1, "rrb\n", 4);
	if (*stack_b == (*stack_b)->previous)
		return (0);
	*stack_b = (*stack_b)->previous;
	return (0);
}

// Function to shift all the elements of stack a down by one position
// and shift all the elements of stack b down by one position
int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	result;

	write(1, "rrr\n", 4);
	result = 0;
	result += rra(stack_a);
	result += rrb(stack_b);
	return (result);
}
