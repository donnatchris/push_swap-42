/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:13:35 by christophed       #+#    #+#             */
/*   Updated: 2025/01/06 11:45:52 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Main function test the instructions to sort the stack a
// Return "OK" if the stack is sorted, "KO" if not,
// or "Error" if there is an error
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av +1;
	if (check_input(args) == -1)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	a = dclst_load(args);
	if (a == NULL)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	if (checker(&a, &b) < 0)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	if (!is_sorted(a, dclst_count_nodes(a)) || b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	clear_all(&a, &b, args, ac);
	return (0);
}
