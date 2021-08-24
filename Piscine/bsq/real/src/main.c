/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:30:54 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 15:37:04 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	parse_and_solve(t_file file)
{
	int	result;
	t_elements	*el;
	t_map		*map;

	result = parse(file, el, map);
	if(result == 1)
		write(2, "map error\n", 10);
	if(result == 2)
		print_map_with_symbols(*map, *el);
	if(result == 3)
	{
		solve(map);
		print_map_with_symbols(*map, *el)
	}
}

int	main(int argc, char **argv)
{
	int		result;
	int		i;
	t_file	file;

	if(argc == 1)
	{
		file = open_file("/");
		if(file.end != 0)
			parse_and_solve(file);
		else
			write(2, "map error\n", 10);
	}
	else
	{
		i = 0;
		while(++i < argc)
		{
			file = open_file(argv[i]);
			if(file.end != 0)
				parse_and_solve(file);
			else
				write(2, "map error\n", 10);
		}
	}
}
