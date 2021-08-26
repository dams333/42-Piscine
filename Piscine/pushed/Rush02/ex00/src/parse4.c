/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:41:00 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 15:45:14 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	count_number(char *str, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (is_whitespace(str[i]) || str[i] == ':')
			return (i);
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (0);
}

int	ft_strcmp2(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	check_validate(t_stock *tab)
{
	t_stock	*compare;
	int		i;
	int		j;
	int		find;

	compare = parse_dictionnary("resources/numbers.dict", 0);
	i = 0;
	while (compare[i].nbr[0] != '\0')
	{
		find = 0;
		j = 0;
		while (tab[j].nbr[0] != '\0')
		{
			if (ft_strcmp2(tab[j].nbr, compare[i].nbr) == 0)
				find = 1;
			j++;
		}
		if (!find)
			return (0);
		i++;
	}
	return (1);
}
