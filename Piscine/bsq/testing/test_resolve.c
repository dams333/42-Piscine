/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_resolve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:41:06 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/23 15:22:26 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_resolve.h"

int	get_min(int a, int b, int c)
{
	if(a <= b && a <= c)
		return a;
	if(b <= a && b <= c)
		return b;
	if(c <= a && c <= b)
		return c;
	return -1;
}

int	main()
{
	// 0 = free
	// 1 = obstacle
	// 2 = full
	int grid[5][5] = {
		{0, 1, 1, 0, 0}, 
		{0, 0, 1, 0, 0},
		{1, 0, 0, 0, 0},
		{0, 0, 0, 1, 1},
		{0, 0, 1, 0, 0}
	};

	// free => -1
	// obsacle => 0
	// -1 is modifiable
	// >= 0 is fixed
	int grid_solve[5][5] = {
		{-1, 0, 0, -1, -1}, 
		{-1, -1, 0, -1, -1},
		{0, -1, -1, -1, -1},
		{-1, -1, -1, 0, 0},
		{-1, -1, 0, -1, -1}
	};


	char free = '.';
	char obstacle = 'o';
	char full = 'X';

	printf("----- GRID -----\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}

	printf("----- PRE SOLVE -----\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf("%d ", grid_solve[i][j]);
		}
		printf("\n");
	}


	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(grid_solve[i][j] == - 1)
			{
				if(i == 0 || j == 0)
				{
					grid_solve[i][j] = 1;	
				}
				else
				{
					int left = grid_solve[i][j - 1];
					int diag = grid_solve[i - 1][j - 1];
					int top = grid_solve[i - 1][j];
					grid_solve[i][j] = get_min(left, diag, top) + 1;
				}
			}
		}
	}

	printf("----- SOLVE -----\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf("%d ", grid_solve[i][j]);
		}
		printf("\n");
	}



	int i_bigger = 0;
	int j_bigger = 0;
	int bigger = grid_solve[0][0];

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(grid_solve[i][j] > bigger)
			{
				bigger = grid_solve[i][j];
				i_bigger = i;
				j_bigger = j;
			}
		}
	}


	printf("Biggest square is %d length in i=%d j=%d\n", bigger, i_bigger, j_bigger);

	for(int i = 0; i < bigger; i++)
	{
		for(int j = 0; j < bigger; j++)
		{
			grid[i_bigger - i][j_bigger - j] = 2;
		}
	}



	printf("----- GRID -----\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(grid[i][j] == 0)
			{
				write(1, &free, 1);
			}
			if(grid[i][j] == 1)
			{
				write(1, &obstacle, 1);
			}
			if(grid[i][j] == 2)
			{
				write(1, &full, 1);
			}
			write(1, " ", 1);
		}
		printf("\n");
	}


}