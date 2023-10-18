/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:03:04 by fbelando          #+#    #+#             */
/*   Updated: 2023/10/10 15:03:09 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	unsigned long long		i;
	char					buffer[20];
	int						length;
	unsigned int			temp;
}		t_data;

int		ft_printf(char const *str, ...);
int		ft_parser_pointer(va_list arg, int *total);
int		ft_parser_hexa(va_list arg, int *total, int upper);
int		ft_parser_unsigned_int(va_list arg, int *total);
int		ft_parser_integer(va_list arg, int *total);
int		ft_parser_string(va_list arg, int *total);
int		ft_parser_char(va_list arg, int *total);
int		ft_putnbr_uns(unsigned int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
size_t	ft_(const char *str);

#endif
