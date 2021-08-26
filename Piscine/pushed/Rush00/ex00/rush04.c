/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:31:44 by hbembnis          #+#    #+#             */
/*   Updated: 2021/08/08 23:21:05 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	top_line(int x)
{
	int	j;

	j = 1;
	ft_putchar('A');
	while (j < x - 1)
	{
		ft_putchar('B');
		j ++;
	}
	if (x > 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	bottom_line(int x)
{
	int	j;

	j = 1;
	ft_putchar('C');
	while (j < x - 1)
	{
		ft_putchar('B');
		j ++;
	}
	if (x > 1)
	{
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	empty_line(int x)
{
	int	j;

	j = 1;
	ft_putchar('B');
	while (j < x - 1)
	{
		ft_putchar(' ');
		j ++;
	}
	if (x > 1)
	{
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{	
	int	i;

	if (x > 0 && y > 0)
	{
		i = 1;
		top_line(x);
		while (i < y - 1)
		{
			empty_line(x);
			i ++;
		}
		if (y > 1)
		{
			bottom_line(x);
		}
	}
}
