/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:17:51 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/23 20:32:23 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_error(char *program_name, char *file)
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

int	open_file(char *file, char *p_name)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		print_error(p_name, file);
		return (0);
	}
	return (fd);
}

char	*get_complete(t_files_infos *f_infos, int nb, char *p_name)
{
	int		file;
	char	*buffer;
	int		i;
	int		completed;
	int		fd;

	completed = 0;
	buffer = malloc(sizeof(*buffer) * (nb + 1));
	i = -1;
	while (++i <= nb)
		buffer[i] = 0;
	close(f_infos->current_fd);
	f_infos->current_fd = -2;
	file = f_infos->current;
	while (++file < f_infos->file_count && completed < nb)
	{
		f_infos->current = file;
		fd = open_file(f_infos->files[file], p_name);
		if (fd)
		{
			f_infos->current_fd = fd;
			completed += read(fd, buffer + completed, nb - completed);
		}
	}
	return (buffer);
}

void	complete_buffer(int readed, char *r_buf, char *c_buf, t_files_infos *fi)
{
	int	i;

	i = -1;
	while (++i < (16 - readed))
		r_buf[readed + i] = c_buf[i];
	print_complete(r_buf, fi->option, fi->offset);
	fi->offset += 16;
}

void	read_file(t_files_infos f_infos, char *p_name)
{
	int		readed;
	char	r_buffer[16];
	char	*c_buffer;

	readed = read(f_infos.current_fd, r_buffer, 16);
	while (readed > 0 && f_infos.current_fd >= 0)
	{
		if (readed == 16)
		{
			print_complete(r_buffer, f_infos.option, f_infos.offset);
			f_infos.offset += 16;
		}
		else
		{
			c_buffer = get_complete(&f_infos, 16 - readed, p_name);
			if (ft_strlen(c_buffer) != (16 - readed))
				print_not_complete(r_buffer, c_buffer, f_infos, readed);
			else
				complete_buffer(readed, r_buffer, c_buffer, &f_infos);
		}
		if (f_infos.current_fd != -2)
			readed = read(f_infos.current_fd, r_buffer, 16);
	}
	print_offset(f_infos.offset, r_buffer);
}
