/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:51:05 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:17 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*actual_lst;

	if (lst == NULL)
		return (NULL);
	actual_lst = lst;
	while (actual_lst->next != NULL)
		actual_lst = actual_lst->next;
	return (actual_lst);
}
