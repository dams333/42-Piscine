/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:44:14 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/25 08:56:48 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <libgen.h>
# include <stdio.h>

typedef struct s_files_infos
{
	char	**files;
	int		file_count;
	int		current;
	int		current_fd;
	int		offset;
	int		option;
}	t_files_infos;

int		ft_strlen(char *str);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

void	print_complete(char *buffer, int option, int offset);
void	print_not_complete(char *b1, char *b2, t_files_infos f_i, int chars);
void	start_read_files(char **files, int file_count, int opt, char *p_name);
void	print_standard_entry(int option, char *p_name);
void	print_has_hexa(int nbr);
void	print_some_chars(char *buffer, int n);
void	tr_offset_to_hex(int offset, char *code, int i);
int		open_file(char *file, char *p_name);
void	read_file(t_files_infos f_infos, char *p_name);
void	print_offset(int offset, char *buffer, int option, int lb);
int		read_next(t_files_infos *fi, char *r_buffer, char *p_name);
void	print_error(char *program_name, char *file);

#endif
