/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:45 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/11 17:14:09 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **array, int ac)
{
	int		i;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = array[i];
		if (str == NULL)
			return (-1);
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (*str == '\0')
			return (-1);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (-1);
			str++;
		}
		i++;
	}
	return (0);
}
