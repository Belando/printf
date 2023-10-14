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
		ft_parser_integer(args, total);
	else if (step == 'c')
		ft_parser_char(args, total);
	else if (step == 'u')
		ft_parser_unsigned_int(args, total);
	else if (step == 'x')
		ft_parser_hexa(args, total, 0);
	else if (step == 'X')
		ft_parser_hexa(args, total, 1);
	else if (step == 'i')
		ft_parser_integer(args, total);
	else if (step == 'p')
	{
		ft_putstr_fd("0x", 1);
		(*total) += 2;
		ft_parser_pointer(args, total);
	}
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
				return (va_end(args), total);
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

/*int	main (void)
{
	// int a = printf(" %p \n", LONG_MIN);
	// int b = ft_printf(" %p \n", LONG_MIN);

	// printf("%d\n", a);
	// printf("%d\n", b);
	printf(" %u \n", 0);
	ft_printf(" %u\n ", 0);
	printf(" %u \n", -1);
	ft_printf(" %u\n ", -1);
	printf("%u\n", -200000);
	ft_printf("%u", -200000);
}*/