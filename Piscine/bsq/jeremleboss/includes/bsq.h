/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:31:13 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 21:46:07 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define SIZE_BUF 50

# include <unistd.h>

typedef struct s_map
{
	int	*map;
	int	line_length;
	int	line_count;
}	t_map;

typedef struct s_elements
{
	char	empty;
	char	obstacle;
	char	full;
}	t_elements;

typedef struct s_file
{
	int		fd;
	int		i;
	int		end;
	char	buf[SIZE_BUF];
}	t_file;

void	solve(t_map *map);
void	print_map_with_symbols(t_map map, t_elements elements);
int		parse(t_file *file, t_elements *elements, t_map *map);
t_file	open_file(char *path);
int		close_file(t_file file);

#endif
