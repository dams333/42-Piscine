/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:31:12 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/05 19:28:58 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i <= size / 2)
	{
		j = size - i - 1;
		printf("\nSize: %d, I: %d, J: %d", size, i, j);
		tmp = *(tab + i);
		*(tab + i) = *(tab + j);
		*(tab + j) = tmp;
		i++;
	}
}

int main(){
	int test[10] = {
		-2147483648,
		2222222,
		3333333,
		4444444,
		0,
		6666666,
		7777777,
		8888888,
		9999999,
		2147483647
	};

	printf("\n");
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", test[i]);
	}

	ft_rev_int_tab(test, 10);

	printf("\n");
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", test[i]);
	}

}
