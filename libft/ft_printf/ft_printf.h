/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:01:47 by dslaveev          #+#    #+#             */
/*   Updated: 2024/04/05 15:23:29 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
size_t	ft_strlen(char const *str);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_address_pointer(void	*format);
char	*ft_strchr(const char *str, int character);
int		ft_unsigned(unsigned long n);
int		ft_puthexa_num(unsigned long n, char c);

#endif
