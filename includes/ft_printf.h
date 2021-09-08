/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:25:43 by agraton           #+#    #+#             */
/*   Updated: 2021/09/08 20:07:18 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Delete this crap
*/

# include <stdio.h>

/*
** Start back here
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
/*
** Basestr: The basic printing functions.
*/

typedef struct			s_list
{
	int					size;
	int					left;
	int					zero;
	int					dot;
	int					dotn;
	int					hastag;
	int					space;
	int					plus;
}						a_list;

int	ft_strlenc(char *s, char c);
int	ft_max(int i, int o);
int	ft_min(int i, int o);
int	ft_atoip(char **s);
void	ft_itoab(char *s, a_list *list, unsigned long n, int base);

a_list	*ft_newa_list();
int	ft_printf(const char *s, ...);
int	ft_printc(int c, a_list *list);
int	ft_prints(char *s, a_list *list);
int	ft_printp(void *a, a_list *list);
int	ft_printd(long n, a_list *list);

#endif
