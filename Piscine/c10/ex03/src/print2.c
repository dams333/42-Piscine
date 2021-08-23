/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:37:34 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/23 20:34:12 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_without(t_files_infos *fi, char *b1, int readed)
{
	int	i;
	int	space_to_print;

	i = -1;
	fi->offset += readed;
	while (++i < readed)
	{
		print_has_hexa(b1[i]);
		if (i != readed - 1)
			write(1, " ", 1);
	}
	space_to_print = 47 - (readed * 2 + (readed - 1));
	i = -1;
	while (++i < space_to_print)
		write(1, " ", 1);
}

void	print_with(t_files_infos *fi, char *b1, int readed)
{
	int	i;
	int	need;

	write(1, " ", 1);
	i = -1;
	fi->offset += readed;
	while (++i < readed)
	{
		print_has_hexa(b1[i]);
		if (i != readed - 1)
			write(1, " ", 1);
		if (i == 7 && i < (readed - 1))
			write(1, " ", 1);
	}
	need = 16 - readed;
	need *= 3;
	if (readed < 9)
		need++;
	need += 2;
	i = -1;
	while (++i < need)
		write(1, " ", 1);
	write(1, "|", 1);
	print_some_chars(b1, readed);
}

void	print_not_complete(char *b1, char *b2, t_files_infos fi, int b1_readed)
{
	char	code[9];
	int		i;
	int		readed;

	i = -1;
	while (++i < 8)
		code[i] = '0';
	tr_offset_to_hex(fi.offset, code, 7);
	ft_putstr(code);
	write(1, " ", 1);
	i = -1;
	while (b2[++i])
		b1[b1_readed + i] = b2[i];
	readed = b1_readed + i;
	if (!fi.option)
		print_without(&fi, b1, readed);
	else
		print_with(&fi, b1, readed);
	write(1, "\n", 1);
}

void	print_offset(int	offset, char *buffer)
{
	char	code[9];
	int		i;

	if (buffer[0] != '\0')
	{
		i = -1;
		while (++i < 8)
			code[i] = '0';
		tr_offset_to_hex(offset, code, 7);
		ft_putstr(code);
		write(1, "\n", 1);
	}
}
