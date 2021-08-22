/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:47:48 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/19 10:02:47 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		find;
	char	*tmp;

	find = 1;
	while (find)
	{
		find = 0;
		i = 0;
		while (tab[i + 1] != 0)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				find = 1;
			}
			i++;
		}
	}	
}
