/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:54:56 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 17:35:43 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		print_standard_entry(0, basename(argv[0]));
	else if (argc == 2)
	{
		if (ft_strcmp(argv[1], "-C") == 0)
			print_standard_entry(1, basename(argv[0]));
		else
			start_read_files(argv + 1, 1, 0, basename(argv[0]));
	}
	else
	{
		if (ft_strcmp(argv[1], "-C") == 0)
			start_read_files(argv + 2, argc - 2, 1, basename(argv[0]));
		else
			start_read_files(argv + 1, argc - 1, 0, basename(argv[0]));
	}
	return (0);
}
