/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 08:40:23 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/10 15:54:48 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;
	unsigned int	nbr;

	nbr = nb;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while ((i * i) <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_is_prime(2147483647));
}
