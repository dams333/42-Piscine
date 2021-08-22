/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:42:34 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/18 09:32:52 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	shift(char	*tab, int size, int amount)
{
	int	i;

	i = 0;
	while (i + amount < size)
	{
		tab[i] = tab[i + amount];
		i++;
	}
}

void	push(char *tab, int size_tab, char *new_elems, int size_new_elems)
{
	int	i;
	int	j;

	shift(tab, size_tab, size_new_elems);
	i = size_tab - size_new_elems;
	j = 0;
	while (i < size_tab)
	{
		tab[i] = new_elems[j];
		++i;
		++j;
	}
}
