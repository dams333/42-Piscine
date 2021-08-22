/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:30:27 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/07 17:12:07 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	strlength(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size)
	{
		i = 0;
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		while (i < size)
			dest[i++] = '\0';
	}
	return (strlength(src));
}
