/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:02:42 by christophed       #+#    #+#             */
/*   Updated: 2024/12/12 22:06:55 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to swap the first two elements of the stack a
void    sa(t_stack **stack_a)

// Function to swap the first two elements of the stack b
void    sb(t_stack **stack_b)  

// Function to swap the first two elements of the stack a and b
void    ss(t_stack **stack_a, t_stack **stack_b)

// Function to push the first element of the stack b to the stack a
void    pa(t_stack **stack_a, t_stack **stack_b)

// Function to push the first element of the stack a to the stack b
void    pb(t_stack **stack_a, t_stack **stack_b)

// Function to rotate the stack a
void    ra(t_stack **stack_a)

// Function to rotate the stack b
void    rb(t_stack **stack_b)

// Function to rotate the stack a and b
void    rr(t_stack **stack_a, t_stack **stack_b)

// Function to reverse rotate the stack a
void    rra(t_stack **stack_a)

// Function to reverse rotate the stack b
void    rrb(t_stack **stack_b)

// Function to reverse rotate the stack a and b
void    rrr(t_stack **stack_a, t_stack **stack_b)

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