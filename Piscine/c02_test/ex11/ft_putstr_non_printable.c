/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:28:47 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/15 11:49:45 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_char_as_hex(unsigned char c)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	ft_putchar(92);
	ft_putchar(hex_base[c / 16]);
	ft_putchar(hex_base[c % 16]);
}

int	check(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (check(str[i]))
			ft_putchar(str[i]);
		else
			print_char_as_hex(str[i]);
	}
}
