/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbogicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 10:50:44 by dbogicev          #+#    #+#             */
/*   Updated: 2021/08/15 20:09:31 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_addnumber(int board[6][6], int i, int n)
{
	i = i / 2;
	if (i >= 0 && i <= 3)
	{
		board[i + 1][0] = n;
	}
	if (i >= 4 && i <= 7)
	{
		board[i - 3][5] = n;
	}
	if (i >= 8 && i <= 11)
	{
		board[0][i - 7] = n;
	}
	if (i >= 12 && i <= 15)
	{
		board[5][i - 11] = n;
	}
}

int	ft_parse(int board[6][6], int argc, char **argv)
{	
	char	*line;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	line = argv[1];
	while (line[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (line[i] > '0' && line[i] < '5' && i <= 30)
				ft_addnumber(board, i, line[i] - 48);
			else
				return (0);
		}
		else
			if (line[i] != ' ')
				return (0);
		i++;
	}
	if (i < 16)
		return (0);
	return (1);
}
