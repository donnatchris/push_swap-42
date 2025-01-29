/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:29 by christophed       #+#    #+#             */
/*   Updated: 2025/01/29 18:51:35 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to shift all the elements of stack a down by one position
void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	if (!a || !*a || !(*a)->previous)
		return ;
	*a = (*a)->previous;
}

// Function to shift all the elements of stack b down by one position
void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	if (!b || !*b || !(*b)->previous)
		return ;
	*b = (*b)->previous;
}

// Function to shift all the elements of stack a down by one position
// and shift all the elements of stack b down by one position
void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	if (a && *a)
		*a = (*a)->previous;
	if (b && *b)
		*b = (*b)->previous;
}
