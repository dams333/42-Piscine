/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:49:07 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/15 20:27:26 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_char_in_array(char c, char *charset)
{
	int	i;

	if (!charset[0])
	{
		return (-1);
	}
	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_first_char(char *str, char *charset)
{
	int	i;

	i = 0;
	if (is_char_in_array(str[i], charset) == -1)
		return (0);
	while (str[i] && is_char_in_array(str[i], charset))
		i++;
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word;
	int	j;

	i = get_first_char(str, charset) - 1;
	word = 0;
	if (is_char_in_array(str[i], charset) == -1
		&& is_char_in_array(str[i], str) != -1)
		return (1);
	while (str[++i])
	{
		if (is_char_in_array(str[i], charset))
		{
			while (str[i] && is_char_in_array(str[i], charset))
				i++;
			if (str[i])
				word++;
			j = i;
			while (str[j] && !is_char_in_array(str[j], charset))
				j++;
			if (!str[j])
				return (++word);
		}
	}
	return (word);
}

char	*get_word(char *str, int start, int stop)
{
	int		range;
	int		i;
	char	*ptr;
	int		j;

	range = stop - start;
	ptr = malloc(sizeof(*str) * (range + 1));
	i = start;
	j = 0;
	while (i < stop)
	{
		ptr[j] = str[i];
		i++;
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}

char	**ft_split(char *str, char *charset)
{
	int		count_word;
	char	**strs;
	int		i;
	int		start;
	int		word;

	count_word = count_words(str, charset);
	strs = malloc(sizeof(*strs) * (count_word + 1));
	i = get_first_char(str, charset);
	start = i;
	word = 0;
	while (str[i++])
	{
		if (is_char_in_array(str[i], charset) == 1 || !str[i])
		{
			strs[word++] = get_word(str, start, i);
			while (is_char_in_array(str[i], charset) == 1)
				i++;
			start = i;
		}
	}
	strs[count_word] = 0;
	return (strs);
}
