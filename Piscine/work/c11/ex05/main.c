/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:07:49 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/19 11:51:42 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	plus(int i1, int i2);
void	minus(int i1, int i2);
void	multiple(int i1, int i2);
void	divide(int i1, int i2);
void	modulo(int i1, int i2);

int	ft_atoi(char *str)
{
	int			i;
	int			signe;
	long int	result;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	signe = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (signe * result);
}

void	ft_putnbr(int n)
{
	long int	nbr;
	char		print;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	print = (nbr % 10) + 48;
	write(1, &print, 1);
}

int	ft_strequal(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] == str2[i]);
}

void	setup_tab(void (*ptr[5])(int, int))
{
	ptr[0] = &plus;
	ptr[1] = &minus;
	ptr[2] = &multiple;
	ptr[3] = &divide;
	ptr[4] = &modulo;
}

int	main(int argc, char **argv)
{
	int		first;
	int		second;
	void	(*ptr[5])(int, int);

	setup_tab(ptr);
	if (argc == 4)
	{
		first = ft_atoi(argv[1]);
		second = ft_atoi(argv[3]);
		if (ft_strequal(argv[2], "+"))
			(*ptr[0])(first, second);
		else if (ft_strequal(argv[2], "-"))
			(*ptr[1])(first, second);
		else if (ft_strequal(argv[2], "*"))
			(*ptr[2])(first, second);
		else if (ft_strequal(argv[2], "/"))
			(*ptr[3])(first, second);
		else if (ft_strequal(argv[2], "%"))
			(*ptr[4])(first, second);
		else
			write(1, "0\n", 2);
	}
}
