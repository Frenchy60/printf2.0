/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:03:18 by agraton           #+#    #+#             */
/*   Updated: 2021/09/08 20:07:20 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

a_list	*ft_readflags(char **s)
{
	a_list	*list;

	list = ft_newa_list();
	if (!list)
		return (NULL);
	(*s)++;
	while ((**s >= '0' && **s <= '9') || **s == '-' || **s == '.' || **s == '#'
			|| **s == ' ' || **s == '+')
	{
		if (**s >= '1' && **s <= '9')
			list->size = ft_atoip(s);
		else if (**s == '-')
		{
			(*s)++;
			list->left = ft_max(1, ft_atoip(s));
		}
		else if (**s == '0')
			list->zero = 1;
		else if (**s == '.')
		{
			list->dot = 1;
			(*s)++;
			list->dotn = ft_atoip(s);
		}
		else if (**s == '#')
			list->hastag = 1;
		else if (**s == ' ')
			list->space = 1;
		else if (**s == '+')
			list->plus = 1;
		(*s)++;
	}
	return (list);
}

void	ft_readarg(va_list args, char **s, int *count)
{
	a_list	*list;

	list = ft_readflags(s);
	if (!list)
		return ;
	if (**s == 'c')
		*count += ft_printc(va_arg(args, int), list);
	else if (**s == 's')
		*count += ft_prints(va_arg(args, char *), list);
	else if (**s == 'p')
		*count += ft_printp(va_arg(args, void *), list);
	else if (**s == 'd')
		*count += ft_printd((long)va_arg(args, int), list);
	(*s)++;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	char	*s;

	s = (char *)str;
	count = 0;
	va_start(args, str);
	while (*s)
	{
		if (*s == '%')
			ft_readarg(args, &s, &count);
		i = ft_strlenc(s, '%');
		write(1, s, i);
		count += i;
		s += i;
	}
	va_end(args);
	return (count);
}
