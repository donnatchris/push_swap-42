/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:06:06 by christophed       #+#    #+#             */
/*   Updated: 2024/12/19 00:39:42 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to find the first pivot in the stack
// which must be the median value
t_stack	*find_pivot(t_stack *head, int len)
{
	t_stack	*current;
	t_stack *pivot;
	int		n_inferior_values;
	int		j;
	int		i;

	if (!head)
		return (NULL);
	pivot = head;
	j = 0;
	while (j < len)
	{
		current = head;
		n_inferior_values = 0;
		i = 0;
		while (i < len)
		{
			if (current->data < pivot->data)
				n_inferior_values++;
			current = current->next;
			i++;
		}
		if (n_inferior_values == len / 2)
			return (pivot);
		pivot = pivot->next;
		j++;
	}
	return (NULL);
}

// Function to find the next higher value in the stack
t_stack	*find_next_higher(t_stack *head, t_stack *node)
{
	t_stack	*current;
	t_stack	*next_higher;

	if (!head || !node)
		return (NULL);
	next_higher = NULL;
	current = node->next;
	while (current != node)
	{
		if (current->data > node->data)
		{
			if (!next_higher)
				next_higher = current;
			else if (current->data < next_higher->data)
				next_higher = current;
		}
		current = current->next;
	}
	return (next_higher);
}

// Function to put a node on top of the stack a
// and push the elements lower than the treshold to the stack b
// while they are passing on top of the stack a
int	put_node_on_top_a(t_stack **a, t_stack **b, t_stack *node, int treshold)
{
	if (!a || !*a || !node)
		return (-1);
	while ((*a)->data < treshold)
	{
		if (pb(a, b) < 0)
			return (-1);
	}
	if (dclst_find_node_pos(*a, node) <= dclst_count_nodes(*a) / 2)
	{
		while (*a != node)
		{
			ra(a);
			if ((*a)->data < treshold)
				if (pb(a, b) < 0)
					return (-1);
		}
	}
	else
	{
		while (*a != node)
		{
			rra(a);
			if ((*a)->data < treshold)
				if (pb(a, b) < 0)
					return (-1);
		}
	}
	return (0);
}

// Function to sort all the elements greater or equal to the pivot in the stack a
// and push the elements lower than the pivot to the stack b
int	sort_by_pivot(t_stack **a, t_stack **b, int len)
{
	t_stack	*pivot;
	int		treshold;

// ATTENTION GROSSE ERREUR IL FAUT DEMARRER PAR LE MAX
// ET DESCENDRE JUSQU'A LA VALEUR DU PIVOT


	if (!a || !*a)
		return (-1);
	pivot = find_pivot(*a, len);
	treshold = pivot->data;
	if (!pivot)
		return (-1);
	while (pivot)
	{
		printf("pivot = %d\n", pivot->data);
		printf("treshold = %d\n", treshold);
		printf("stack a = ");
		dclst_print(*a);
		printf("stack b = ");
		dclst_print(*b);
		if (put_node_on_top_a(a, b, pivot, treshold) < 0)
			return (-1);
		pivot = find_next_higher(*a, pivot);
	}
	return (0);
}

// Function to sort the stack a by central pivot
int	push_swap(t_stack **a, t_stack **b)
{
	int	len;

	if (is_sorted(*a) || !a || !*a)
		return (dclst_clear(a), 0);
	len = dclst_count_nodes(*a);
	if (len <= 3)
		return (sort_3_or_less(a), dclst_clear(a), 0);
	sort_by_pivot(a, b, len);
	return (0);
}