/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:58:02 by dslaveev          #+#    #+#             */
/*   Updated: 2024/03/14 12:51:10 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;
	int	reversing;

	reversing = 1;
	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		count++;
		n = -n;
	}
	while (reversing <= n / 10)
		reversing = reversing * 10;
	while (reversing > 0)
	{
		if (ft_putchar(n / reversing + '0') < 0)
			return (-1);
		count++;
		n = n % reversing;
		reversing = reversing / 10;
	}
	return (count);
}

// int	ft_putnbr(int n)
// {
// 	int	count;

// 	count = 0;
// 	if (n == -2147483648)
// 		count += write(1, "-2147483648", 11);
// 	else if (n < 0)
// 	{
// 		count += ft_putchar('-');
// 		n = -n;
// 		count += ft_putnbr(n);
// 	}
// 	else
// 	{
// 		if (n > 9)
// 		{
// 			count += ft_putnbr(n / 10);
// 			count += ft_putnbr(n % 10);
// 		}
// 		else
// 			count += ft_putchar(n + '0');
// 	}
// 	if (count < 0)
// 		return (-1);
// 	return (count);
// }

// int main(void)
// {
// 	printf("%d\n", printf("%d\n", 10));
// 	printf("%d\n", ft_printf("%d\n", 10));
// 	return (0);
// }
