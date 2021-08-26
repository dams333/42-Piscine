/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:20:29 by jmaia             #+#    #+#             */
/*   Updated: 2021/08/24 18:57:22 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdlib.h>
# include "files.h"
# include "map.h"
# include "ft.h"
# include "dynamic_buffer.h"
# include "elements.h"
int	parse_first_line(t_file *file, t_elements *elements, int *n_line);
int	parse(t_file *file, t_elements *elements, t_map *map);
int	parse_map(t_file *file, t_elements *elements, t_map *map);
int	parse_line(t_map *map, int i_line, t_dynamic_buffer *line,
		t_elements *elements);
int	get_associated_number(t_elements *elements, char element);
int	parse_map(t_file *file, t_elements *elements, t_map *map);
#endif
