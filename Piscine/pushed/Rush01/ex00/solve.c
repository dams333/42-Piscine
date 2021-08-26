/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:27:10 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/15 11:32:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		already_in_col(int board[6][6], int n, int x);
int		already_in_line(int board[6][6], int n, int y);
void	ft_print(int board[6][6]);
int		check_col(int board[6][6], int x);
int		check_line(int board[6][6], int y);

int	is_valid(int board[6][6], int pos)
{
	int	x;
	int	y;
	int	i;

	if (pos == 16)
		return (1);
	y = (pos / 4) + 1;
	x = (pos % 4) + 1;
	if (board[x][y] != 0)
		return (is_valid(board, pos + 1));
	i = 0;
	while (++i <= 4)
	{
		if (!already_in_col(board, i, x) && !already_in_line(board, i, y))
		{
			board[x][y] = i;
			if (check_col(board, x) && check_line(board, y))
			{
				if (is_valid(board, pos + 1))
					return (1);
			}
		}
	}
	board[x][y] = 0;
	return (0);
}

int	start_resolve(int board[6][6])
{
	return (is_valid(board, 0));
}
