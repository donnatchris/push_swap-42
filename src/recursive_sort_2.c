/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:58:57 by christophed       #+#    #+#             */
/*   Updated: 2024/12/26 11:56:47 by christophed      ###   ########.fr       */
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
			if (PB < 0)
				return (-1);
			pushed++;
		}
		else
			RA;
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
			if (PB < 0)
				return (-1);
			pushed++;
		}
		else
		{
			RA;
			set_aside++;
		}
	}
	if (len == dclst_count_nodes(*a))
		set_aside = 0;
	while (set_aside > 0 && dclst_count_nodes(*a) > 1)
	{
		RRA;
		set_aside--;
	}
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
			if (PA < 0)
				return (-1);
			pushed++;
		}
		else
		{
			RB;
			set_aside++;
		}
	}
	while (set_aside > 0 && dclst_count_nodes(*b) > 1)
	{
		RRB;
		set_aside--;
	}
	return (pushed);
}

// Function to push back the first len nodes from stack b to stack a
int	get_back_to_a(t_stack **a, t_stack **b, int len)
{
	while (len > 0)
	{
		if (PA < 0)
			return (-1);
		len--;
	}
	return (0);
}

// Function to push back the first len nodes from stack a to stack b
int	get_back_to_b(t_stack **a, t_stack **b, int len)
{
	while (len > 0)
	{
		if (PB < 0)
			return (-1);
		len--;
	}
	return (0);
}
