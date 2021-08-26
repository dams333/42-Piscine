/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:00:17 by jmaia             #+#    #+#             */
/*   Updated: 2021/08/25 10:42:18 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_things(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int	parse_map(t_file *file, t_elements *elements, t_map *map)
{
	int					line_count;
	int					tmp_length_line;
	t_char_file			c;
	t_dynamic_buffer	line;
	int					has_error;

	init_things(&line_count, &has_error, &tmp_length_line);
	line = init_buffer();
	while (!is_end_reached(file) && !has_error)
	{
		c = get_next_char(file);
		if (c.c == '\n' && !c.is_end)
		{
			if (map->map == 0)
				map->map = malloc(sizeof(*map->map) * line.i * map->line_count);
			has_error = parse_line(map, line_count, &line, elements);
			line.i = 0;
			line_count++;
		}
		else
			append(&line, c.c);
	}
	if (line_count != map->line_count || line_count == 0)
		has_error = 1;
	return (has_error);
}

int	get_associated_number(t_elements *elements, char element)
{
	if (element == elements->empty)
		return (0);
	else if (element == elements->obstacle)
		return (1);
	else if (element == elements->full)
		return (2);
	else
		return (-1);
}

int	parse_line(t_map *map, int i_line, t_dynamic_buffer *line,
		t_elements *elements)
{
	int	i;

	if (map->line_length == -1)
		map->line_length = line->i;
	if (map->line_length != line->i)
		return (1);
	i = 0;
	while (i < line->i)
	{
		if (!is_good_element(line->buf[i], elements))
			return (1);
		map->map[i_line * map->line_length + i]
			= get_associated_number(elements, line->buf[i]);
		i++;
	}
	return (0);
}
