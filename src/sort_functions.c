/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:05:24 by christophed       #+#    #+#             */
/*   Updated: 2024/12/16 11:58:20 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function to check if the stack is sorted by reverse order
int	is_reverse_sorted(t_stack *stack)
{
	t_stack	*index;

	index = stack;
	while (index->next != stack)
	{
		if (index->data < index->next->data)
			return (0);
		index = index->next;
	}
	return (1);
}

// Function to check if the stack is sorted
int	is_sorted(t_stack *stack)
{
	t_stack	*index;

	index = stack;
	while (index->next != stack)
	{
		if (index->data > index->next->data)
			return (0);
		index = index->next;
	}
	return (1);
}

// Function to push all the elements of the stack b to the stack a
int	push_all_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		pa(stack_a, stack_b);
	return (0);
}

// Function to put min at the top of the stack
int	put_min_on_top(t_stack **stack_a)
{
	t_stack	*min;

	min = dclst_find_min(*stack_a);
	while (*stack_a != min)
	{
		if ((*stack_a)->next == min)
			sa(stack_a);
		else if ((*stack_a)->previous == min)
			rra(stack_a);
		else
			ra(stack_a);
	}
	return (0);
}

// Function to sort the stack a from the smallest to the biggest number
// by using the stack b and the instructions
int	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	while (*stack_a || (!is_sorted(*stack_a) && *stack_b))
	{
		put_min_on_top(stack_a);
		if (is_sorted(*stack_a))
			return (push_all_b_to_a(stack_a, stack_b));
		pb(stack_a, stack_b);
	}
	return (0);
}