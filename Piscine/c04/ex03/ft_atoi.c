/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:59:58 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/12 16:17:23 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*clear_string_of_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			i++;
		else if (str[i] == '-')
			i++;
		else
		{
			return (str + i);
		}
	}
	return (str);
}

int	get_sign(char *str)
{
	int	i;
	int	minus_count;

	i = 0;
	minus_count = 0;
	while (str[i])
	{
		if (str[i] == '+')
			i++;
		else if (str[i] == '-')
		{
			i++;
			minus_count++;
		}
		else
		{
			return (minus_count % 2);
		}
	}
	return (0);
}

char	*clear_string_of_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v'
			&& str[i] != '\f' && str[i] != '\r' && str[i] != '\n')
		{
			return (str + i);
		}
		i++;
	}
	return (str);
}

int	add_to_result(char c, int result)
{
	int	nb;

	nb = c - 48;
	result *= 10;
	result += nb;
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	i = 0;
	str = clear_string_of_spaces(str);
	sign = get_sign(str);
	str = clear_string_of_sign(str);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (sign)
				result *= -1;
			return (result);
		}
		result = add_to_result(str[i], result);
		i++;
	}	
	if (sign)
		result *= -1;
	return (result);
}
