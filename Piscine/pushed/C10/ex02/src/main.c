/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:31:19 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/23 20:18:27 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	require_argument_error(void)
{
	write(2, g_program_name, ft_strlen(g_program_name));
	write(2, ": option requires an argument -- c\n", 35);
	write(2, "usage: tail [-F | -f | -r] [-q] ", 32);
	write(2, "[-b # | -c # | -n #] [file ...]\n", 33);
}

void	illegal_offset_error(char *offset)
{
	write(2, g_program_name, ft_strlen(g_program_name));
	write(2, ": illegal offset -- ", 20);
	write(2, offset, ft_strlen(offset));
	write(2, "\n", 1);
}

int	parse_separate(int argc, char **argv)
{
	if (argc <= 2)
	{
		require_argument_error();
		return (1);
	}
	if (!is_nbr(argv[2]))
	{
		illegal_offset_error(argv[2]);
		return (1);
	}
	if (argc == 3)
		return (read_last_standard_input(ft_atoi(argv[2])));
	return (read_last_all_files(ft_atoi(argv[2]), argc, 3, argv));
}

int	main(int argc, char **argv)
{
	g_program_name = basename(argv[0]);
	if (ft_strlen(argv[1]) == 2)
		return (parse_separate(argc, argv));
	else
	{
		if (!is_nbr(argv[1] + 2))
		{
			illegal_offset_error(argv[1] + 2);
			return (1);
		}
		if (argc == 2)
			return (read_last_standard_input(ft_atoi(argv[1] + 2)));
		return (read_last_all_files(ft_atoi(argv[1] + 2), argc, 2, argv));
	}
}
