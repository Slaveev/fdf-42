/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:15:44 by dslaveev          #+#    #+#             */
/*   Updated: 2024/03/16 11:24:07 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned long n)
{
	char	*base;
	int		length;

	base = "0123456789";
	length = 0;
	if (n > 9)
		length += (ft_unsigned(n / 10));
	if (length < 0)
		return (-1);
	length += ft_putchar(*(base + (n % 10)));
	if (length < 0)
		return (-1);
	return (length);
}

// int main(void)
// {
// 	int	i = 123;
// 	printf("%u", ft_unsigned(i));
// 	return (0);
// }
