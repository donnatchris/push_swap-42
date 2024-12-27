/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:58:57 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 10:48:04 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to push the first len elements below treshold
// from stack a to stack b
int	first_divide_a_by_treshold(t_stack **a, t_stack **b, int len, int treshold)
{
	int		pushed;

	pushed = 0;
	while (pushed < len / 2)
	{
		if ((*a)->data < treshold)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	return (pushed);
}

// Function to push the first len elements below treshold
// from stack a to stack b
// and the get back the set aside elements
// at the bottom of the stack a to the top of the stack a
int	divide_a_by_treshold(t_stack **a, t_stack **b, int len, int treshold)
{
	int		pushed;
	int		set_aside;

	set_aside = 0;
	pushed = 0;
	while (pushed < len / 2)
	{
		if ((*a)->data < treshold)
		{
			pb(a, b);
			pushed++;
		}
		else
		{
			ra(a);
			set_aside++;
		}
	}
	if (len == dclst_count_nodes(*a))
		set_aside = 0;
	while (set_aside-- > 0 && dclst_count_nodes(*a) > 1)
		rra(a);
	return (pushed);
}

// Function to push the first len elements above treshold
// from stack b to stack a
// and the get back the set aside elements
// at the bottom of the stack b to the top of the stack b
int	divide_b_by_treshold(t_stack **a, t_stack **b, int len, int treshold)
{
	int		pushed;
	int		set_aside;

	set_aside = 0;
	pushed = 0;
	while (pushed < len / 2 + len % 2)
	{
		if ((*b)->data >= treshold)
		{
			pa(a, b);
			pushed++;
		}
		else
		{
			rb(b);
			set_aside++;
		}
	}
	while (set_aside-- > 0 && dclst_count_nodes(*b) > 1)
		rrb(b);
	return (pushed);
}

// Function to push back the first len nodes from stack b to stack a
void	get_back_to_a(t_stack **a, t_stack **b, int len)
{
	while (len-- > 0)
		pa(a, b);
}

// Function to push back the first len nodes from stack a to stack b
void	get_back_to_b(t_stack **a, t_stack **b, int len)
{
	while (len-- > 0)
		pb(a, b);
}
