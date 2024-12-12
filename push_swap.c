/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:08 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/12 21:36:00 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (check_input(av, ac) == -1)
		return (write(2, "Error\n", 6), 2);
	stack_a = clst_load(av, ac);
	if (stack_a == NULL)
		return (write(2, "Error\n", 6), 2);
}
