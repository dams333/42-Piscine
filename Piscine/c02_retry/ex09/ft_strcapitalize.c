/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:36:54 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/07 09:40:24 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

int	is_alphanumeric(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

void	capitalize(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] = str[i] - 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	i = 0;
	while (str[i] != 0)
	{
		if (i == 0)
		{
			capitalize(str, i);
		}
		else
		{
			if (is_alphanumeric(str[i - 1]) == 0)
			{
				capitalize(str, i);
			}
		}
		i++;
	}
	return (str);
}
