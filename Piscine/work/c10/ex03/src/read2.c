/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:38:35 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/25 09:33:44 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	read_error(char *p_name, char **files, int f_count);

void	start_read_files(char **files, int file_count, int opt, char *p_name)
{
	int				fd;
	int				i;
	t_files_infos	f_infos;

	i = 0;
	fd = 0;
	while (!fd && i < file_count)
	{
		fd = open_file(files[i], p_name);
		if (!fd)
			i++;
	}
	if (i == file_count)
		read_error(p_name, files, file_count);
	else if (fd)
	{
		f_infos.files = files;
		f_infos.file_count = file_count;
		f_infos.current = i;
		f_infos.current_fd = fd;
		f_infos.offset = 0;
		f_infos.option = opt;
		read_file(f_infos, p_name);
	}
}

void	read_error(char *p_name, char **files, int f_count)
{
	char	*file;
	char	stock;
	char	*error;

	file = files[f_count - 1];
	read(-1, &stock, 1);
	write(2, p_name, ft_strlen(p_name));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	error = strerror(errno);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

void	print_standard_entry(int option, char *p_name)
{
	t_files_infos	f_infos;

	f_infos.files = 0;
	f_infos.file_count = 1;
	f_infos.current = 0;
	f_infos.current_fd = 0;
	f_infos.offset = 0;
	f_infos.option = option;
	read_file(f_infos, p_name);
}

int	read_next(t_files_infos *fi, char *r_buffer, char *p_name)
{
	int	readed;
	int	file;
	int	fd;

	readed = read(fi->current_fd, r_buffer, 16);
	file = fi->current;
	while (++file < fi->file_count && readed == 0)
	{
		if (fi->current_fd != 0)
			close(fi->current_fd);
		fi->current = file;
		fd = open_file(fi->files[file], p_name);
		if (fd)
		{
			fi->current_fd = fd;
			readed = read(fd, r_buffer, 16);
		}
	}
	return (readed);
}
