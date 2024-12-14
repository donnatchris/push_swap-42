/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap_rotate.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: chdonnat <chdonnat@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/13 14:29:35 by chdonnat		  #+#	#+#			 */
/*   Updated: 2024/12/13 14:45:02 by chdonnat		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

// Function to shift all the elements of stack a up by one position
int	ra(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || *stack_a == (*stack_a)->next)
		return (-1);
	*stack_a = (*stack_a)->next;
	return (0);
}

// Function to shift all the elements of stack b up by one position
int	rb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || *stack_b == (*stack_b)->next)
		return (-1);
	*stack_b = (*stack_b)->next;
	return (0);
}

// Function to shift all the elements of stack a up by one position
// and shift all the elements of stack b up by one position
int	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	result;

	result = 0;
	result += ra(stack_a);
	result += rb(stack_b);
	return (result);
}
