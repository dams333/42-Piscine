/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:35:00 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 15:52:27 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_stock	*parse_dictionnary(char *file, int check)
{
	int		fd;
	t_stock	*parsed;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		parsed = read_file(fd);
		if (!check || check_validate(parsed))
			return (parsed);
	}
	return (0);
}

t_stock	*ft_realloc(t_stock *stock, int current, int increment)
{
	t_stock	*tmp;
	int		i;

	tmp = malloc(sizeof(*tmp) * (current + increment));
	i = -1;
	while (++i < current)
		tmp[i] = stock[i];
	free(stock);
	return (tmp);
}

void	free_tab(t_stock *tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i].nbr);
		free(tab[i].write);
		i++;
	}
	free(tab);
}

int	clear(int fd, t_read_infos *i)
{
	close(fd);
	free_tab(i->struct_tab, i->stocked_struct);
	return (0);
}

int	create_struct(t_read_infos *i, int start, int stop, int fd)
{
	t_stock	*tmp;

	if (i->current_stock == 0)
	{
		tmp = create_complete(i->buffer, start, stop);
		if (!tmp)
			return (clear(fd, i));
		i->struct_tab = ft_realloc(i->struct_tab, i->stocked_struct, 1);
		(i->struct_tab)[i->stocked_struct] = *tmp;
		free(tmp);
	}
	else
	{
		tmp = create_multiple(i, start, stop);
		if (!tmp)
			return (clear(fd, i));
		i->struct_tab = ft_realloc(i->struct_tab, i->stocked_struct, 1);
		(i->struct_tab)[i->stocked_struct] = *tmp;
		free(i->stock);
		i->stock = 0;
		i->current_stock = 0;
		free(tmp);
	}
	i->stocked_struct++;
	return (1);
}
