/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:20:47 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/12 20:25:39 by christophed      ###   ########.fr       */
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

// push_swap_error_manager.c
int		check_input(char **array, int ac);

// push_swap_utils.c
long	ft_atoi_long(const char *nptr);

// push_swap_clst.c
t_stack	*clst_create_node(int data);
t_stack	*clst_insert_node(t_stack **head, int data);
t_stack	*clst_load(char **av, int ac);

#endif
