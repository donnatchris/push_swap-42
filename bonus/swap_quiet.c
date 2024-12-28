/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_quiet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:41:41 by christophed       #+#    #+#             */
/*   Updated: 2024/12/28 10:42:20 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to swap the first two elements of stack_a
void	quiet_sa(t_stack **a)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	dclst_swap_nodes(a, *a, (*a)->next);
}

// Function to swap the first two elements of stack b
void	quiet_sb(t_stack **b)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	dclst_swap_nodes(b, *b, (*b)->next);
}

// Function to swap the first two elements of stack_a
// and swap the first two elements of swap_b
void	quiet_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	dclst_swap_nodes(a, *a, (*a)->next);
	dclst_swap_nodes(b, *b, (*b)->next);
}
