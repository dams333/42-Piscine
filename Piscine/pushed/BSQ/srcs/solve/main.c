/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:30:54 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/25 22:25:00 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map_error(int i, int max)
{
	write(2, "map error\n", 10);
	if (i < (max - 1))
		write(1, "\n", 1);
}

void	parse_and_solve(t_file file, int i, int max)
{
	int			result;
	t_elements	el;
	t_map		map;

	result = parse(&file, &el, &map);
	if (result == 1)
		print_map_error(i, max);
	if (result == 2)
	{
		print_map_with_symbols(map, el);
		if (i < (max - 1))
			write(1, "\n", 1);
	}
	if (result == 0)
	{
		solve(&map);
		print_map_with_symbols(map, el);
		if (i < (max - 1))
			write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_file	file;

	if (argc == 1)
	{
		file = open_file("/");
		if (file.end != 0)
			parse_and_solve(file, 1, 2);
		else
			write(2, "map error\n", 10);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			file = open_file(argv[i]);
			if (file.end != 0)
				parse_and_solve(file, i, argc);
			else
				print_map_error(i, argc);
		}
	}
}
