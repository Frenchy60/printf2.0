/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlenum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:47:55 by agraton           #+#    #+#             */
/*   Updated: 2021/09/09 18:27:45 by agraton          ###   ########.fr       */
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
	ft_itoab(buffer + 2, (unsigned long)a, 16, 0);
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
	if (tmp > 0)
		return (ft_strlenc(buffer, '\0') + tmp);
	return (ft_strlenc(buffer, '\0'));
}

static int	ft_printic(a_list *list, char *buffer, int neg)
{
	int	es;
	int	tmp;

	es = ft_max(list->left, list->size) - ft_max(ft_strlenc(buffer, '\0'),
			list->dotn) - (neg || list->space || list->plus);
	tmp = list->dotn;
	list->dotn -= ft_strlenc(buffer, '\0') + (neg || list->space || list->plus);
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
	while (es-- > 0)
		write(1, " ", 1);
	return (ft_max(ft_strlenc(buffer, '\0') + (list->space || neg || list->plus)
			, ft_max(tmp, ft_max(list->space, list->left))));
}

int	ft_printi(long n, a_list *list)
{
	char	buffer[12];
	int		neg;

	neg = 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	list->dotn += (!list->zero && (neg || list->space || list->plus));
	ft_itoab(buffer, (unsigned long)n, 10, 0);
	return (ft_printic(list, buffer, neg));
}

int	ft_printu(unsigned int n, a_list *list)
{
	return (ft_printi((long)n, list));
}
