/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:12:32 by agraton           #+#    #+#             */
/*   Updated: 2021/09/09 18:14:16 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printx(unsigned int a, a_list *list)
{
	char	buffer[20];
	int		es;
	int		tmp;

	if (list->hastag && a)
	{
		buffer[0] = '0';
		buffer[1] = 'x';
	}
	ft_itoab(buffer + ((list->hastag && a) * 2), a, 16, list->dotn);
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

int	ft_printX(unsigned int a, a_list *list)
{
	char	buffer[20];
	int		es[2];

	if (list->hastag && a)
	{
		buffer[0] = '0';
		buffer[1] = 'X';
	}
	ft_itoab(buffer + ((list->hastag && a) * 2), a, 16, list->dotn);
	ft_touppers(buffer);
	es[0] = list->size;
	if (list->left)
		es[0] = list->left;
	es[0] -= ft_strlenc(buffer, '\0');
	es[1] = es[0];
	if (es[0] > 0 && !list->left)
		while (es[0]--)
			write(1, " ", 1);
	write(1, buffer, ft_strlenc(buffer, '\0'));
	if (es[0] > 0)
		while (es[0]--)
			write(1, " ", 1);
	if (es[1] > 0)
		return (ft_strlenc(buffer, '\0') + es[1]);
	return (ft_strlenc(buffer, '\0'));
}
