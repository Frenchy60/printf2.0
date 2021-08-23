/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basestr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:56:23 by agraton           #+#    #+#             */
/*   Updated: 2021/08/23 14:50:38 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

static int	ft_findsize(long long n, int base)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n)
	{
		n /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(long long n, int base)
{
	int		size;
	int		c;
	char	*str;

	size = ft_findsize(n, base);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	c = 0;
	if (n < 0)
	{
		str[c++] = '-';
		n *= -1;
	}
	str[size] = '\0';
	while (size-- - c)
	{
		str[size] = ft_itoc_base(n % base, base);
		n /= base;
	}
	return (str);
}
