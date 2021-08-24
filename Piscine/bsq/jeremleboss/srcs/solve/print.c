/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:13:00 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 22:59:51 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

void	print_symbol(int i, t_elements elements)
{
	if (i == 0)
		write(1, &(elements.empty), 1);
	if (i == 1)
		write(1, &(elements.obstacle), 1);
	if (i == 2)
		write(1, &(elements.full), 1);
}

void	print_map_with_symbols(t_map map, t_elements elements)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.line_count)
	{
		j = -1;
		while (++j < map.line_length)
			print_symbol(get_element_in_map(i, j, map), elements);
		write(1, "\n", 1);
	}
}
