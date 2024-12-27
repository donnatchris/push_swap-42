/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:43:50 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 23:21:34 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to find the target in stack a
// which is the closest higher value to the data
t_stack	*find_target(t_stack *a, int data)
{
	t_stack	*current;
	t_stack	*target;
	int		len;

	current = a;
	target = NULL;
	len = dclst_count_nodes(a);
	while (len > 0)
	{
		if (current->data > data)
		{
			if (!target || current->data < target->data)
				target = current;
		}
		current = current->next;
		len--;
	}
	if (!target)
		target = dclst_find_min(a);
	return (target);
}

// Function to calculate the cost of pushing the node from stack b
// to stack a at its right place
int	calculate_sort_cost(t_stack *node)
{
	int		cost;

	if (node->better_up && node->target->better_up)
	{
		if (node->index > node->target->index)
			cost = node->index;
		else
			cost = node->target->index;
	}
	else if (!node->better_up && !node->target->better_up)
	{
		if (node->rr_cost > node->target->rr_cost)
			cost = node->rr_cost;
		else
			cost = node->target->rr_cost;
	}
	else
	{
		if (node->better_up)
			cost = node->index + node->target->rr_cost;
		else
			cost = node->target->index + node->rr_cost;
	}
	return (cost);
}

// Function to initialize the variables of all the nodes
// of stack b
void	initialize_variables_in_b(t_stack *a, t_stack *b)
{
	int		len;
	int		i;
	t_stack	*current;

	len = dclst_count_nodes(b);
	current = b;
	i = 0;
	while (i < len)
	{
		current->index = i;
		current->rr_cost = len - i;
		current->target = find_target(a, current->data);
		if (current->rr_cost > current->index)
			current->better_up = 1;
		else
			current->better_up = 0;
		current->sort_cost = calculate_sort_cost(current);
		current = current->next;
		i++;
	}
}

// Function to initilalize the variables of all the nodes
// of stack a
void	initialize_variables_in_a(t_stack *a)
{
	int		len;
	int		i;
	t_stack	*current;

	current = a;
	len = dclst_count_nodes(a);
	i = 0;
	while (i < len)
	{
		current->index = i;
		current->rr_cost = len - i;
		current->target = NULL;
		if (current->rr_cost > current->index)
		{
			current->better_up = 1;
			current->sort_cost = current->index;
		}
		else
		{
			current->better_up = 0;
			current->sort_cost = current->rr_cost;
		}
		current = current->next;
		i++;
	}
}
