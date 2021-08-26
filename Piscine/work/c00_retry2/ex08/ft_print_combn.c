/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:04:20 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/11 15:03:21 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb_from_table(int tab[], int size)
{
	char	print;
	int		i;
	int		n;

	i = 0;
	while (i < size)
	{
		n = tab[i];
		print = n + '0';
		write(1, &print, 1);
		i++;
	}
}

int	add_to_digit(int tab[], int digit, int size)
{
	int	current;
	int	max;
	int	prev;

	current = tab[digit];
	max = 9 - (size - 1 - digit);
	current++;
	if (current <= max)
	{
		tab[digit] = current;
		return (current);
	}
	else
	{
		prev = add_to_digit(tab, digit - 1, size);
		current = prev + 1;
		tab[digit] = current;
		return (current);
	}
}

int	is_all_max(int tab[], int size)
{
	int	i;
	int	all_max;
	int	max;

	i = 0;
	all_max = 1;
	while (i < size)
	{
		 max = 9 - (size - 1 - i);
		if (tab[i] != max)
		{
			all_max = 0;
		}
		i++;
	}
	return (all_max);
}

void	ft_print_combn(int n)
{
	int	stock[10];
	int	i;

	i = 0;
	while (i < n)
	{
		stock[i] = i;
		i++;
	}
	print_comb_from_table(stock, n);
	write(1, ", ", 2);
	while (is_all_max(stock, n) == 0)
	{
		add_to_digit(stock, n - 1, n);
		print_comb_from_table(stock, n);
		if (is_all_max(stock, n) == 0)
		{
			write(1, ", ", 2);
		}
	}
}
