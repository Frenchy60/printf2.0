/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:25:43 by agraton           #+#    #+#             */
/*   Updated: 2021/09/09 18:10:55 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	int					zeron;
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
void	ft_itoab(char *s, unsigned long n, int base, int length);
void	ft_touppers(char *str);

a_list	*ft_newa_list();
int	ft_printf(const char *s, ...);
int	ft_printc(int c, a_list *list);
int	ft_prints(char *s, a_list *list);
int	ft_printp(void *a, a_list *list);
int	ft_printi(long n, a_list *list);
int	ft_printu(unsigned int n, a_list *list);
int	ft_printx(unsigned int n, a_list *list);
int	ft_printX(unsigned int n, a_list *list);

#endif
