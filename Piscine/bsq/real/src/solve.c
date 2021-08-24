/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:31:22 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 12:54:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int	get_min(int a, int b, int c)
{
	if(a <= b && a <= c)
		return a;
	if(b <= a && b <= c)
		return b;
	if(c <= a && c <= b)
		return c;
	return -1;
}

void	set_case(t_map *map, int i, int j)
{
	int	left;
	int	diag;
	int	top;
	int	min;

	left = get_element(i, j - 1, map);
	diag = get_element(i - 1, j - 1, map);
	top = get_element(i - 1, j, map);
	min = get_min(left, diag, top);
	set_element(i, j, min + 1, map)
}

void	set_all_squares(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(i < map->line_count)
	{
		j = 0;
		while(j < map->line_length)
		{
			if(get_elements(i, j, *map) == -1)
			{
				if(i == 0 || j == 0)
					set_element(i, j, 1, *map);
				else
					set_case(map, i, j);
			}
			j++;
		}
		i++;
	}
}

void	solve(t_map map)
{
	t_map *copy = map_copy(map, -1);
	print_map(*copy);
}
