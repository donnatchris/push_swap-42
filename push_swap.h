/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:20:47 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/13 14:29:09 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

// push_swap.c
t_stack *dclst_load(char **av, int ac);

// push_swap_error_manager.c
int		check_input(char **array, int ac);
int		is_int(long n);
int	has_double(t_stack *head, int data);

// push_swap_utils.c
long	ft_atoi_long(const char *nptr);

// push_swap_dclst1.c
t_stack	*dclst_create_node(int data);
t_stack	*dclst_insert_node_end(t_stack **head, int data);
t_stack *dclst_insert_node_start(t_stack **head, int data);
void    dclst_remove_node(t_stack **head, t_stack *node);
void    dclst_clear(t_stack **head);

// push_swap_dclst2.c
int dclst_swap_node(t_stack *node1, t_stack *node2);

// push_swap_swap.c
int sa(t_stack **stack_a);
int sb(t_stack **stack_b);
int sb(t_stack **stack_b);

// push_swap_push.c
int    pa(t_stack **stack_a, t_stack **stack_b);
int    pb(t_stack **stack_a, t_stack **stack_b);

#endif