/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:49:29 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/10 12:36:53 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_safe(int *board, int x, int y)
{
	int	i;
	int	d;

	i = 0;
	while (i < x)
	{
		if (board[i] == y)
			return (0);
		d = x - i;
		if (board[i] + d == y)
			return (0);
		if (board[i] - d == y)
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	queen_puzzle(int *board, int queens, int solutions)
{
	int	i;

	if (queens == 10)
	{
		solutions++;
		print_solution(board);
		return (solutions);
	}
	i = 0;
	while (i < 10)
	{
		if (is_safe(board, queens, i))
		{
			board[queens] = i;
			solutions = queen_puzzle(board, queens + 1, solutions);
			board[queens] = -1;
		}
		i++;
	}
	return (solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		board[i] = -1;
		i++;
	}
	return (queen_puzzle(board, 0, 0));
}
