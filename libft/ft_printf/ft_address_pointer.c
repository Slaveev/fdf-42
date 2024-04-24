/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:47:59 by dslaveev          #+#    #+#             */
/*   Updated: 2024/03/14 10:17:59 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_add(unsigned long n)
{
	int				add;
	const char		*base;

	base = "0123456789abcdef";
	add = 0;
	if (n > 15)
		add += convert_add(n / 16);
	if (add < 0)
		return (-1);
	add += ft_putchar(*(base + (n % 16)));
	if (add < 0)
		return (-1);
	return (add);
}

int	ft_address_pointer(void	*format)
{
	unsigned long	n;
	int				length;

	length = 0;
	n = (unsigned long)format;
	length += ft_putstr("0x");
	if (length < 0)
		return (-1);
	length += convert_add(n);
	if (length < 0)
		return (-1);
	return (length);
}
