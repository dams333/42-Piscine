/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbogicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 10:43:40 by dbogicev          #+#    #+#             */
/*   Updated: 2021/08/15 11:30:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_parse(int board[6][6], int argc, char **argv);
void	ft_print(int board[6][6]);
int		start_resolve(int board[6][6]);
void	ft_print(int board[6][6]);

void	init_board(int board[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	board[6][6];

	if (ft_parse(board, argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_board(board);
	if (start_resolve(board))
	{
		ft_print(board);
	}
	else
	{
		write(1, "Error\n", 6);
	}
}
