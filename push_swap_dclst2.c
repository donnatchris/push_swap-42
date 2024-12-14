/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dclst2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:00 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/14 07:48:13 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void update_previous_pointers(t_stack *head)
{
    t_stack *current = head;

    if (!head)
        return;

    do {
        current->next->previous = current;
        current = current->next;
    } while (current != head);
}

// Function to swap 2 adjacent nodes in the doubly circular linked list
void swap_adjacent_nodes(t_stack **head, t_stack *node1, t_stack *node2)
{
    if (*head == node1)
        *head = node2;
    else if (*head == node2)
        *head = node1;
    node1->next = node2->next;
    node1->previous->next = node2;
    node2->next->previous = node1;
    node2->previous = node1->previous;
    node2->next = node1;
    node1->previous = node2;
}

// Function to swap 2 adjacent nodes in the doubly circular linked list
void swap_adjacent_nodes_reverse(t_stack **head, t_stack *node1, t_stack *node2)
{
    if (*head == node2)
        *head = node1;
    else if (*head == node1)
        *head = node2;
    node2->previous->next = node1;
    node1->next->previous = node2;
    node2->next = node1->next;
    node1->previous = node2->previous;
    node2->previous = node1;
    node1->next = node2;

}

// Function to swap 2 non adjacent nodes in the doubly circular linked list
void swap_non_adjacent_nodes(t_stack **head, t_stack *node1, t_stack *node2)
{
    t_stack *temp_next;
    t_stack *temp_previous;

    temp_next = node1->next;
    temp_previous = node1->previous;
    node1->previous->next = node2;
    node1->next->previous = node2;
    node2->previous->next = node1;
    node2->next->previous = node1;
    node1->next = node2->next;
    node1->previous = node2->previous;
    node2->next = temp_next;
    node2->previous = temp_previous;
    if (*head == node1)
        *head = node2;
    else if (*head == node2)
        *head = node1;
}

// Function to swap 2 nodes in the doubly circular linked list
int dclst_swap_nodes(t_stack **head, t_stack *node1, t_stack *node2)
{
    if (!head || !*head || !node1 || !node2 || (node1 == node2))
        return (-1);
    if (node1->next == node2)
        swap_adjacent_nodes(head, node1, node2);
    else if (node2->next == node1)
        swap_adjacent_nodes_reverse(head, node1, node2);
    else
        swap_non_adjacent_nodes(head, node1, node2);
    update_previous_pointers(*head);
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
        printf("%d  ", current->data);


    // TO BE SUPPRESSED BEFORE SUBMITTING
    printf("next points to %d AND ", current->next->data);
    printf("previous points to %d\n", current->previous->data);

        current = current->next;
    }
    printf("%d  ", current->data);

    // TO BE SUPPRESSED BEFORE SUBMITTING
    printf("next points to %d AND ", current->next->data);
    printf("previous points to %d\n", current->previous->data);
}