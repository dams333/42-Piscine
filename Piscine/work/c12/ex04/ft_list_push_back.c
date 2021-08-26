/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:26:50 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/23 10:31:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*begin;

	elem = malloc(sizeof(*elem));
	elem->data = data;
	elem->next = 0;
	if ((*begin_list)->next == 0)
		*begin_list = elem;
	else
	{
		begin = *begin_list;
		while (begin)
		{
			if (begin->next == 0)
			{
				begin->next = elem;
				return ;
			}
			begin = begin->next;
		}
	}
}
