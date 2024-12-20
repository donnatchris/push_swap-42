/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:44:22 by christophed       #+#    #+#             */
/*   Updated: 2024/12/20 15:07:19 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to find the median value in the stack
int	pivot_value(t_stack *head, int len)
{
	t_stack	*current;
	t_stack *pivot;
	int		n_inferior_values;
	int		j;
	int		i;

	if (!head || len < 	2)
		return (-2147483647);
	pivot = head;
	j = 0;
	while (j < len)
	{
		current = head;
		n_inferior_values = 0;
		i = 0;
		while (i < len)
		{
			if (current->data < pivot->data)
				n_inferior_values++;
			current = current->next;
			i++;
		}
		if (n_inferior_values == len / 2)
		{
			printf("PIVOT VALUE: %d\n", pivot->data);
			return (pivot->data);
		}
		pivot = pivot->next;
		j++;
	}
	return (-2147483647);
}

// Function to push all values below treshold to b
int	divide_a_by_treshold(t_stack **a, t_stack **b, int len, int treshold)
{
	printf("BEFORE DIVIDE A BY TRESHOLD\n");
	dclst_print(*a);
	dclst_print(*b);
	int		pushed;

	if (!a || !*a)
		return (-1);
	pushed = 0;
	while (pushed < len / 2)
	{
		if ((*a)->data < treshold)
		{
			if (pb(a, b) < 0)
				return (-1);
			pushed++;
		}
		else
			if (ra(a) < 0)
				return (-1);
	}
	return (pushed);
}

// Function to push all values below treshold to a
int	divide_b_by_treshold(t_stack **a, t_stack **b, int len, int treshold)
{
	printf("BEFORE DIVIDE B BY TRESHOLD\n");
	dclst_print(*a);
	dclst_print(*b);
	int		pushed;
	int		set_aside;

	if (!b || !*b)
		return (-1);
	set_aside = 0;
	pushed = 0;
	while (pushed < len / 2 + len % 2)
	{
		if ((*b)->data >= treshold)
		{
			if (pa(a, b) < 0)
				return (-1);
			pushed++;
		}
		else
		{
			if (rb(b) < 0)
				return (-1);
			set_aside++;
		}
	}
	while (set_aside > 0)
	{
		if (rrb(b) < 0)
			return (-1);
		set_aside--;
	}
	return (pushed);
}

// Function to sort the remainder in stack_a
int	sort_a(t_stack **a, t_stack **b, int len)
{
	printf("BEFORE SORT A\n");
	dclst_print(*a);
	dclst_print(*b);
	int		treshold;
	int		pushed;

	if (!a || !*a || len < 1)
		return (-1);
	if (len == 1)
		return (0);
	if (len == 2)
		return (sort_2(a, NULL));
	treshold = pivot_value(*a, len);
	if (treshold == -2147483648)
		return (-1);
	pushed = divide_a_by_treshold(a, b, len, treshold);
	if (pushed < 0)
		return (-1);
	if (pushed > 0)
	{
		if (sort_b(a, b, pushed) < 0)
			return (-1);
	}
	return (0);
}

// Function to sort the remainder in stack_b
int	sort_b(t_stack **a, t_stack **b, int len)
{
	printf("BEFORE SORT B\n");
	dclst_print(*a);
	dclst_print(*b);
	int		treshold;
	int		pushed;

	if (!b || !*b || len < 1)
		return (-1);
	if (len == 1)
		return (0);
	if (len == 2)
		return (sort_2(NULL, b));
	treshold = pivot_value(*b, len);
	if (treshold == -2147483648)
		return (-1);
	pushed = divide_b_by_treshold(a, b, len, treshold);
	if (pushed < 0)
		return (-1);
	if (pushed > 0)
	{
		if (sort_a(a, b, pushed) < 0)
			return (-1);
	}
	return (0);
}

// Function to make the first sort of the stack_a
int	first_sort_a(t_stack **a, t_stack **b, int len)
{
	printf("BEFORE FIRST SORT A\n");
	dclst_print(*a);
	dclst_print(*b);
	int		treshold;
	int		pushed;

	treshold = pivot_value(*a, len);
	if (treshold == -2147483648)
		return (-1);
	pushed = divide_a_by_treshold(a, b, len, treshold);
	if (pushed < 0)
		return (-1);
	if (sort_b(a, b, pushed) < 0)
		return (-1);
	printf("AFTER FIRST SORT A\n");
	dclst_print(*a);
	dclst_print(*b);
	return (0);
}

// Function to sort the stack_a with the recursive method
int	push_swap(t_stack **a, t_stack **b)
{
	int		len;

	if (is_sorted(*a) || !a || !*a)
		return (dclst_clear(a), 0);
	len = dclst_count_nodes(*a);
	if (len <= 3)
		return (dclst_clear(a), sort_3_or_less(a));
	if (first_sort_a(a, b, len) < 0)
		return (dclst_clear(a), dclst_clear(b), -1);
	if (!is_sorted(*a))
		write(1, "Sort has failed\n", 16);
	return (dclst_clear(a), dclst_clear(b), 0);	
}