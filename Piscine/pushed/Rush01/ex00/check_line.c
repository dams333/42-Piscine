/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:47:36 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/15 11:08:57 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_line_left(int board[6][6], int y)
{
	int	max;
	int	view;
	int	x;

	max = 0;
	view = 0;
	x = 1;
	while (x <= 4)
	{
		if (board[x][y] > max)
		{
			max = board[x][y];
			view++;
		}
		if (board[x][y] == 0)
			return (-1);
		x++;
	}
	if (board[0][y] != view)
		return (0);
	return (1);
}

int	check_line_right(int board[6][6], int y)
{
	int	max;
	int	view;
	int	x;

	max = 0;
	view = 0;
	x = 4;
	while (x >= 1)
	{
		if (board[x][y] > max)
		{
			max = board[x][y];
			view++;
		}
		if (board[x][y] == 0)
			return (-1);
		x--;
	}
	if (board[5][y] != view)
		return (0);
	return (1);
}

int	check_line(int board[6][6], int y)
{
	if (check_line_left(board, y) && check_line_right(board, y))
		return (1);
	return (0);
}
