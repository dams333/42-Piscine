/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:57:49 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/15 09:00:08 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int board[6][6], int x)
{
	int	max;
	int	view;
	int	y;

	max = 0;
	view = 0;
	y = 1;
	while (y <= 4)
	{
		if (board[x][y] > max)
		{
			max = board[x][y];
			view++;
		}
		if (board[x][y] == 0)
			return (-1);
		y++;
	}
	if (board[x][0] != view)
		return (0);
	return (1);
}

int	check_col_down(int board[6][6], int x)
{
	int	max;
	int	view;
	int	y;

	max = 0;
	view = 0;
	y = 4;
	while (y >= 1)
	{
		if (board[x][y] > max)
		{
			max = board[x][y];
			view++;
		}
		if (board[x][y] == 0)
			return (-1);
		y--;
	}
	if (board[x][5] != view)
		return (0);
	return (1);
}

int	check_col(int board[6][6], int x)
{
	if (check_col_up(board, x) && check_col_down(board, x))
		return (1);
	return (0);
}
