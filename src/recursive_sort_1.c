/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:44:22 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 10:56:56 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to find the median value
// in the len first nodes of the stack head
int	pivot_value(t_stack *head, int len)
{
	t_stack	*current;
	t_stack	*pivot;
	int		n_inferior_values;
	int		j;
	int		i;

	pivot = head;
	j = 0;
	while (j++ < len)
	{
		current = head;
		n_inferior_values = 0;
		i = 0;
		while (i++ < len)
		{
			if (current->data < pivot->data)
				n_inferior_values++;
			current = current->next;
		}
		if (n_inferior_values == len / 2)
			return (pivot->data);
		pivot = pivot->next;
	}
	return (pivot->data);
}

// Function to sort the remainder in stack_b
void	sort_pushed_b(t_stack **a, t_stack **b, int len)
{
	int		treshold;
	int		pushed;

	if (len <= 2 || is_reverse_sorted(*b, len))
	{
		if (len == 2)
			sort_2b(b);
		get_back_to_a(a, b, len);
	}
	else
	{
		treshold = pivot_value(*b, len);
		pushed = divide_b_by_treshold(a, b, len, treshold);
		if (pushed > 0)
			sort_pushed_a(a, b, pushed);
		len = len / 2;
		sort_pushed_b(a, b, len);
	}
}

// Function to sort the remainder in stack_a
void	sort_pushed_a(t_stack **a, t_stack **b, int len)
{
	int		treshold;
	int		pushed;

	if (len == 1 || is_sorted(*a, len))
		return ;
	else if (len == 2)
		sort_2a(a);
	else
	{
		treshold = pivot_value(*a, len);
		pushed = divide_a_by_treshold(a, b, len, treshold);
		len = len / 2 + len % 2;
		if (len > 1)
			sort_pushed_a(a, b, len);
		if (pushed > 0)
			sort_pushed_b(a, b, pushed);
	}
}

// Function to sort stack_a using recursives functions
void	recursive_sort(t_stack **a, t_stack **b, int len)
{
	int		treshold;
	int		pushed;

	if (is_sorted(*a, len))
		return ;
	else if (len == 2)
		sort_2a(a);
	else if (len == 3)
		sort_3(a);
	else
	{
		treshold = pivot_value(*a, len);
		pushed = first_divide_a_by_treshold(a, b, len, treshold);
		len = len / 2 + len % 2;
		if (len > 1)
			recursive_sort(a, b, len);
		if (pushed > 0)
			sort_pushed_b(a, b, pushed);
	}
}

// Function to sort the stack_a with the recursive method
// Returns 0 if the sort is successful
// Returns -1 if the process has failed
void	push_swap(t_stack **a, t_stack **b)
{
	int		len;

	if (!a || !*a)
		return ;
	len = dclst_count_nodes(*a);
	if (is_sorted(*a, len))
		return ;
	recursive_sort(a, b, len);
	if (!is_sorted(*a, len) || *b)
		write(1, "Sort has failed\n", 16);
}
