/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playingwithnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:57:33 by agraton           #+#    #+#             */
/*   Updated: 2021/09/09 18:31:51 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	findsize(unsigned long n, int base)
{
	int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= base;
	}
	return (ft_max(1, size));
}

static char	convert(int n)
{
	if (n < 10)
		return (n + '0');
	return (n + 'a' - 10);
}

void	ft_itoab(char *s, unsigned long n, int base, int length)
{
	int	size;

	size = findsize(n, base);
	if (length < size)
		length = size;
	s[length] = '\0';
	while (size--)
	{
		length--;
		s[length] = convert(n % base);
		n /= base;
	}
	while (length > 0)
		s[--length] = '0';
}

void	ft_touppers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
}
