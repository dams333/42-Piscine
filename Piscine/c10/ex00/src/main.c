/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:54:56 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/17 08:55:57 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/display_file.h"

int	main(int argc, char **argv)
{
	int		f_descriptor;
	char	current_char;

	if (argc < 2)
	{
		write(1, FILE_NAME_MISSING, 19);
		return (0);
	}
	if (argc > 2)
	{
		write(1, TOO_MANY_ARGUMENTS, 20);
		return (0);
	}
	f_descriptor = open(argv[1], O_RDONLY);
	if (f_descriptor == -1)
	{
		write(1, CANNOT_READ_FILE, 18);
		return (0);
	}
	while (read(f_descriptor, &current_char, 1))
		write(1, &current_char, 1);
	close(f_descriptor);
	return (0);
}
