/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:14:57 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 12:43:24 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

void	print_map(t_map map);

int	main()
{
	int	line_length = 5;
	int line_count = 5;

	int *map = malloc(sizeof(*map) * 25);
	map[0] = 0;
	map[1] = 0;
	map[2] = 0;
	map[3] = 0;
	map[4] = 0;

	map[5] = 0;
	map[6] = 0;
	map[7] = 0;
	map[8] = 0;
	map[9] = 1;

	map[10] = 0;
	map[11] = 0;
	map[12] = 0;
	map[13] = 0;
	map[14] = 0;

	map[15] = 0;
	map[16] = 1;
	map[17] = 1;
	map[18] = 0;
	map[19] = 0;

	map[20] = 0;
	map[21] = 0;
	map[22] = 0;
	map[23] = 0;
	map[24] = 0;

	t_map map_struct;
	map_struct.map = map;
	map_struct.line_length = line_length;
	map_struct.line_count = line_count;

	print_map(map_struct);
	solve(map_struct);
}

void	print_map(t_map map)
{
	int	i;
	int	j;
	
	i = 0;
	while(i < map.line_count)
	{
		j = 0;
		while(j < map.line_length)
		{
			printf("%i ", get_element(i, j, map));
			j++;
		}
		printf("\n");
		i++;
	}
}


