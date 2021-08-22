/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:30:27 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/06 22:26:09 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	size_str(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

unsigned	int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;

	i = 0;
	while(i < ((int) size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size_str(src));
}
