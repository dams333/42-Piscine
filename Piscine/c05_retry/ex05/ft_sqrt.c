/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 08:22:51 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/10 15:49:09 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	i;
	unsigned int	nbr;

	if (nb <= 0)
		return (0);
	nbr = nb;
	if (nbr == 1)
		return (1);
	i = 1;
	while ((i * i) < nbr)
	{
		i++;
	}
	if ((i * i) == nbr)
	{
		return (i);
	}
	return (0);
}
