/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:50:23 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 17:40:05 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	tr_offset_to_hex(int offset, char *code, int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (offset >= 16)
		tr_offset_to_hex(offset / 16, code, i - 1);
	code[i] = base[offset % 16];
}

void	print_has_hexa(int nbr)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[nbr / 16]);
	ft_putchar(base[nbr % 16]);
}

void	print_chars(char *buffer)
{
	int	i;

	write(1, "  |", 3);
	i = -1;
	while (++i < 16)
	{
		if (buffer[i] >= ' ' && buffer[i] <= '~')
			write(1, &buffer[i], 1);
		else
			write(1, ".", 1);
	}
	write(1, "|", 1);
}

void	print_complete(char *buffer, int option, int offset)
{
	char	code[9];
	int		i;

	i = -1;
	while (++i < 8)
		code[i] = '0';
	tr_offset_to_hex(offset, code, 7);
	ft_putstr(code);
	write(1, " ", 1);
	if (option)
		write(1, " ", 1);
	i = -1;
	while (++i < 16)
	{
		print_has_hexa((unsigned char) buffer[i]);
		if (i != 15)
			write(1, " ", 1);
		if (option && i == 7)
			write(1, " ", 1);
	}
	if (option)
		print_chars(buffer);
	write(1, "\n", 1);
}

void	print_some_chars(char *buffer, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (buffer[i] >= ' ' && buffer[i] <= '~')
			write(1, &buffer[i], 1);
		else
			write(1, ".", 1);
	}
	write(1, "|", 1);
}
