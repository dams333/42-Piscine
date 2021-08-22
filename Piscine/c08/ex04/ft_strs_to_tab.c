/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:34:44 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/16 10:47:26 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	ptr = (char *) malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}	

t_stock_str	*get_struct(char *str)
{
	t_stock_str	*stock;
	char		*cpy;

	stock = malloc(sizeof(*stock));
	cpy = ft_strdup(str);
	if (!cpy || !stock)
	{
		free(stock);
		return (NULL);
	}
	stock->str = str;
	stock->copy = cpy;
	stock->size = ft_strlen(str);
	return (stock);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	t_stock_str	empty;
	t_stock_str	*stock;
	int			i;

	tab = malloc(sizeof(*tab) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock = get_struct(av[i]);
		if (!stock)
		{
			free(tab);
			return (NULL);
		}
		tab[i] = *stock;
		i++;
	}
	empty.str = 0;
	tab[ac] = empty;
	return (tab);
}
