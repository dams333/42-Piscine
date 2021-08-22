/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:14:00 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/18 10:01:42 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# define SIZE_BUFFER 10

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <libgen.h>
# include <stdio.h>

char	*g_program_name;

int		is_nbr(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);

int		read_last_all_files(int offset, int argc, int first, char **argv);
int		read_last_standard_input(int offset);
int		ft_atoi(char *str);
void	push(char *tab, int size_tab, char *new_elems, int size_new_elems);

#endif
