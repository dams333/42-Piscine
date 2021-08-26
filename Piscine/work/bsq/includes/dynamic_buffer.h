/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_buffer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:11:48 by jmaia             #+#    #+#             */
/*   Updated: 2021/08/25 23:15:30 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_BUFFER_H
# define DYNAMIC_BUFFER_H
# define EXPAND_SIZE 10
# include <stdlib.h>
# include "ft.h"
typedef struct s_dynamic_buffer
{
	char	*buf;
	int		i;
	int		size;
}	t_dynamic_buffer;
t_dynamic_buffer	init_buffer(void);
int					append(t_dynamic_buffer *buf, char c);
int					expand(t_dynamic_buffer *buf);
#endif
