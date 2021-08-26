/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:32:35 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 15:52:25 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define BUFFER_SIZE 500

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stock
{
	char	*nbr;
	char	*write;
}	t_stock;

typedef struct s_read_infos
{
	char	buffer[BUFFER_SIZE];
	char	*stock;
	int		current_stock;
	int		stocked_struct;
	int		start;
	t_stock	*struct_tab;
}	t_read_infos;

t_stock			*parse_dictionnary(char *file, int check);
t_stock			*read_file(int fd);
t_stock			*create_complete(char *str, int start, int stop);
t_stock			*create_multiple(t_read_infos *infos, int start, int stop);
int				is_whitespace(char c);
t_stock			*ft_realloc(t_stock *stock, int current, int increment);
void			free_tab(t_stock *tab, int count);
int				clear(int fd, t_read_infos *i);
int				create_struct(t_read_infos *i, int start, int stop, int fd);
void			add_to_stock(t_read_infos *infos, int start, int readed, int i);
t_stock			*end_read(int fd, t_read_infos infos);
t_read_infos	init_struct(void);
void			skip_whitespace(int *i, int readed, t_read_infos infos);
t_stock			*read_file(int fd);
int				is_whitespace(char c);
int				count_number(char *str, int length);
int				count_letter(char *str, int length);
void			fill_number_tab(char *tab, char *str, int length);
void			fill_letter_tab(char *tab, char *str, int length);
t_stock			*create_complete(char *str, int start, int stop);
t_stock			*create_multiple(t_read_infos *infos, int start, int stop);
int				check_validate(t_stock *tab);

#endif
