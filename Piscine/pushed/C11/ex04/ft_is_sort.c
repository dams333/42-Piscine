/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:01:31 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/20 10:17:18 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	order;

	i = 0;
	order = 0;
	while ((i + 1) < length)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
		{
			if (order == 0)
				order = -1;
			else if (order == 1)
				return (0);
		}
		if ((*f)(tab[i], tab[i + 1]) > 0)
		{
			if (order == 0)
				order = 1;
			else if (order == -1)
				return (0);
		}
		i++;
	}
	return (1);
}
