/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:25:43 by agraton           #+#    #+#             */
/*   Updated: 2021/08/23 14:47:37 by agraton          ###   ########.fr       */
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

/*
** Basestr: The basic printing functions.
*/

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa_base(long long n, int base);
char	ft_itoc_base(int c, int base);

#endif
