/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:04:59 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/13 14:27:31 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to push the first element of the stack b to the stack a
int    pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *new;
    
    if (!stack_b || !(*stack_b))
        return (-1);
    new = dclst_insert_node_start(stack_a, (*stack_b)->data);
    if (!new)
        return (-1);
    // attention a free
    dclst_remove_node(stack_b, *stack_b);
    return (0);
}

// Function to push the first element of the stack a to the stack b
int    pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *new;
    
    if (!stack_a || !(*stack_a))
        return (-1);
    new = dclst_insert_node_start(stack_b, (*stack_a)->data);
    if (!new)
        return (-1);
        // attention a free
    dclst_remove_node(stack_a, *stack_a);
    return (0);
}