/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:44:22 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 16:32:00 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to get nodes back from stack_b to stack_a
// from the highest rank to the lowest rank
void	get_back_in_order(t_stack **a, t_stack **b, int len)
{
	int		rank;
	int		set_aside;

	rank = len - 3;
	while (rank > 0)
	{
		set_aside = 0;
		while ((*b)->rank != rank)
		{
			// trying someting
			// if ((*b)->rank == rank - 2)
			// {
			// 	rrb(b);
			// 	pa(a, b);
			// 	set_aside = 1;
			// }
			else if ((*b)->rank == rank - 1)
			{
				pa(a, b);
				set_aside = 1;
			}
			else
				rb(b);
		}
		pa(a, b);
		if (set_aside == 1)
		{
			sa(a);
			rank--;
		}
		rank--;
	}
}

// Function to push every element from stack_a to stack_b
// except nodes with rank len to len - 2
void	push_all_to_b(t_stack **a, t_stack **b, int len)
{
	int	treshold;

	treshold = len - 3;
	while (len > 0)
	{
		if ((*a)->rank > treshold)
			ra(a);
		else
			pb(a, b);
		len--;
	}
}

// Function to sort the stack_a
void	push_swap(t_stack **a, t_stack **b)
{
	int		len;

	if (!a || !*a)
		return ;
	len = dclst_count_nodes(*a);
	if (is_sorted(*a, len))
		return ;
	if (len == 2)
		sort_2a(a);
	else if (len == 3)
		sort_3(a);
	else
	{
		dclst_affect_rank(*a, len);
		push_all_to_b(a, b, len);
		sort_3(a);
		get_back_in_order(a, b, len);
		// dclst_print(*a);
	}
}
