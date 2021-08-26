/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:33:49 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 15:50:13 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	count_letter(char *str, int length)
{
	int	i;

	i = 0;
	while (i < length && str[i] != ':')
		i++;
	if (i == length)
		return (0);
	i++;
	while (i < length && is_whitespace(str[i]))
		i++;
	return (length - i);
}

void	fill_number_tab(char *tab, char *str, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (is_whitespace(str[i]) || str[i] == ':')
			return ;
		tab[i] = str[i];
		i++;
	}
}

void	fill_letter_tab(char *tab, char *str, int length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < length && str[i] != ':')
		i++;
	i++;
	while (i < length && is_whitespace(str[i]))
		i++;
	while (i < length)
	{
		tab[j] = str[i];
		i++;
		j++;
	}
}

t_stock	*create_complete(char *str, int start, int stop)
{
	t_stock	*stock;
	int		number;
	int		letter;
	char	*nbr_tab;
	char	*write_tab;

	number = count_number(str + start, stop - start);
	letter = count_letter(str + start, stop - start);
	if (number == 0 || letter == 0)
		return (0);
	nbr_tab = malloc(sizeof(*nbr_tab) * (number + 1));
	write_tab = malloc(sizeof(*write_tab) * (letter + 1));
	if (!nbr_tab || !write_tab)
		return (0);
	nbr_tab[number] = 0;
	write_tab[letter] = 0;
	fill_number_tab(nbr_tab, str + start, stop - start);
	fill_letter_tab(write_tab, str + start, stop - start);
	stock = malloc(sizeof(*stock));
	stock->nbr = nbr_tab;
	stock->write = write_tab;
	return (stock);
}

t_stock	*create_multiple(t_read_infos *infos, int start, int stop)
{
	int		length;
	char	*buffer;
	int		j;
	int		i;
	t_stock	*tmp;

	length = (infos->current_stock) + (stop - start);
	buffer = malloc(sizeof(*buffer) * length);
	if (!buffer)
		return (0);
	j = -1;
	while (++j < (infos->current_stock))
		buffer[j] = (infos->stock[j]);
	i = start - 1;
	while (++i < stop)
		buffer[i - start + j] = (infos->buffer[i]);
	tmp = create_complete(buffer, 0, length);
	free(buffer);
	return (tmp);
}
