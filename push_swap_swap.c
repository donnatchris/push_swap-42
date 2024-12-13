/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:02:42 by christophed       #+#    #+#             */
/*   Updated: 2024/12/13 14:05:38 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to swap the first two elements of stack_a
int sa(t_stack **stack_a)
{
    int result;
    
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return (-1);
    result = dclst_swap_node(*stack_a, (*stack_a)->next);
    if (result == 0)
        *stack_a = (*stack_a)->next;
    return (result);
}

// Function to swap the first two elements of stack b
int sb(t_stack **stack_b) 
{
    int result;
    
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return (-1);
    result = dclst_swap_node(*stack_b, (*stack_b)->next);
    if (result == 0)
        *stack_b = (*stack_b)->next;
    return (result);
}

// Function to swap the first two elements of stack_a
// and swap the first two elements of swap_b
int ss(t_stack **stack_a, t_stack **stack_b)
{
    int result;

    result = 0;
    result += sa(stack_a);
    result += sb(stack_b);
    return (result);
}