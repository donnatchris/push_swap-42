/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quiet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:14:13 by christophed       #+#    #+#             */
/*   Updated: 2024/12/28 11:09:35 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to push the first element of the stack b to the stack a
void	quiet_pa(t_stack **a, t_stack **b)
{
	if (!b || !(*b))
		return ;
	dclst_move_node(b, a, *b);
}

// Function to push the first element of the stack a to the stack b
void	quiet_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	dclst_move_node(stack_a, stack_b, *stack_a);
}
