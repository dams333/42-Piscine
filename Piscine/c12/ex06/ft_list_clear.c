/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:37:28 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/23 10:40:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	while(begin_list)
	{
		(*free_fct)(begin_list->data);
		tmp = begin_list;
		begin_list = tmp->next;
		free(tmp);
	}
}
