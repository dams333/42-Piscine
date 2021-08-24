/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:50:51 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/24 12:54:24 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

#include <stdio.h>
#include <stdlib.h>

// line_length = taille d une ligne
// line_count = nombre de ligne
typedef struct s_map
{
   int  *map;
   int  line_length;
   int  line_count;
}  t_map;

typedef struct s_elements
{
    char  empty;
    char  obstacle;
    char  full;
}  t_elements;

int	get_element(int line, int column, t_map map);
void	print_map(t_map map);
void	set_element(int line, int column, int i, t_map *map);
t_map	*map_copy(t_map map, int modificator);
void	solve(t_map map);

#endif
