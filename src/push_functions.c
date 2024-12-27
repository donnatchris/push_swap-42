/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:22 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 10:25:55 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to push the first element of the stack b to the stack a
void	pa(t_stack **a, t_stack **b)
{
	if (!b || !(*b))
		return ;
	write(1, "pa\n", 3);
	dclst_move_node(b, a, *b);
}

// Function to push the first element of the stack a to the stack b
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	write(1, "pb\n", 3);
	dclst_move_node(stack_a, stack_b, *stack_a);
}
