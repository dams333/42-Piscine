/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:50:00 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/17 12:47:55 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	read_standard_input(void)
{
	char	buffer[30000];
	int		readed;
	int		i;

	readed = read(0, buffer, 30000);
	while (readed > 0)
	{
		i = -1;
		while (++i < readed)
			ft_putchar(buffer[i]);
		readed = read(0, buffer, 30000);
	}
}
