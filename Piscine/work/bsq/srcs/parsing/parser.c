/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:18:06 by jmaia             #+#    #+#             */
/*   Updated: 2021/08/25 12:07:30 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_element(char *buf, int i, char *element)
{
	if (i >= 0 && ft_is_printable(buf[i]))
		*element = buf[i];
	else
		return (1);
	return (0);
}

int	get_elements(t_dynamic_buffer line, t_elements *elements)
{
	int	i;
	int	has_error;

	i = line.i - 1;
	has_error = 0;
	has_error = has_error || get_element(line.buf, i--, &elements->full);
	has_error = has_error || get_element(line.buf, i--, &elements->obstacle);
	has_error = has_error || get_element(line.buf, i--, &elements->empty);
	if (elements->full == elements->obstacle
		|| elements->full == elements->empty
		|| elements->obstacle == elements->empty)
		has_error = 1;
	return (has_error);
}

int	parse_first_line(t_file *file, t_elements *elements, int *n_line)
{
	t_dynamic_buffer	buf;
	t_char_file			c;
	int					has_error;

	has_error = 1;
	buf = init_buffer();
	c.c = 0;
	while (!is_end_reached(file) && c.c != '\n')
	{
		c = get_next_char(file);
		if (c.c == '\n')
		{
			has_error = get_elements(buf, elements);
			break ;
		}
		append(&buf, c.c);
	}
	*n_line = ft_mini_atoi(buf.buf, buf.i - 3);
	free(buf.buf);
	if (*n_line == -1 || *n_line == 0)
		return (1);
	return (has_error);
}

int	parse(t_file *file, t_elements *elements, t_map *map)
{
	int	has_error;
	int	i;
	int	empty_found;

	map->map = 0;
	map->line_length = -1;
	has_error = parse_first_line(file, elements, &map->line_count);
	if (has_error)
		return (has_error);
	has_error = parse_map(file, elements, map);
	i = 0;
	empty_found = 0;
	while (i < map->line_length * map->line_count && !empty_found)
	{
		if (map->map[i++] == 0)
			empty_found = 1;
	}
	if (!empty_found && !has_error)
		return (2);
	return (has_error);
}
