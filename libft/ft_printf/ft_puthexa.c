/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:30:27 by dslaveev          #+#    #+#             */
/*   Updated: 2024/03/14 10:20:18 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_puthexa_num(unsigned long n, char c)
// {
// 	int	nmhex;

// 	if (n == 0)
// 	{
// 		ft_putchar('0');
// 		return ;
// 	}
// 	nmhex = n % 16;
// 	ft_puthexa_num(n / 16, c);
// 	if (nmhex >= 10)
// 		ft_putchar(c + (nmhex - 10));
// 	else
// 		ft_putnbr('0' + nmhex);
// }

int	ft_puthexa_num(unsigned long n, char c)
{
	char	*hex_dig;
	int		count;

	count = 0;
	if (c == 'x')
		hex_dig = "0123456789abcdef";
	else
		hex_dig = "0123456789ABCDEF";
	if (n / 16 != 0)
		count += ft_puthexa_num(n / 16, c);
	if (count < 0)
		return (-1);
	count += ft_putchar(hex_dig[n % 16]);
	if (count < 0)
		return (-1);
	return (count);
}

// void	reverse_hexa(char str)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	while (i > 0)
// 	{
// 		ft_putchar(str[i]);
// 		i--;
// 	}
// }

// int main(void)
// {
// 	printf("%x\n", -10);
// 	ft_printf("%x\n", -10);
// 	return 0;
// }
