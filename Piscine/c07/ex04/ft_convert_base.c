/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:13:21 by dhubleur          #+#    #+#             */
/*   Updated: 2021/08/16 22:04:16 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);
int	ft_strlen(char *str);

int	count_digit(int nbr, char *base)
{
	int			base_size;
	long int	nb;
	int			count;

	count = 0;
	base_size = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb >= base_size)
	{
		nb = nb / base_size;
		count++;
	}
	return (++count);
}

void	ft_convnbr_base(int nbr, char *base, char *ptr, int i)
{
	int			base_size;
	long int	nb;

	base_size = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		ptr[0] = '-';
	}
	if (nb >= base_size)
		ft_convnbr_base(nb / base_size, base, ptr, i - 1);
	ptr[i] = base[nb % base_size];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		convert;
	int		count;
	char	*ptr;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	convert = ft_atoi_base(nbr, base_from);
	count = count_digit(convert, base_to) + 1;
	ptr = malloc(sizeof(*nbr) * count);
	ft_convnbr_base(convert, base_to, ptr, count - 2);
	ptr[count - 1] = '\0';
	return (ptr);
}

#include <stdio.h>
int    main(int argc, char **argv)
{
    (void)argc;
    printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
}
