/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:08:19 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 17:29:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_error(char *file, int *failed)
{
	char	*error;

	*failed = 1;
	write(2, g_program_name, ft_strlen(g_program_name));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	error = strerror(errno);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

int	read_file(int fd, int offset)
{
	int		readed;
	int		total_readed;
	char	buffer[SIZE_BUFFER];
	char	*wanted_data;

	total_readed = 0;
	wanted_data = malloc(sizeof(*wanted_data) * offset);
	readed = read(fd, buffer, SIZE_BUFFER);
	total_readed += readed;
	while (readed && readed != -1)
	{
		if (offset < readed)
			push(wanted_data, offset, buffer + readed - offset, offset);
		else
			push(wanted_data, offset, buffer, readed);
		readed = read(fd, buffer, SIZE_BUFFER);
		total_readed += readed;
	}
	if (total_readed < offset)
		write(1, wanted_data + offset - total_readed, total_readed);
	else
		write(1, wanted_data, offset);
	return (0);
}

void	print_file_name(char *file)
{
	write(1, "==> ", 4);
	write(1, file, ft_strlen(file));
	write(1, " <==\n", 5);
}

int	read_last_all_files(int offset, int argc, int first, char **argv)
{
	int	f_descriptor;
	int	i;
	int	multiple;
	int	failed;

	multiple = ((first + 1) != argc);
	i = first - 1;
	while (++i < argc)
	{
		failed = 0;
		f_descriptor = open(argv[i], O_RDONLY);
		if (f_descriptor == -1)
			print_error(argv[i], &failed);
		else
		{
			if (!failed && i != first && multiple)
				write(1, "\n", 1);
			if (multiple)
				print_file_name(argv[i]);
			read_file(f_descriptor, offset);
		}
		close(f_descriptor);
	}
	return (0);
}

int	read_last_standard_input(int offset)
{
	read_file(0, offset);
	return (0);
}
