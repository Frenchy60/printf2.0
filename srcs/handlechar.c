/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlechar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:48:44 by agraton           #+#    #+#             */
/*   Updated: 2021/09/08 18:39:50 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printc(int d, a_list *list)
{
	int		size;
	char	c;

	c = (char)d;
	size = list->left;
	if (!size)
		size = list->size;
	if (size > 1 && !(list->left))
		while (size-- > 1)
			write(1, " ", 1);
	write(1, &c, 1);
	if (size > 1 && !(list->left))
		while (size-- > 1)
			write(1, " ", 1);
	return (ft_max(1, size));
}

int		ft_prints(char *s, a_list *list)
{
	int	i;
	int ss;
	int	size;

	size = list->left;
	if (!(list->left))
		size = list->size;
	if (list->dot)
		ss = ft_min(ft_strlenc(s, '\0'), list->dotn);
	else
		ss = ft_strlenc(s, '\0');
	i = size - ss;
	if (i > 0 && !list->left)
		while (i--)
			write(1, " ", 1);
	write(1, s, ss);
	if (i > 0 && list->left)
		while (i--)
			write(1, " ", 1);
	return (ft_max(ss, size));
}
