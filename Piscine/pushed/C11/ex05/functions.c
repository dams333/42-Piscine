/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:17:00 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/19 09:46:56 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n);

void	plus(int i1, int i2)
{
	int	result;

	result = i1 + i2;
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	minus(int i1, int i2)
{
	int	result;

	result = i1 - i2;
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	multiple(int i1, int i2)
{
	int	result;

	result = i1 * i2;
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	divide(int i1, int i2)
{
	int	result;

	if (i2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	result = i1 / i2;
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	modulo(int i1, int i2)
{
	int	result;

	if (i2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	result = i1 % i2;
	ft_putnbr(result);
	write(1, "\n", 1);
}
