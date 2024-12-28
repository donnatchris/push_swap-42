/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:00:06 by christophed       #+#    #+#             */
/*   Updated: 2024/12/28 11:11:13 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include <unistd.h>
# include <stdlib.h>

// Structure for the doubly circular linked list
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*previous;
	int				index;
	int				rr_cost;
	int				better_up;
	struct s_stack	*target;
	int				sort_cost;
}					t_stack;

// SRC DIRECTORY
// src/load_and_clear.c
// load the stack, free everything
t_stack	*dclst_load(char **args);
void	clear_all(t_stack **a, t_stack **b, char **args, int ac);
// src/swap_functions.c
// swap the first two elements of stack a, stack b, or both
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
// src/push_functions.c
// push the first element of stack b to stack a,
// or the first element of stack a to stack b
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
// src/reverse_rotate_functions.c
// reverse rotate the stack a, stack b, or both
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
// src/rotate_functions.c
// rotate the stack a, stack b, or both
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
// src/sort.c
// sort the stack a
void	put_lowest_to_top(t_stack **a);
void	push_node_to_a(t_stack **a, t_stack **b, t_stack *node);
t_stack	*find_cheapest_node(t_stack *b);
void	sort_from_b_to_a(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
// src/variable_initializers.c
// initialize the variables (needed for sorting) of all the nodes
void	initialize_variables_in_b(t_stack *a, t_stack *b);
void	initialize_variables_in_a(t_stack *a);
int		calculate_sort_cost(t_stack *node);
t_stack	*find_target(t_stack *a, int data);
// src/sort_utils.c
// check if the first len nodes of stack are sorted or reverse sorted
// and sort tiny stacks
int		is_sorted(t_stack *stack, int len);
int		is_reverse_sorted(t_stack *stack, int len);
void	sort_2a(t_stack **a);
void	sort_2b(t_stack **b);
void	sort_3(t_stack **a);

// UTILS DIRECTORY
// utils/dclst1.c utils/dclst2.c utils/dclst3.c utils/dclst4.c
// functions to manipulate doubly circular linked lists
t_stack	*dclst_create_node(int data);
t_stack	*dclst_insert_node_end(t_stack **head, int data);
t_stack	*dclst_insert_node_start(t_stack **head, int data);
void	dclst_remove_node(t_stack **head, t_stack *node);
void	dclst_clear(t_stack **head);
void	dclst_print(t_stack *head);
t_stack	*dclst_find_min(t_stack *head);
t_stack	*dclst_find_max(t_stack *head);
int		dclst_find_node_pos(t_stack *head, t_stack *node);
t_stack	*dclst_find_node_with_pos(t_stack *head, int pos);
int		dclst_count_nodes(t_stack *head);
int		dclst_swap_nodes(t_stack **head, t_stack *node1, t_stack *node2);
void	dclst_move_node(t_stack **origin, t_stack **destination, t_stack *node);
t_stack	*dclst_find_next_higher(t_stack *head, t_stack *node);
// src/error_manager.c
// check if the input is valid, if it is an int, and if it has a double
int		check_input(char **args);
int		is_int(long n);
int		has_double(t_stack *head, int data);
// utils/ft_atoi_long.c
// convert a string to a long
long	ft_atoi_long(const char *nptr);

// BONUS DIRECTORY
// bonus/checker.c
// check if the instructions are valid and
// if the stack is sorted after executing the instructions
int		instruction_4(t_stack **a, t_stack **b, char *line);
int		instruction_3(t_stack **a, t_stack **b, char *line);
int		instruction(t_stack **a, t_stack **b, char *line);
int		checker(t_stack **a, t_stack **b);
// bonus/push_quiet.c
// push the first element of one stack to another
// without printing anything
void	quiet_pa(t_stack **a, t_stack **b);
void	quiet_pb(t_stack **a, t_stack **b);
// bonus/reverse_rotate_quiet.c
// reverse rotate the stack a, stack b, or both
// without printing anything
void	quiet_rra(t_stack **a);
void	quiet_rrb(t_stack **b);
void	quiet_rrr(t_stack **a, t_stack **b);
// bonus/rotate_quiet.c
// rotate the stack a, stack b, or both
// without printing anything
void	quiet_ra(t_stack **a);
void	quiet_rb(t_stack **b);
void	quiet_rr(t_stack **a, t_stack **b);
// bonus/swap_quiet.c
// swap the first two elements of stack a, stack b, or both
// without printing anything
void	quiet_sa(t_stack **a);
void	quiet_sb(t_stack **b);
void	quiet_ss(t_stack **a, t_stack **b);

#endif