/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:38:35 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/23 20:32:27 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

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
	if (fd)
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
