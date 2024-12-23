/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:07:28 by christophed       #+#    #+#             */
/*   Updated: 2024/12/23 10:42:39 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// // Function to sort a stack with 3 or less elements
// void	sort_3_or_less(t_stack **a)
// {
// 	// printf("SORT 3 OR LESS\n");
// 	int	stack_len;

// 	if (!a || !*a)
// 		return ;
// 	stack_len = dclst_count_nodes(*a);
// 	if (stack_len == 1)
// 		return ;
// 	else if (stack_len == 2)
// 	{
// 		if ((*a)->data > (*a)->next->data)
// 			SA;
// 		return ;
// 	}
// 	if ((*a)->data < (*a)->next->data && (*a)->data < (*a)->previous->data)
// 	{
// 		if ((*a)->next->data > (*a)->previous->data)
// 		{
// 			SA;
// 			RA;
// 		}
// 	}
// 	else if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->previous->data)
// 	{
// 		RA;
// 		if ((*a)->data > (*a)->next->data)
// 			SA;
// 	}
// 	else
// 	{
// 		if ((*a)->previous->data < (*a)->data)
// 			RRA;
// 		else
// 			SA;
// 	}
// }

// // Function to sort the len first elements of a stack
// // if len is <= 5
// int	tiny_sort(t_stack **a, t_stack **b, int len)
// {
// 	// printf("TINY SORT\n");
// 	// dclst_print(*a);
// 	// dclst_print(*b);
// 	if (len > 5 || !a || !*a)
// 		return (-1);
// 	if (len == 1 || is_sorted(*a, len))
// 		return (0);
// 	if (len == 2)
// 		return (sort_2a(a), 0);
// 	else if (len == 5)
// 		return (sort_5a(a, b));
// 	else if (len == 4)
// 		return (sort_4a(a, b));
// 	else
// 		return (sort_3_or_less(a), 0);
// }