/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:11:25 by chdonnat          #+#    #+#             */
/*   Updated: 2024/12/16 18:17:55 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putuint_pf(unsigned int n, int *count)
{
	if (n > 9)
		ft_putuint_pf(n / 10, count);
	ft_putchar_pf((n % 10) + 48, count);
}
