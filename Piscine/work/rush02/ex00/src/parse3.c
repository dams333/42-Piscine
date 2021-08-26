/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:40:18 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 15:49:35 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	add_to_stock(t_read_infos *infos, int start, int readed, int i)
{
	infos->current_stock = readed - start;
	infos->stock = malloc(sizeof(*(infos->stock)) * infos->current_stock);
	i = start;
	while (i < readed)
	{
		infos->stock[i - start] = infos->buffer[i];
		i++;
	}
}

t_stock	*end_read(int fd, t_read_infos infos)
{
	t_stock	empty;

	close(fd);
	infos.struct_tab = ft_realloc(infos.struct_tab, infos.stocked_struct, 1);
	empty.nbr = "";
	infos.struct_tab[infos.stocked_struct] = empty;
	free(infos.stock);
	return (infos.struct_tab);
}

t_read_infos	init_struct(void)
{
	t_read_infos	infos;

	infos.current_stock = 0;
	infos.struct_tab = 0;
	infos.stock = 0;
	infos.stocked_struct = 0;
	infos.start = 0;
	return (infos);
}

void	skip_whitespace(int *i, int readed, t_read_infos infos)
{
	while (is_whitespace(infos.buffer[*i]) && *i < readed)
		*i = *i + 1;
}

t_stock	*read_file(int fd)
{
	t_read_infos	infos;
	int				readed;
	int				i;

	infos = init_struct();
	readed = read(fd, infos.buffer, BUFFER_SIZE);
	while (readed > 0)
	{
		i = -1;
		infos.start = 0;
		while (++i < readed)
		{
			if (infos.buffer[i] == '\n')
			{
				if (!create_struct(&infos, infos.start, i, fd))
					return (0);
				skip_whitespace(&i, readed, infos);
				infos.start = i;
			}
		}
		if (infos.start < readed)
			add_to_stock(&infos, infos.start, readed, i);
		readed = read(fd, infos.buffer, BUFFER_SIZE);
	}
	return (end_read(fd, infos));
}
