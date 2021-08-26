/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:52:08 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/22 21:57:41 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_element;

	new_element = malloc(sizeof(*new_element));
	if(!new_element)
		return ;
	new_element->data = data;
	new_element->next = *begin_list;
	*begin_list = new_element;
}
