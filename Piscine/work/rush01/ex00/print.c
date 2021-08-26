/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbogicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:26:13 by dbogicev          #+#    #+#             */
/*   Updated: 2021/08/15 11:21:57 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	ft_print(int board[6][6])
{
	int	x;
	int	y;

	y = 1;
	while (y <= 4)
	{
		x = 1;
		while (x <= 4)
		{
			ft_putnbr(board[x][y]);
			if (x == 4)
			{
				write(1, "\n", 1);
			}
			else
			{
				write(1, " ", 1);
			}
			x++;
		}
		y++;
	}
}
