/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_V.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:05:24 by christophed       #+#    #+#             */
/*   Updated: 2024/12/19 00:27:57 by christophed      ###   ########.fr       */
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

// // Function to put a node on top of the stack_a
// void	put_node_on_top_a(t_stack **stack_a, t_stack *node)
// {
// 	int		len;
// 	int		position;

// 	if (!stack_a || !*stack_a || !node)
// 		return ;
// 	if (node == *stack_a)
// 		return ;
// 	len = dclst_count_nodes(*stack_a);
// 	position = dclst_find_node_pos(*stack_a, node);
// 	while (*stack_a != node)
// 	{
// 		if (position <= len / 2)
// 			ra(stack_a);
// 		else
// 			rra(stack_a);
// 	}
// }

// // Function to put a node on top of the stack_b
// void	put_node_on_top_b(t_stack **stack_b, t_stack *node)
// {
// 	int		len;
// 	int		position;

// 	if (!stack_b || !*stack_b || !node)
// 		return ;
// 	if (node == *stack_b)
// 		return ;
// 	len = dclst_count_nodes(*stack_b);
// 	position = dclst_find_node_pos(*stack_b, node);
// 	while (*stack_b != node)
// 	{
// 		if (position <= len / 2)
// 			rb(stack_b);
// 		else
// 			rrb(stack_b);
// 	}
// }

// Function to sort a stack with 3 or less elements
void	sort_3_or_less(t_stack **stack)
{
	int	stack_len;

	stack_len = dclst_count_nodes(*stack);
	if (stack_len == 1)
		return ;
	else if (stack_len == 2)
	{
		if ((*stack)->data > (*stack)->next->data)
			sa(stack);
		return ;
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
}

// // Function to sort the second half of the stack by using the stack b
// int	sort_second_half(t_stack **a , t_stack **b, int len)
// {
// 	t_stack	*min;

// 	if (!a || !*a)
// 		return (-1);
// 	while (len > 0)
// 	{
// 		min = dclst_find_min(*a, len);
// 		put_node_on_top_a(a, min);
// 		if (pb(a, b) < 0)
// 			return (-1);
// 		len--;
// 	}
// 	return (0);
// }

// // Function to sort a half of the stack by using the stack b
// int	sort_first_half(t_stack **a, t_stack **b, t_stack *pivot, int len)
// {
// 	t_stack	*max;
	
// 	if (!pivot || !a || !*a)
// 		return (-1);
// 	while (len > 0)
// 	{
// 		max = dclst_find_max(pivot, len);
// 		if (max == pivot)
// 			pivot = pivot->next;
// 		put_node_on_top_a(a, max);
// 		if (pb(a, b) < 0)
// 			return (-1);
// 		len--;
// 	}
// 	return (0);
// }

// // Function to get back the elements from the stack b to the stack a
// // from the highest to the lowest number
// int	get_back_to_a(t_stack **a, t_stack **b)
// {
// 	if (!*b || !b)
// 		return (-1);
// 	while (*b)
// 	{
// 		if ((*b)->data < (*b)->previous->data)
// 			rrb(b);
// 		if (pa(a, b) < 0)
// 			return (-1);
// 	}
// 	return (0);
// }

// Function to sort the stack a from the lowest to the highest number
// by using the stack b and the instructions
// int	push_swap(t_stack **a, t_stack **b)
// {
// 	int		stack_len;
// 	int		pivot_pos;
// 	int		pivot_len;
// 	t_stack	*pivot;

// 	if (is_sorted(*a) || !a || !*a)
// 		return (dclst_clear(a), dclst_clear(b), 0);
// 	stack_len = dclst_count_nodes(*a);
// 	if (stack_len <= 3)
// 		return (sort_3_or_less(a), dclst_clear(a), 0);
// 	pivot_pos = stack_len / 2 + stack_len / 4 - 1;
// 	pivot_len = stack_len / 2;
// 	pivot = dclst_find_node_with_pos(*a, pivot_pos);
// 	if (sort_first_half(a, b, pivot, pivot_len) < 0)
// 		return (dclst_clear(a), dclst_clear(b), -1);
// 	if (sort_second_half(a, b, dclst_count_nodes(*a)) < 0)
// 		return (dclst_clear(a), dclst_clear(b), -1);
// 	if (get_back_to_a(a, b) < 0)
// 		return (dclst_clear(a), dclst_clear(b), -1);

// 	// to be removed before submitting
// 	printf("Sorted list:\n");
// 	dclst_print(a);
// 	dclst_print(b);

// 	return (dclst_clear(a), dclst_clear(b), 0);
// }