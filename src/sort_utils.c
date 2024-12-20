/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:05:24 by christophed       #+#    #+#             */
/*   Updated: 2024/12/20 15:57:01 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to see if a stack is sorted
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

// Function to sort the 2 elements at the top of a stack a
int	sort_2a(t_stack **a)
{
	if (!a || !*a)
		return (-1);
	if ((*a)->data > (*a)->next->data)
		sa(a);
	return (0);
}

// Function to sort the 2 elements at the top of a stack b
int	sort_2b(t_stack **b)
{
	if (!b || !*b)
		return (-1);
	if ((*b)->data > (*b)->next->data)
		sb(b);
	return (0);
}

// Function to sort a stack with 3 or less elements
int	sort_3_or_less(t_stack **stack)
{
	int	stack_len;

	if (!stack || !*stack)
		return (-1);
	stack_len = dclst_count_nodes(*stack);
	if (stack_len == 1)
		return (0);
	else if (stack_len == 2)
	{
		if ((*stack)->data > (*stack)->next->data)
			sa(stack);
		return (0);
	}
	if ((*stack)->data < (*stack)->next->data && (*stack)->data < (*stack)->previous->data)
	{
		if ((*stack)->next->data > (*stack)->previous->data)
		{
			sa(stack);
			ra(stack);
		}
	}
	else if ((*stack)->data > (*stack)->next->data && (*stack)->data > (*stack)->previous->data)
	{
		ra(stack);
		if ((*stack)->data > (*stack)->next->data)
			sa(stack);
	}
	else
	{
		if ((*stack)->previous->data < (*stack)->data)
			rra(stack);
		else
			sa(stack);
	}
	return (0);
}

// Function to see if rotate is the shortest way to the top
int	r_is_best(t_stack *head, t_stack *node)
{
	int	len;
	int	pos;

	len = dclst_count_nodes(head);
	pos = dclst_find_node_pos(head, node);
	if (pos <= len / 2)
		return (1);
	else
		return (0);
}

// Function to calculate the distance between node and head
int	dist_from_head(t_stack *head, t_stack *node)
{
	int	dist_by_ra;
	int	dist_by_rra;
	int	len;

	len = dclst_count_nodes(head);
	dist_by_ra = dclst_find_node_pos(head, node);
	dist_by_rra = len - dclst_find_node_pos(head, node);
	if (dist_by_ra < dist_by_rra)
		return (dist_by_ra);
	else
		return (dist_by_rra);
}