/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:51:50 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 21:53:04 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int	get_element_in_map(int line, int column, t_map map)
{
	int	index;

	index = (line * map.line_length);
	index += column;
	return (map.map[index]);
}

void	set_element(int line, int column, int i, t_map *map)
{
	int	index;

	index = (line * (map->line_length));
	index += column;
	(map->map)[index] = i;
}

t_map	*map_copy(t_map map, int modificator)
{
	int		i;
	int		elements_count;
	t_map	*dup;

	elements_count = map.line_length * map.line_count;
	dup = malloc(sizeof(*dup));
	dup->line_length = map.line_length;
	dup->line_count = map.line_count;
	dup->map = malloc(sizeof(int) * elements_count);
	i = 0;
	while (i < elements_count)
	{
		(dup->map)[i] = (map.map)[i] + modificator;
		i++;
	}
	return (dup);
}

void	replace_in_original(t_map *map, int i_bigger, int j_bigger, int bigger)
{
	int	i;
	int	j;

	i = -1;
	while (++i < bigger)
	{
		j = -1;
		while (++j < bigger)
		{
			set_element(i_bigger - i, j_bigger - j, 2, map);
		}
	}
}
