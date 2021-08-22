/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:34:12 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 19:55:06 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	ft_print_num(char *str, t_stock *strtab);
int		str_len(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char	*s1, char	*s2);

void	ft_big_num(int i, t_stock *strtab, char **next, int count)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc(sizeof(char) * ((i - 1) * 3 + 2));
	if (!str)
		return ;
	str[0] = '1';
	while (++j < ((i - 1) * 3 + 1))
		str[j] = '0';
	str[j] = '\0';
	write(1, " ", 1);
	ft_print_num(str, strtab);
	j = 0;
	while (++j < count)
	{
		if (ft_strcmp(next[j], "000") != 0)
		{	
			write(1, " ", 1);
			break ;
		}
	}
	free(str);
}

char	*add_zero(char *str)
{
	int		i;
	int		y;
	char	*dest;

	i = 0;
	y = -1;
	dest = malloc(sizeof(char) * (str_len(str) + 1));
	if (str_len(str) % 3 == 1)
	{
		dest[0] = '0';
		dest[1] = '0';
		i = 2;
	}
	else if (str_len(str) % 3 == 2)
	{
		dest[0] = '0';
		i = 1;
	}
	while (str[++y] != '\0')
	{
		dest[i] = str[y];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char	*s1, char	*s2)
{
	while (*s1 != '\0' && *s2 == *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_print_num(char *str, t_stock *strtab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_strcmp(strtab[i].nbr, str) != 0)
	{
		i++;
	}
	if (ft_strcmp(strtab[i].nbr, str) != 0)
		write(1, "Dict Error\n", 11);
	else
		ft_putstr(strtab[i].write);
}
