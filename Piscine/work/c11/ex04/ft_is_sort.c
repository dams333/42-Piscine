/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:01:31 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/20 10:23:13 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	order;

	i = 0;
	order = 0;
	while((i + 1) < length)
	{
		if((*f)(tab[i], tab[i + 1]) < 0)
		{
			if(order == 0)
				order = -1;
			else if(order == 1)
				return (0);
		}
		if((*f)(tab[i], tab[i + 1]) > 0)
		{
			if(order == 0)
				order = 1;
			else if(order == -1)
				return (0);
		}
		i++;
	}
	return (1);
}

int	compare(int i1, int i2)
{
	if(i1 > i2)
		return 1;
	if(i2 > i1)
		return -1;
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int	main()
{
	int	tab[] = {1, 1, 1, 1, 1};
	printf("%i\n", ft_is_sort(tab, 5, &compare));
}
