/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:29:17 by agraton           #+#    #+#             */
/*   Updated: 2021/09/09 18:32:55 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

a_list	*ft_newa_list(void)
{
	a_list	*list;

	list = malloc(sizeof(a_list));
	if (!list)
		return (NULL);
	list->size = 0;
	list->left = 0;
	list->zero = 0;
	list->zeron = 0;
	list->dot = 0;
	list->dotn = 0;
	list->hastag = 0;
	list->space = 0;
	list->plus = 0;
	return (list);
}
