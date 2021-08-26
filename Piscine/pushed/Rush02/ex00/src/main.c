/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:13:48 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 15:52:23 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	call_program(char *dico, char *number)
{
	t_stock	*tab;

	while (number[0] && number[1] && number[0] == '0')
		number++;
	tab = parse_dictionnary(dico, 1);
	if (!tab)
		write(1, "Dict Error\n", 11);
	else
	{
		ft_rush(number, tab);
		free(tab);
	}
}

int	ft_arg1(char **argv)
{
	int	i;

	i = -1;
	while (argv[1][++i] != '\0')
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	call_program("resources/numbers.dict", argv[1]);
	return (0);
}

int	ft_arg2(char **argv)
{
	int	i;

	i = -1;
	while (argv[2][++i] != '\0')
	{
		if (!(argv[2][i] >= '0' && argv[2][i] <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	call_program(argv[1], argv[2]);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		ft_arg1(argv);
		return (0);
	}
	else if (argc == 3)
	{
		ft_arg2(argv);
		return (0);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
