/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 08:56:21 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/08 18:26:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*find(char *str, char *to_find)
{
	int		i;
	int		i2;
	int		j;
	char	*ptr;

	i = -1;
	while (str[++i])
	{
		if (str[i] == to_find[0])
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

char	*ft_strstr(char *str, char *to_find)
{
	if (!to_find[0])
		return (str);
	return (find(str, to_find));
}
