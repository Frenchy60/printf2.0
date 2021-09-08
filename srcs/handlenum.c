/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlenum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:47:55 by agraton           #+#    #+#             */
/*   Updated: 2021/09/08 20:07:12 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printp(void *a, a_list *list)
{
	char	buffer[20];
	int		es;
	int		tmp;

	buffer[0] = '0';
	buffer[1] = 'x';
	ft_itoab(buffer + 2, list, (unsigned long)a, 16);
	es = list->size;
	if (list->left)
		es = list->left;
	es -= ft_strlenc(buffer, '\0');
	tmp = es;
	if (es > 0 && !list->left)
		while (es--)
			write(1, " ", 1);
	write(1, buffer, ft_strlenc(buffer, '\0'));
	if (es > 0)
		while (es--)
			write(1, " ", 1);
	return (ft_strlenc(buffer, '\0') + tmp);
}

int	ft_printd(long n, a_list *list)
{
	char	buffer[12];
	int		neg;
	int		es;
	int		tmp;

	tmp = list->dotn;
	neg = 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	ft_itoab(buffer, list, (unsigned long)n, 10);
	es = ft_max(list->left, list->size) - ft_max(ft_strlenc(buffer, '\0'),
			list->dotn) - ft_max(neg, ft_max(list->space, list->plus));
	list->dotn -= ft_strlenc(buffer, '\0');
	if (es > 0 && !list->left)
		while (es--)
			write(1, " ", 1);
	if (neg)
		write(1, "-", 1);
	else if (list->space)
		write(1, " ", 1);
	else if (list->plus)
		write(1, "+", 1);
	while (list->dotn-- > 0)
		write(1, "0", 1);
	write(1, buffer, ft_strlenc(buffer, '\0'));
	while (es > 0)
		write(1, " ", 1);
	return (ft_max(ft_strlenc(buffer, '\0'), ft_max(tmp, ft_max(list->space,
						list->left))));
}
