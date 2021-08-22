/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:24:56 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/17 12:49:32 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

int		ft_strlen(char *str);
void	read_file(char *file, char *program_name);
void	read_standard_input(void);
void	ft_putchar(char c);

#endif
