/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_and_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:30:18 by christophed       #+#    #+#             */
/*   Updated: 2024/12/28 10:30:57 by christophed      ###   ########.fr       */
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
