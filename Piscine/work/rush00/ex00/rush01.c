/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:09:18 by hbembnis          #+#    #+#             */
/*   Updated: 2021/08/08 23:20:15 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	top_line(int x)
{
	int	j;

	j = 1;
	ft_putchar('/');
	while (j < x - 1)
	{
		ft_putchar('*');
		j ++;
	}
	if (x > 1)
	{
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	bottom_line(int x)
{
	int	j;

	j = 1;
	ft_putchar('\\');
	while (j < x - 1)
	{
		ft_putchar('*');
		j ++;
	}
	if (x > 1)
	{
		ft_putchar('/');
	}
	ft_putchar('\n');
}

void	empty_line(int x)
{
	int	j;

	j = 1;
	ft_putchar('*');
	while (j < x - 1)
	{
		ft_putchar(' ');
		j ++;
	}
	if (x > 1)
	{
		ft_putchar('*');
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
