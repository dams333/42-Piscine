/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:13:42 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/05 14:53:21 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_length(char *s)
{
	int	length;

	length = 0;
	while (*s++ != 0)
	{
		length++;
	}
	return (length);
}

void	ft_putstr(char *str)
{
	write(1, str, str_length(str));
}
