/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:28:47 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/07 10:16:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	transform_to_hex(char c)
{
	if (c < 10)
	{
		return (c + 48);
	}
	else
	{
		if (c == 10)
			return ('a');
		if (c == 11)
			return ('b');
		if (c == 12)
			return ('c');
		if (c == 13)
			return ('d');
		if (c == 14)
			return ('e');
		if (c == 15)
			return ('f');
	}
	return (-1);
}

void	print_char_on_hexa(char c)
{
	char	first;
	char	second;	

	first = transform_to_hex(c / 16);
	second = transform_to_hex(c % 16);
	write(1, &first, 1);
	write(1, &second, 1);
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
			print_char_on_hexa(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}	
		i++;
	}
}

int main()
{
	ft_putstr_non_printable("Salut\nles amis	!");
	return 0;
}
