/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:20:21 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/05 15:52:31 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	min_of_int_tab_from(int *tab, int size, int n)
{
	int	min;
	int	i;

	min = *(tab + n);
	i = n;
	while (i < size)
	{
		if (*(tab + i) < min)
		{
			min = *(tab + i);
		}
		i++;
	}
	return (min);
}

int	index_of_element_from(int *tab, int e, int size, int n)
{
	int	i;

	i = n;
	while (i < size)
	{
		if (*(tab + i) == e)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	while (i < size)
	{
		min = min_of_int_tab_from(tab, size, i);
		index = index_of_element_from(tab, min, size, i);
		*(tab + index) = *(tab + i);
		*(tab + i) = min;
		i++;
	}
}
