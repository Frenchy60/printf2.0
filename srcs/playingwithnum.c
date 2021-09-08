/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playingwithnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:57:33 by agraton           #+#    #+#             */
/*   Updated: 2021/09/08 20:07:16 by agraton          ###   ########.fr       */
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
		n/= base;
	}
	return (ft_max(1, size));
}

static char	convert(int n)
{
	if (n < 10)
		return (n + '0');
	return (n + 'a');
}

void	ft_itoab(char *s, a_list *list, unsigned long n, int base)
{
	int	size;

	size = findsize(n, base);
	s[size] = '\0';
	while (size--)
	{
		s[size] = convert(n % base);
		n /= base;
	}
}
