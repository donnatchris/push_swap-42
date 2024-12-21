/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:05:24 by christophed       #+#    #+#             */
/*   Updated: 2024/12/21 08:02:15 by christophed      ###   ########.fr       */
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
void	sort_2a(t_stack **a)
{
	// printf("SORT 2A\n");
	if (!a || !*a)
		return ;
	if ((*a)->data > (*a)->next->data)
		SA;
}

// Function to sort the 2 elements at the top of a stack b
void	sort_2b(t_stack **b)
{
	// printf("SORT 2B\n");
	if (!b || !*b)
		return ;
	if ((*b)->data < (*b)->next->data)
		SB;
}

// Function to sort a stack with 3 or less elements
void	sort_3_or_less(t_stack **a)
{
	// printf("SORT 3 OR LESS\n");
	int	stack_len;

	if (!a || !*a)
		return ;
	stack_len = dclst_count_nodes(*a);
	if (stack_len == 1)
		return ;
	else if (stack_len == 2)
	{
		if ((*a)->data > (*a)->next->data)
			SA;
		return ;
	}
	if ((*a)->data < (*a)->next->data && (*a)->data < (*a)->previous->data)
	{
		if ((*a)->next->data > (*a)->previous->data)
		{
			SA;
			RA;
		}
	}
	else if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->previous->data)
	{
		RA;
		if ((*a)->data > (*a)->next->data)
			SA;
	}
	else
	{
		if ((*a)->previous->data < (*a)->data)
			RRA;
		else
			SA;
	}
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