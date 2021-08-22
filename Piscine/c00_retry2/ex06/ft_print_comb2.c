/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:12:01 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/05 09:58:52 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(int i1, int i2, int j1, int j2)
{
	char	i1_c;
	char	i2_c;
	char	j1_c;
	char	j2_c;

	i1_c = i1 + '0';
	i2_c = i2 + '0';
	j1_c = j1 + '0';
	j2_c = j2 + '0';
	if ((i1 * 10 + i2) < (j1 * 10 + j2))
	{
		write(1, &i1_c, 1);
		write(1, &i2_c, 1);
		write(1, " ", 1);
		write(1, &j1_c, 1);
		write(1, &j2_c, 1);
		if (i1 != 9 || i2 != 8 || j1 != 9 || j2 != 9)
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb2(void)
{
	int	i1;
	int	i2;
	int	j1;
	int	j2;

	i1 = -1;
	while (i1++ < 9)
	{
		i2 = -1;
		while (i2++ < 9)
		{
			j1 = i1 - 1;
			while (j1++ < 9)
			{
				j2 = -1;
				while (j2++ < 9)
				{
					print_numbers(i1, i2, j1, j2);
				}
			}
		}
	}
}
