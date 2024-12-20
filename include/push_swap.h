/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:00:06 by christophed       #+#    #+#             */
/*   Updated: 2024/12/20 17:05:09 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ATENTION, MUST BE REMOVED BEFORE SUBMITTING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

// SRC DIRECTORY
// src/swap_functions.c
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		sb(t_stack **stack_b);
// src/push_functions.c
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
// src/reverse_rotate_functions.c
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
// src/rotate_functions.c
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
// src/recursive_sort.c
int		pivot_value(t_stack *head, int len);
int		sort_a(t_stack **a, t_stack **b, int len);
int		sort_b(t_stack **a, t_stack **b, int len);
int		divide_b_by_treshold(t_stack **a, t_stack **b, int len, int treshold);
int		divide_a_by_treshold(t_stack **a, t_stack **b, int len, int treshold);
int		push_swap(t_stack **a, t_stack **b);
// src/sort_utils.c
int		is_sorted(t_stack *stack);
int		sort_2a(t_stack **a);
int		sort_2b(t_stack **b);
int		sort_3_or_less(t_stack **stack);

// UTILS DIRECTORY
// utils/dclst1.c
t_stack	*dclst_create_node(int data);
t_stack	*dclst_insert_node_end(t_stack **head, int data);
t_stack	*dclst_insert_node_start(t_stack **head, int data);
void	dclst_remove_node(t_stack **head, t_stack *node);
void	dclst_clear(t_stack **head);
// utils/dclst2.c
int		dclst_count_nodes(t_stack *head);
void	dclst_print(t_stack *head);
t_stack	*dclst_find_min(t_stack *head);
t_stack	*dclst_find_max(t_stack *head);
int		dclst_find_node_pos(t_stack *head, t_stack *node);
t_stack	*dclst_find_node_with_pos(t_stack *head, int pos);
// utils/dclst3.c
int		dclst_swap_nodes(t_stack **head, t_stack *node1, t_stack *node2);
// src/error_manager.c
int		check_input(char **args);
int		is_int(long n);
int		has_double(t_stack *head, int data);
// utils/utils.c
t_stack	*dclst_load(char **args);
long	ft_atoi_long(const char *nptr);
size_t	ft_cpy_len(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *s);
int		ft_is_split(char c1, char c2);
int		ft_word_count(char const *s, char c);
void	ft_free_split(char **str_split, int words);
char	**ft_allocate(char const *s, char c, int words, char **str_split);
char	**ft_split(char const *s, char c);

#endif