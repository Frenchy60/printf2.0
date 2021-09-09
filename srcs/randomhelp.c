/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomhelp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:14:21 by agraton           #+#    #+#             */
/*   Updated: 2021/09/09 18:32:22 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlenc(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_min(int i, int o)
{
	if (i > o)
		return (o);
	return (i);
}

int	ft_max(int i, int o)
{
	if (i > o)
		return (i);
	return (o);
}

int	ft_atoip(char **s)
{
	int	ans;

	ans = 0;
	if (**s < '0' || **s > '9')
		return (0);
	while (**s >= '0' && **s <= '9')
	{
		ans *= 10;
		ans += (**s - '0');
		(*s)++;
	}
	(*s)--;
	return (ans);
}
