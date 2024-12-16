/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:05 by christophed       #+#    #+#             */
/*   Updated: 2024/12/16 10:59:58 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function to count the number of nodes in the doubly circular linked list
int	dclst_count_nodes(t_stack *head)
{
	t_stack	*current;
	int		count;

	count = 0;
	if (head)
	{
		current = head;
		while (current->next != head)
		{
			count++;
			current = current->next;
		}
		count++;
	}
	return (count);
}

// Function to print the doubly circular linked list 
void	dclst_print(t_stack *head)
{
	t_stack	*current;

	if (head)
	{
		current = head;
		while (current->next != head)
		{
			printf("%d ", current->data);
			current = current->next;
		}
		printf("%d", current->data);
	}
	printf("\n");
}

// Function to find the minimum value in the doubly circular linked list
t_stack	*dclst_find_min(t_stack *head)
{
	t_stack	*current;
	t_stack	*min;

	if (!head)
		return (NULL);
	current = head;
	min = current;
	while (current->next != head)
	{
		if (current->data < min->data)
			min = current;
		current = current->next;
	}
	if (current->data < min->data)
		min = current;
	return (min);
}