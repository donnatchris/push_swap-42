/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:20:17 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 10:54:05 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to move a node from the stack origin
// to the top of the stack destination
void	dclst_move_node(t_stack **origin, t_stack**destination, t_stack *node)
{
	if (node == *origin)
	{
		if ((*origin)->next == *origin)
			*origin = NULL;
		else
			*origin = node->next;
	}
	node->next->previous = node->previous;
	node->previous->next = node->next;
	if (!*destination)
	{
		*destination = node;
		node->next = node;
		node->previous = node;
	}
	else
	{
		node->next = *destination;
		node->previous = (*destination)->previous;
		(*destination)->previous->next = node;
		(*destination)->previous = node;
		*destination = node;
	}
}
