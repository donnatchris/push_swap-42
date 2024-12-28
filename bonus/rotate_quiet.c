/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_quiet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:15:17 by christophed       #+#    #+#             */
/*   Updated: 2024/12/28 11:08:56 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to shift all the elements of stack a up by one position
void	quiet_ra(t_stack **a)
{
	if (!a || !*a || *a == (*a)->next)
		return ;
	*a = (*a)->next;
}

// Function to shift all the elements of stack b up by one position
void	quiet_rb(t_stack **b)
{
	if (!b || !*b || *b == (*b)->next)
		return ;
	*b = (*b)->next;
}

// Function to shift all the elements of stack a up by one position
// and shift all the elements of stack b up by one position
void	quiet_rr(t_stack **a, t_stack **b)
{
	if (!a || !b || !*a || !*b)
		return ;
	*a = (*a)->next;
	*b = (*b)->next;
}
