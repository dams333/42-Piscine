/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:13:00 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/25 23:11:49 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "dynamic_buffer.h"

void	print_symbol(int i, t_elements elements)
{
	if (i == 0)
		write(1, &(elements.empty), 1);
	if (i == 1)
		write(1, &(elements.obstacle), 1);
	if (i == 2)
		write(1, &(elements.full), 1);
}

char	get_element2(int	i, t_elements elements)
{
	if (i == 0)
		return (elements.empty);
	if (i == 1)
		return (elements.obstacle);
	if (i == 2)
		return (elements.full);
	return (-1);
}

void	print_map_with_symbols(t_map map, t_elements elements)
{
	int					i;
	int					j;
	int					k;
	t_dynamic_buffer	buf;

	buf = init_buffer();
	i = -1;
	while (++i < map.line_count)
	{
		buf.i = 0;
		j = -1;
		while (++j < map.line_length)
			append(&buf, get_element2(get_element_in_map(i, j, map), elements));
		k = 0;
		write(1, buf.buf, buf.i);
		write(1, "\n", 1);
	}
}
