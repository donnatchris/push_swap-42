/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:20:47 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/11 17:26:20 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

int	check_input(char **array, int ac);
long	ft_atoi_long(const char *nptr);

#endif
