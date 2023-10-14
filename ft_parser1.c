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

void	ft_putnbr_uns(unsigned int n, int fd)
{
	long	num;

	num = n;
	if (num >= 10)
	{
		ft_putnbr_uns(num / 10, fd);
		ft_putnbr_uns(num % 10, fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

void	ft_parser_string(va_list arg, int *total)
{
	char	*str;

	str = va_arg(arg, char *);
	if (str == NULL)
	{	
		*total += 6;
		ft_putstr_fd("(null)", 1);
	}
	else
	{
		*total = *total + ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
}

void	ft_parser_integer(va_list arg, int *total)
{
	int	num;
	int	length;
	int	temp;

	num = va_arg(arg, int);
	length = 0;
	temp = num;
	ft_putnbr_fd(num, 1);
	if (num == 0)
		*total += 1;
	else
	{
		if (num < 0)
		{
			temp = -num;
			length++;
		}
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
	unsigned int	num;
	int				length;
	unsigned int	temp;

	num = va_arg(arg, unsigned int);
	length = 0;
	temp = num;
	ft_putnbr_uns(num, 1);
	if (num == 0)
		*total += 1;
	else
	{
		if (num < 0)
		{
			temp = -num;
			length++;
		}
		while (temp != 0)
		{
			temp /= 10;
			length++;
		}
		*total += length;
	}
}
