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

int	ft_parser_char(va_list arg, int *total)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	if (ft_putchar_fd(i, 1) == -1)
		return (-1);
	(*total)++;
	return (0);
}

int	ft_parser_string(va_list arg, int *total)
{
	char	*str;

	str = va_arg(arg, char *);
	if (str == NULL)
	{	
		*total += 6;
		if (ft_putstr_fd("(null)", 1) == -1)
			return (-1);
	}
	else
	{
		*total = *total + strlen(str);
		if (ft_putstr_fd(str, 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_parser_integer(va_list arg, int *total)
{
	t_data	vars;
	int		num;

	num = va_arg(arg, int);
	vars.length = 0;
	vars.temp = num;
	if (ft_putnbr_fd(num, 1) == -1)
		return (-1);
	if (num == 0)
		*total += 1;
	else
	{
		if (num < 0)
		{
			vars.temp = -num;
			vars.length++;
		}
		while (vars.temp != 0)
		{
			vars.temp /= 10;
			vars.length++;
		}
		*total += vars.length;
	}
	return (0);
}

int	ft_parser_unsigned_int(va_list arg, int *total)
{
	t_data			vars;
	unsigned int	num;

	num = va_arg(arg, unsigned int);
	vars.length = 0;
	vars.temp = num;
	if (ft_putnbr_uns(num, 1) == -1)
		return (-1);
	if (num == 0)
		*total += 1;
	else
	{
		if (num < 0)
		{
			vars.temp = -num;
			vars.length++;
		}
		while (vars.temp != 0)
		{
			vars.temp /= 10;
			vars.length++;
		}
		*total += vars.length;
	}
	return (0);
}
