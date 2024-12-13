/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dclst2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:00 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/13 22:06:15 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to swap 2 nodes
int dclst_swap_nodes(t_stack *node1, t_stack *node2)
{
    int temp;

    if (!node1 || !node2 || (node1 == node2))
        return (-1);
    temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
    return (0);
}

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