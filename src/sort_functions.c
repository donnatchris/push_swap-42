/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:05:24 by christophed       #+#    #+#             */
/*   Updated: 2024/12/16 12:35:35 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	int		count;
	int		position;
	t_stack	*min;

	min = dclst_find_min(*stack_a);
	if (min == *stack_a)
		return (0);
	if ((*stack_a)->next == min)
		return (sa(stack_a), 0);
	if ((*stack_a)->previous == min)
		return (rra(stack_a), 0);
	count = dclst_count_nodes(*stack_a);
	position = dclst_find_node_position(*stack_a, min);
	while (*stack_a != min)
	{
		if (position <= count / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	return (0);
}

// Function to sort the stack a from the smallest to the biggest number
// by using the stack b and the instructions
int	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		count;
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