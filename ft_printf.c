/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:25:07 by fbelando          #+#    #+#             */
/*   Updated: 2023/10/09 16:25:58 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_arg(char step, va_list args, int *total)
{
	if (step == 's')
		ft_parser_string(args, total);
	else if (step == 'd')
		ft_parser_unsigned_int(args, total);
	else if (step == 'c')
		ft_parser_char(args, total);
	else if (step == 'u')
		ft_parser_unsigned_int(args, total);
	else if (step == 'x' || step == 'X')
		ft_parser_hexa(args, total);
	else if (step == 'i')
		ft_parser_integer(args, total);
	else if (step == 'p')
		ft_parser_pointer(args, total);
	else
	{
		ft_putchar_fd(step, 1);
		*total += 1;
	}
}

int	ft_printf(char const *str, ...)
{
	int			total;
	const char	*step;
	va_list		args;

	total = 0;
	va_start(args, str);
	step = str;
	while (*step != '\0')
	{
		while (*step != '%')
		{
			if (*step == '\0')
				return (total);
			ft_putchar_fd(*step, 1);
			step++;
			total++;
		}
		step++;
		ft_parse_arg(*step, args, &total);
		step++;
	}
	va_end(args);
	return (total);
}

/* Pasamos nuestros argumentos variables y el argumento fijo de la función
lista de Argumentos variables, funcionará como un iterador o puntero.
Realiza una limpieza de la estructura*/