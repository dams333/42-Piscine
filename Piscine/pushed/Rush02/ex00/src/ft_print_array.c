/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:33:55 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 15:01:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	ft_print_num(char *str, t_stock *tab);

void	ft_hundred(char *tab, char *str, t_stock *strtab)
{
	tab[0] = str[0];
	tab[1] = '\0';
	ft_print_num(tab, strtab);
	write(1, " ", 1);
	ft_print_num("100", strtab);
}

void	ft_ten(char *tab, char *str, t_stock *strtab)
{
	tab[0] = str[1];
	tab[1] = str[2];
	ft_print_num(tab, strtab);
}

void	ft_unite(char *tab, char *str, t_stock *strtab)
{
	tab[0] = str[1];
	tab[1] = '0';
	tab[2] = '\0';
	ft_print_num(tab, strtab);
}

void	ft_unite2(char *tab, char *str, t_stock *strtab)
{
	tab[0] = str[2];
	tab[1] = '\0';
	ft_print_num(tab, strtab);
}

void	ft_print_array(char *str, t_stock *strtab)
{
	int		i;
	int		nb;
	char	tab[4];

	i = 0;
	nb = str[i];
	if (str[0] != '0')
	{
		ft_hundred(tab, str, strtab);
		if (str[1] != '0' || str[2] != '0')
			write(1, " and ", 5);
	}
	if (str[1] == '1')
		ft_ten(tab, str, strtab);
	else
	{
		if (str[1] != '0')
		{
			ft_unite(tab, str, strtab);
			if (str[2] != '0')
				write(1, "-", 1);
		}
		if (str[2] != '0')
			ft_unite2(tab, str, strtab);
	}
}
