/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:48:25 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 21:51:53 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}
