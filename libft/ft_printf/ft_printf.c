/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:05:57 by dslaveev          #+#    #+#             */
/*   Updated: 2024/03/14 12:52:56 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(va_list args, char c)
{
	void	*ptr;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, long)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_puthexa_num(va_arg(args, unsigned int), c));
	else if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			return (ft_putstr("0x0"));
		return (ft_address_pointer(ptr));
	}
	else if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		x;

	i = 0;
	count = 0;
	va_start(args, str);
	while (*(str + i))
	{
		x = count;
		if (*(str + i) == '%' && ft_strchr("cspdiuxX%", *(str + i + 1)))
		{
			count += check_format(args, *(str + i + 1));
			i++;
		}
		else
			count += ft_putchar(*(str + i));
		if (x > count)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}

// int main(void)
// {
// 	printf(" %%\n");
// 	ft_printf(" %%\n1");
// 	return (0);
// }
