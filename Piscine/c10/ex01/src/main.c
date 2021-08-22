/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:54:56 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/17 12:46:06 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	analyse_input(char *file, char *program_name)
{
	if (ft_strlen(file) == 1)
	{
		if (file[0] == '-')
		{
			read_standard_input();
			return ;
		}
	}
	read_file(file, program_name);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		analyse_input("-", argv[0]);
	}
	else
	{
		while (i < argc)
		{
			analyse_input(argv[i], argv[0]);
			i++;
		}
	}
}
