/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:31:22 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 21:53:03 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int	get_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	if (c <= a && c <= b)
		return (c);
	return (-1);
}

void	set_case(t_map *map, int i, int j)
{
	int	left;
	int	diag;
	int	top;
	int	min;

	left = get_element_in_map(i, j - 1, *map);
	diag = get_element_in_map(i - 1, j - 1, *map);
	top = get_element_in_map(i - 1, j, *map);
	min = get_min(left, diag, top);
	set_element(i, j, min + 1, map);
}

void	set_all_squares(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line_count)
	{
		j = 0;
		while (j < map->line_length)
		{
			if (get_element_in_map(i, j, *map) == -1)
			{
				if (i == 0 || j == 0)
					set_element(i, j, 1, map);
				else
					set_case(map, i, j);
			}
			j++;
		}
		i++;
	}
}

void	search_bigger(t_map *map, t_map *solve)
{
	int	i_bigger;
	int	j_bigger;
	int	bigger;
	int	i;
	int	j;

	i_bigger = 0;
	j_bigger = 0;
	bigger = get_element_in_map(0, 0, *solve);
	i = -1;
	while (++i < solve->line_count)
	{
		j = -1;
		while (++j < solve->line_length)
		{
			if (get_element_in_map(i, j, *solve) > bigger)
			{
				bigger = get_element_in_map(i, j, *solve);
				i_bigger = i;
				j_bigger = j;
			}
		}
	}
	replace_in_original(map, i_bigger, j_bigger, bigger);
}

void	solve(t_map *map)
{
	t_map	*copy;

	copy = map_copy(*map, -1);
	set_all_squares(copy);
	search_bigger(map, copy);
}
