/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_quiet.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:16:30 by christophed       #+#    #+#             */
/*   Updated: 2025/01/29 18:49:17 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to shift all the elements of stack a down by one position
void	quiet_rra(t_stack **a)
{
	if (!a || !*a || !(*a)->previous)
		return ;
	*a = (*a)->previous;
}

// Function to shift all the elements of stack b down by one position
void	quiet_rrb(t_stack **b)
{
	if (!b || !*b || !(*b)->previous)
		return ;
	*b = (*b)->previous;
}

// Function to shift all the elements of stack a down by one position
// and shift all the elements of stack b down by one position
void	quiet_rrr(t_stack **a, t_stack **b)
{
	if (a && *a)
		*a = (*a)->previous;
	if (b && *b)
		*b = (*b)->previous;
}
