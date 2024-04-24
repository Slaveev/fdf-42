/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:30:55 by dslaveev          #+#    #+#             */
/*   Updated: 2024/03/14 10:31:12 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	words;

	if (!s)
		return (write(1, "(null)", 6));
	words = write(1, s, ft_strlen(s));
	if (words < 0)
		return (-1);
	return (words);
}
