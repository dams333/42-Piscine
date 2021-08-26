/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:34:34 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 15:03:03 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int		str_count(char *str);
char	*add_zero(char *str);
void	ft_print_num(char *str, t_stock *tab);
void	ft_print_array(char *str, t_stock *strtab);
void	ft_big_num(int i, t_stock *strtab, char *next);

int	is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_tab(int j, char **tab, char *str)
{
	if (j % 3 == 0)
		tab[j / 3] = malloc(sizeof(char) * 3);
	tab[j / 3][j % 3] = str[j];
}

void	end_processus(char **tab, int length, char *str)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(str);
	write(1, "\n", 1);
}

void	ft_rush(char *arg, t_stock *strtab)
{
	char	**tab;
	char	*str;
	int		i;
	int		j;
	int		k;

	i = str_count(arg);
	tab = malloc(sizeof(char *) * i);
	str = add_zero(arg);
	if (!tab)
		return ;
	j = -1;
	while (str[++j] != '\0')
		ft_tab(j, tab, str);
	k = i;
	j = -1;
	while (++j < i)
	{
		ft_print_array(tab[j], strtab);
		if (i == 1 && is_zero(tab[j]))
			ft_print_num("0", strtab);
		if (j != i - 1)
			ft_big_num(k--, strtab, tab[j + 1]);
	}
	end_processus(tab, i, str);
}
