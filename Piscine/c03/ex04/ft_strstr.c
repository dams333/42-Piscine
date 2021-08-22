/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 08:56:21 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/14 18:35:03 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		i2;
	int		j;
	char	*ptr;

	i = -1;
	while (str[++i])
	{
		if (to_find[0] && str[i] == to_find[0])
		{
			j = 0;
			i2 = i;
			while (str[i2] == to_find[j] && to_find[j] && str[i2])
			{
				i2++;
				j++;
			}
			if (!to_find[j])
			{
				ptr = str + i;
				return (ptr);
			}
		}
	}
	return (0);
}
