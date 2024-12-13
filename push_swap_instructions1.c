/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:02:42 by christophed       #+#    #+#             */
/*   Updated: 2024/12/13 12:11:12 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to swap the first two elements of a stack
int    swap(t_stack **head)
{
    int temp;

    if (!*head || (*head)->next == *head)
        return (1);
    temp = (*head)->data;
    (*head)->data = (*head)->next->data;
    (*head)->next->data = temp;
}

// Function to swap the first two elements of the stack b
int    sb(t_stack **stack_b) 

// Function to swap the first two elements of the stack a and b
int    ss(t_stack **stack_a, t_stack **stack_b)

// Function to push the first element of the stack b to the stack a
int    pa(t_stack **stack_a, t_stack **stack_b)

// Function to push the first element of the stack a to the stack b
int    pb(t_stack **stack_a, t_stack **stack_b)

// Function to rotate the stack a
int    ra(t_stack **stack_a)

// Function to rotate the stack b
int    rb(t_stack **stack_b)

// Function to rotate the stack a and b
int    rr(t_stack **stack_a, t_stack **stack_b)

// Function to reverse rotate the stack a
int    rra(t_stack **stack_a)

// Function to reverse rotate the stack b
int    rrb(t_stack **stack_b)

// Function to reverse rotate the stack a and b
int    rrr(t_stack **stack_a, t_stack **stack_b)

/*
sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
ss : sa et sb en même temps.
pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
rr : ra et rb en même temps.
rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
rrr : rra et rrb en même temps.
*/