/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:51:29 by fbelando          #+#    #+#             */
/*   Updated: 2023/10/11 16:51:32 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_char(va_list arg, int *total)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	ft_putchar_fd(i, 1);
	(*total)++;
}

void	ft_parser_string(va_list arg, int *total)
{
	char	*str;

	str = va_arg(arg, char *);
	ft_putstr_fd(str, 1);
	if (!str)
		*total = *total + 0;
	else
		*total = *total + ft_strlen(str);
}

void	ft_parser_integer(va_list arg, int *total)
{
	unsigned int	i;
	unsigned int	temp;
	int				length;

	i = va_arg(arg, unsigned int);
	ft_putnbr_fd(i, 1);
	if (i == 0)
		*total = *total;
	else
	{
		temp = i;
		length = 0;
		while (temp != 0)
		{
			temp /= 10;
			length++;
		}
		*total += length;
	}
}

void	ft_parser_unsigned_int(va_list arg, int *total)
{
	unsigned int	i;
	unsigned int	temp;
	int				length;

	i = va_arg(arg, unsigned int);
	ft_putnbr_fd(i, 1);
	if (i == 0)
		*total = *total;
	else
	{
		temp = i;
		length = 0;
		while (temp != 0)
		{
			temp /= 10;
			length++;
		}
		*total += length;
	}
}