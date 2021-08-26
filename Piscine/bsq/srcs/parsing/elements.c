/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:07:05 by jmaia             #+#    #+#             */
/*   Updated: 2021/08/24 18:56:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

int	is_good_element(char c, t_elements *elements)
{
	return (c == elements->empty || c == elements->obstacle);
}
