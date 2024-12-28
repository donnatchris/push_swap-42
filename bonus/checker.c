/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:34:05 by christophed       #+#    #+#             */
/*   Updated: 2024/12/28 11:06:16 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

// Function to choose which instruction to execute
// when the instruction is 3 characters long
// Returns 0 if the instruction is executed, -1 if the instruction is not found
int	instruction_4(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		quiet_rra(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		quiet_rrb(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		quiet_rrr(a, b);
	else
		return (-1);
	return (0);
}

// Function to choose which instruction to execute
// when the instruction is 2 characters long
// Returns 0 if the instruction is executed, -1 if the instruction is not found
int	instruction_3(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 2) == 0)
		quiet_sa(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		quiet_sb(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		quiet_ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		quiet_pa(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		quiet_pb(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		quiet_ra(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		quiet_rb(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		quiet_rr(a, b);
	else
		return (-1);
	return (0);
}

// Function to check the instruction is valid
// Returns 0 if the instruction is valid, -1 if not
int	instruction(t_stack **a, t_stack **b, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len != 3 && len != 4)
		return (0);
	if (len == 3)
	{
		if (instruction_3(a, b, line) < 0)
			return (-1);
	}
	else
	{
		if (instruction_4(a, b, line) < 0)
			return (-1);
	}
	return (0);
}

// Function to test the instructions to sort the stack a
int	checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (instruction(a, b, line) < 0)
			return (free(line), -1);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (0);
}
