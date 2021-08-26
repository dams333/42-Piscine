/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:23:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/08/24 19:38:37 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
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
#endif
