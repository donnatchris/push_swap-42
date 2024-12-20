/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:44:22 by christophed       #+#    #+#             */
/*   Updated: 2024/12/20 16:28:26 by christophed      ###   ########.fr       */
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
	printf("*****\nBEFORE SORT A\n*****\n");
	dclst_print(*a);
	dclst_print(*b);
	int		treshold;
	int		pushed;

	if (!a || !*a || len < 1)
		return (-1);
	if (len == 1)
		return (0);
	treshold = pivot_value(*a, len);
	printf("TRESHOLD = %d\n", treshold);
	if (treshold == -2147483648)
		return (-1);
	pushed = divide_a_by_treshold(a, b, len, treshold);
	if (pushed < 0)
		return (-1);
	printf("PUSHED = %d\n", pushed);
	len = len / 2 + len % 2;
	printf("NEW LEN = %d\n", len);
	if (len >2)
	{
		printf("OUVRE LA BOUCLE RECURSIVE A\n");
		if (sort_a(a, b, len) < 0)
			return (-1);
	}
	else if (len == 2)
	{
		printf("SORT 2A\n");
		if (sort_2a(a) < 0)
			return (-1);
	}
	if (pushed > 0)
	{
		printf("OUVRE SORT B DEPUIS SORT A\n");
		if (sort_b(a, b, pushed) < 0)
			return (-1);
	}
	return (0);
}

// Function to sort the remainder in stack_b
int	sort_b(t_stack **a, t_stack **b, int len)
{
	printf("*****\nBEFORE SORT B\n*****\n");
	dclst_print(*a);
	dclst_print(*b);
	int		treshold;
	int		pushed;

	if (!b || !*b || len < 1)
		return (-1);
	if (len > 2)
	{
		treshold = pivot_value(*b, len);
		printf("TRESHOLD = %d\n", treshold);
		if (treshold == -2147483648)
			return (-1);
		pushed = divide_b_by_treshold(a, b, len, treshold);
		printf("PUSHED = %d\n", pushed);
		if (pushed < 0)
			return (-1);
		len = len / 2;
		printf("NEW LEN = %d\n", len);
	}
	if (len > 2)
	{
		printf("OUVRE LA BOUCLE RECURSIVE B\n");
		if (sort_b(a, b, len) < 0)
			return (-1);
	}
	else if (len == 2)
	{
		printf("SORT 2B\n");
		if (sort_2b(b) < 0)
			return (-1);
	}
	if (pushed > 0)
	{
		printf("OUVRE SORT A DEPUIS SORT B\n");
		if (sort_a(a, b, pushed) < 0)
			return (-1);
	}
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
	if (sort_a(a, b, len) < 0)
		return (dclst_clear(a), dclst_clear(b), -1);
	if (!is_sorted(*a))
		write(1, "Sort has failed\n", 16);
	return (dclst_clear(a), dclst_clear(b), 0);	
}