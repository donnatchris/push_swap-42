/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dclst2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:00 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/13 21:28:05 by christophed      ###   ########.fr       */
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

    // Swap the nodes
    temp_next = node1->next;
    temp_previous = node1->previous;
    if (node1->next == node2) { // node1 and node2 are adjacent
        node1->next = node2->next;
        node1->previous = node2;
        node2->next = node1;
        node2->previous = temp_previous;
    } else if (node2->next == node1) { // node2 and node1 are adjacent
        node2->next = node1->next;
        node2->previous = node1;
        node1->next = node2;
        node1->previous = temp_previous;
    } else { // nodes are not adjacent
        node1->next = node2->next;
        node1->previous = node2->previous;
        node2->next = temp_next;
        node2->previous = temp_previous;
    }
    node1->next->previous = node1;
    node1->previous->next = node1;
    node2->next->previous = node2;
    node2->previous->next = node2;
    return (0);
}
// int dclst_swap_node(t_stack *node1, t_stack *node2)
// {
//     t_stack *temp_next;
//     t_stack *temp_previous;

//     if (!node1 || !node2 || (node1 == node2))
//         return (-1);
// 	temp_next = node1->next;
//     temp_previous = node1->previous;
//     node1->next = node2->next;
// 	node1->previous = node2->previous;
//     node2->next = temp_next;
//     node2->previous = temp_previous;
//     node1->next->previous = node1;
//     node1->previous->next = node1;
//     node2->next->previous = node2;
//     node2->previous->next = node2;
// 	return (0);
// }

// Function to print the list
void dclst_print(t_stack *head)
{
    t_stack *current;

    if (!head)
        return ;
    current = head;
    while (current->next != head)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}