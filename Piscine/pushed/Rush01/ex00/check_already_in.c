/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_already_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:46:07 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/15 08:58:01 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	already_in_col(int board[6][6], int n, int x)
{
	int	y;

	y = 1;
	while (y <= 4)
	{
		if (board[x][y] == n)
			return (1);
		y++;
	}
	return (0);
}

int	already_in_line(int board[6][6], int n, int y)
{
	int	x;

	x = 1;
	while (x <= 4)
	{
		if (board[x][y] == n)
			return (1);
		x++;
	}
	return (0);
}
