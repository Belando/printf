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
# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct s_data
{
	unsigned int	i;
	char			buffer[20];
	int				length;
	int				j;
}		t_data;

int		ft_printf(char const *str, ...);
void	print_string(const char *value);
void	ft_parser_octal(va_list arg, int *total);
void	ft_parser_pointer(va_list arg, int *total);
void	ft_parser_hexa(va_list arg, int *total);
void	ft_parser_unsigned_int(va_list arg, int *total);
void	ft_parser_integer(va_list arg, int *total);
void	ft_parser_string(va_list arg, int *total);
void	ft_parser_char(va_list arg, int *total);

#endif
