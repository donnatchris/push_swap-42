/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dclst2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:00 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/13 13:27:18 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to swap 2 nodes
int dclst_swap_node(t_stack *node1, t_stack *node2)
{
    t_stack *temp_next;
    t_stack *temp_previous;

    if (!node1 || !node2 || (node1 == node2))
        return (-1);
	temp_next = node1->next;
    temp_previous = node1->previous;
    node1->next = node2->next;
	node1->previous = node2->previous;
    node2->next = temp_next;
    node2->previous = temp_previous;
    node1->next->previous = node1;
    node1->previous->next = node1;
    node2->next->previous = node2;
    node2->previous->next = node2;
	return (0);
}