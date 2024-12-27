/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:44:22 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 18:04:46 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to find if rb or rrb is the shortest way to push the node
// with the highest rank to the top of the stack
void	find_shortest_way(t_stack **b)
{
	int		len;
	int		i;
	int		way;
	t_stack	*current;
	t_stack	*target;

	target = dclst_find_max(*b);
	len = dclst_count_nodes(*b);
	way = 0;
	i = 0;
	current = *b;
	while (current != target)
	{
		current = current->next;
		i++;
	}
	if (i > len / 2)
		return (&rrb);
	else
		return (&rb);
}


// Function to get nodes back from stack_b to stack_a
// from the highest rank to the lowest rank
void	get_back_in_order(t_stack **a, t_stack **b, int len)
{
	int		rank;
	int		next_push;
	int		next_push2;

	rank = len - 3;
	next_push2 = 0;
	while (rank > 0)
	{
		if (next_push2 != 0)
		{
			if (next_push == 0)
			{
				while ((*b)->rank != rank)
					rb(b);
				pa(a, b);
			}
			rra(a);
			rank = next_push2;
			next_push2 = 0;
		}
		else
		{
			next_push = 0;
			while ((*b)->rank != rank)
			{
				if ((*b)->rank == rank - 2)
				{
					next_push2 = (*b)->rank;
					pa(a, b);
					ra(a);
				}
				else if ((*b)->rank == rank - 1)
				{
					pa(a, b);
					next_push = 1;
				}
				else
					rb(b);
			}
			pa(a, b);
			if (next_push == 1)
			{
				sa(a);
				rank--;
			}
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
		// ft_printf("STACK A\n");
		// dclst_print(*a);
		// ft_printf("STACK B\n");
		// dclst_print(*b);
	}
}
