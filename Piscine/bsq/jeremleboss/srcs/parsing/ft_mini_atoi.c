/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:31:17 by jmaia             #+#    #+#             */
/*   Updated: 2021/08/24 17:42:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_mini_atoi(char *nbr, int size)
{
	int	i;
	int	result;

	if (size == 0)
		return (-1);
	i = 0;
	result = 0;
	while (i < size)
	{
		if (nbr[i] >= '0' && nbr[i] <= '9')
			result = result * 10 + nbr[i] - '0';
		else
			return (-1);
		i++;
	}
	return (result);
}
