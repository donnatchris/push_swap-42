/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:45 by christophed       #+#    #+#             */
/*   Updated: 2024/12/13 09:52:37 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new node in the doubly circular linked list
t_stack *dclst_create_node(int data)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = new;
    new->previous = new;
    return (new);
}

// Function to insert a new node at the end of the doubly circular linked list
t_stack *dclst_insert_node_end(t_stack **head, int data)
{
    t_stack *new;

    new = dclst_create_node(data);
    if (!new)
        return (NULL);
    if (!*head)
        *head = new;
    else
    {
        new->next = *head;
        new->previous = (*head)->previous;
        (*head)->previous->next = new;
        (*head)->previous = new;
    }
    return (new);
}

// Function to insert a new node at the start of the doubly circular linked list
t_stack *dclst_insert_node_start(t_stack **head, int data)
{
    t_stack	*new;

    new = dclst_insert_node_end(head, data);
    if (!new)
        return (NULL);
    *head = new;
    return (new);
}

// Function to remove a nod from the doubly circular linked list
void    dclst_remove_node(t_stack **head, t_stack *node)
{
    if (head && *head && node)
    {
		if (node == *head)
		{
			if ((*head)->next == *head)
			{
				free (*head);
				*head = NULL;
				return ;
			}
			*head = node->next;
		}
		node->next->previous = node->previous;
		node->previous->next = node->next;
		free(node);
    }
}