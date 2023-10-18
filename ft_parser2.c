/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:51:19 by fbelando          #+#    #+#             */
/*   Updated: 2023/10/11 16:51:22 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser_hexa(va_list arg, int *total, int upper)
{
	t_data	vars;

	vars.i = va_arg(arg, unsigned int);
	vars.length = 0;
	if (vars.i == 0)
	{
		if (ft_putchar_fd('0', 1) == -1)
			return (-1);
		(*total)++;
	}
	while (vars.i > 0)
	{
		vars.buffer[vars.length++] = "0123456789ABCDEF"[vars.i % 16];
		if (!upper)
			vars.buffer[vars.length - 1] = "0123456789abcdef"[vars.i % 16];
		vars.i /= 16;
	}
	while (vars.length - 1 >= 0)
	{
		if (ft_putchar_fd(vars.buffer[vars.length - 1], 1) == -1)
			return (-1);
		vars.length--;
		(*total)++;
	}
	return (0);
}

int	ft_parser_pointer(va_list arg, int *total)
{
	t_data	vars;

	vars.i = (unsigned long long)va_arg(arg, void *);
	vars.length = 0;
	if (vars.i == 0)
	{
		if (ft_putchar_fd('0', 1) == -1)
			return (-1);
		(*total)++;
	}
	if (vars.i < 0)
		vars.i = UINT_MAX + vars.i + 1;
	while (vars.i > 0)
	{
		vars.buffer[vars.length++] = "0123456789abcdef"[vars.i % 16];
		vars.i /= 16;
	}
	while (vars.length - 1 >= 0)
	{
		if (ft_putchar_fd(vars.buffer[vars.length - 1], 1) == -1)
			return (-1);
		vars.length--;
		(*total)++;
	}
	return (0);
}
