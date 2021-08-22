/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:14:28 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 17:36:15 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	print_error(char *file, char *program_name)
{
	char	*error;

	program_name = basename(program_name);
	write(2, program_name, ft_strlen(program_name));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	error = strerror(errno);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

void	read_file(char *file, char *program_name)
{
	int		f_descriptor;
	char	buffer[30000];
	int		readed;
	int		i;

	f_descriptor = open(file, O_RDONLY);
	if (f_descriptor == -1)
	{
		print_error(file, program_name);
		return ;
	}
	readed = read(f_descriptor, buffer, 30000);
	while (readed > 0)
	{
		i = -1;
		while (++i < readed)
			ft_putchar(buffer[i]);
		readed = read(f_descriptor, buffer, 30000);
	}
	if (readed == 1)
		print_error(file, program_name);
	close(f_descriptor);
}
