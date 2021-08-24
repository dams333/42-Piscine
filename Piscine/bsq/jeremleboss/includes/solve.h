/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:50:51 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 21:46:49 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <stdio.h>
# include <stdlib.h>
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

int		get_element_in_map(int line, int column, t_map map);
void	set_element(int line, int column, int i, t_map *map);
t_map	*map_copy(t_map map, int modificator);
void	solve(t_map *map);
void	replace_in_original(t_map *map, int i_bigger, int j_bigger, int bigger);
void	print_map_with_symbols(t_map map, t_elements elements);

#endif
