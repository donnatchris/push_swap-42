/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_address_pf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:14:01 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/16 18:17:38 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_put_mem_address_pf(uintptr_t address, int *count)
{
	char	*str;

	str = "0123456789abcdef";
	if (address > 15)
		ft_put_mem_address_pf(address / 16, count);
	ft_putchar_pf(str[address % 16], count);
}

void	ft_check_address_pf(void *address, int *count)
{
	if (address == NULL)
		ft_putstr_pf("(nil)", count);
	else
	{
		ft_putstr_pf("0x", count);
		ft_put_mem_address_pf((uintptr_t) address, count);
	}
}
