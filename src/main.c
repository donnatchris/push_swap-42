/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:59 by christophed       #+#    #+#             */
/*   Updated: 2024/12/27 22:12:51 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to load the doubly circular linked list with the input values
t_stack	*dclst_load(char **args)
{
	t_stack	*head;
	t_stack	*new;
	long	data;
	int		i;

	head = NULL;
	i = 0;
	while (args[i])
	{
		data = ft_atoi_long(args[i]);
		if (is_int(data) == 0 || has_double(head, (int) data) != 0)
			return (dclst_clear(&head), NULL);
		new = dclst_insert_node_end(&head, (int) data);
		if (!new)
			return (dclst_clear(&head), NULL);
		i++;
	}
	return (head);
}

// Function to clear stacks and args
void	clear_all(t_stack **a, t_stack **b, char **args, int ac)
{
	int	i;

	if (a && *a)
		dclst_clear(a);
	if (b && *b)
		dclst_clear(b);
	if (ac == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
}

// Main function to sort the stack_a
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
		args = av + 1;
	if (check_input(args) == -1)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	a = dclst_load(args);
	if (a == NULL)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	push_swap(&a, &b);
	if (!is_sorted(a, dclst_count_nodes(a)) || b)
		write(1, "Sort has failed\n", 16);
	clear_all(&a, &b, args, ac);
	return (0);
}
