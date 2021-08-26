/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:14:27 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 14:16:06 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stock
{
	char	*nbr;
	char	*write;
}	t_stock;

t_stock	*parse_dictionnary(char *file, int check);
void	ft_rush(char *arg, t_stock *strtab);

#endif
