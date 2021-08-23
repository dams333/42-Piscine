/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:32:24 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/23 10:37:01 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*last;
	t_list	*current;

	last = 0;
	i = -1;
	while (++i < size)
	{
		current = malloc(sizeof(*current));
		current->data = strs[i];
		current->next = last;
		last = current;
	}
	return (last);
}
