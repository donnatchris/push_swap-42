/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:08:45 by christophed       #+#    #+#             */
/*   Updated: 2024/12/12 19:51:27 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new node in the doubly circular linked list
t_stack *clst_create_node(int data)
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
t_stack *clst_insert_node(t_stack **head, int data)
{
    t_stack *new;

    new = clst_create_node(data);
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

// Function to load the doubly circular linked list with the input values
t_stack *clst_load(char **av, int ac)
{
    t_stack *head;
    t_stack *new;
    int     data;
    int     i;

    head = NULL;
    i = 1;
    while (i < ac)
    {
        data = ft_atoi_long(av[i]);
        if (data < -2147483648 || data > 2147483647)
            return (ft_free_stack(head), NULL);
        new = clst_insert_node(&head, data);
        if (!new)
            return (ft_free_stack(head), NULL);
        i++;
    }
    return (head);
}