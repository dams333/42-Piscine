/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:14:23 by jmaia             #+#    #+#             */
/*   Updated: 2021/08/24 19:38:52 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_buffer.h"

t_dynamic_buffer	init_buffer(void)
{
	t_dynamic_buffer	buf;

	buf.buf = malloc(sizeof(*buf.buf) * EXPAND_SIZE);
	buf.i = 0;
	buf.size = EXPAND_SIZE;
	return (buf);
}

int	append(t_dynamic_buffer *buf, char c)
{
	int	has_error;

	has_error = 0;
	if (buf->i == buf->size)
		has_error = expand(buf);
	if (has_error)
		return (has_error);
	buf->buf[buf->i++] = c;
	return (has_error);
}

int	expand(t_dynamic_buffer *buf)
{
	char	*new_buffer;

	new_buffer = malloc(sizeof(*new_buffer) * (buf->size + EXPAND_SIZE));
	if (!new_buffer)
		return (1);
	ft_strncpy(new_buffer, buf->buf, buf->size);
	free(buf->buf);
	buf->buf = new_buffer;
	buf->size += EXPAND_SIZE;
	return (0);
}
