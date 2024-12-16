/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:00:06 by christophed       #+#    #+#             */
/*   Updated: 2024/12/16 12:27:30 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ATENTION, MUST BE REMOVED BEFORE SUBMITTING
# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

// Structure for the doubly circular linked list
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

// push_swap.c
t_stack	*dclst_load(char **av, int ac);

// src/error_manager.c
int		check_input(char **array, int ac);
int		is_int(long n);
int		has_double(t_stack *head, int data);

// src/utils.c
long	ft_atoi_long(const char *nptr);

// dclst_functions/dclst1.c
t_stack	*dclst_create_node(int data);
t_stack	*dclst_insert_node_end(t_stack **head, int data);
t_stack	*dclst_insert_node_start(t_stack **head, int data);
void	dclst_remove_node(t_stack **head, t_stack *node);
void	dclst_clear(t_stack **head);

// dclst_functions/dclst2.c
int		dclst_count_nodes(t_stack *head);
void	dclst_print(t_stack *head);
t_stack	*dclst_find_min(t_stack *head);
int		dclst_find_node_position(t_stack *head, t_stack *node);

// dclst_functions/dclst3.c
static void	update_previous_pointers(t_stack *head);
static void	swap_adjacent_nodes(t_stack **head, t_stack *node1, t_stack *node2);
static void	swap_non_adjacent_nodes(t_stack **head, t_stack *node1, t_stack *node2);
int			dclst_swap_nodes(t_stack **head, t_stack *node1, t_stack *node2);

// src/swap_functions.c
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		sb(t_stack **stack_b);

// src/push_functions.c
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

// src/rotate_functions.c
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

// src/reverse_rotate_functions.c
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

// src/sort_functions.c
int		is_sorted(t_stack *stack);
int		push_all_b_to_a(t_stack **stack_a, t_stack **stack_b);
int		put_min_top(t_stack **stack_a);
int		sort_stack_a(t_stack **stack_a, t_stack **stack_b);

#endif