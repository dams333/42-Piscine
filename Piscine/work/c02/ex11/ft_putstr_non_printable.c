/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:28:47 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/06 22:26:20 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	transform_to_hex(int i)
{
	if (i < 10)
	{
		return (i + '0');
	}
	else
	{
		if (i == 10)
			return ('a');
		if (i == 11)
			return ('b');
		if (i == 12)
			return ('c');
		if (i == 13)
			return ('d');
		if (i == 14)
			return ('e');
		if (i == 15)
			return ('f');
	}
	return (-1);
}

void	print_int_on_hexa(int n)
{
	int		first;
	int		second;
	char	first_c;
	char	second_c;	

	first = n / 16;
	second = n % 16;
	first_c = transform_to_hex(first);
	second_c = transform_to_hex(second);
	write(1, &first_c, 1);
	write(1, &second_c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			write(1, "\\", 1);
			print_int_on_hexa((int) str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}	
		i++;
	}
}
