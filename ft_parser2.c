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

void	ft_parser_octal(va_list arg, int *total)
{
	t_data	vars;

	vars.i = va_arg(arg, unsigned int);
	if (vars.i == 0)
	{
		ft_putchar_fd(vars.i, 1);
		(*total)++;
	}
	else
	{
		while (vars.i > 0)
		{
			vars.buffer[vars.length++] = '0' + (vars.i % 8);
			vars.i /= 8;
		}
		vars.j = 0;
		while (vars.j >= 0)
		{
			ft_putchar_fd(vars.buffer[vars.j], 1);
			vars.j--;
		}
		*total = *total + vars.length;
	}
}

void	ft_parser_hexa(va_list arg, int *total)
{
	t_data	vars;

	vars.i = va_arg(arg, unsigned int);
	if (vars.i == 0)
	{
		ft_putchar_fd(vars.i, 1);
		(*total)++;
	}
	else
	{
		while (vars.i > 0)
		{
			vars.buffer[vars.length++] = '0' + (vars.i % 16);
			vars.i /= 16;
		}
		vars.j = 0;
		while (vars.j >= 0)
		{
			ft_putchar_fd(vars.buffer[vars.j], 1);
			vars.j--;
		}
		(*total) = *total + vars.length;
	}
}

void	ft_parser_pointer(va_list arg, int *total)
{
	t_data	vars;

	vars.i = va_arg(arg, unsigned int);
	if (vars.i == 0)
	{
		ft_putstr_fd("0x", 1);
		ft_putchar_fd(vars.i, 1);
		(*total)++;
	}
	else
	{
		while (vars.i > 0)
		{
			vars.buffer[vars.length++] = '0' + (vars.i % 16);
			vars.i /= 16;
		}
		vars.j = 2;
		while (vars.j >= 2)
		{
			ft_putstr_fd("0x", 1);
			ft_putchar_fd(vars.buffer[vars.j], 1);
			vars.j--;
		}
		*total = *total + vars.length + 2;
	}
}
