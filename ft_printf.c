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

int	ft_parse_arg(char step, va_list args, int *total)
{
	if (step == 's')
		return (ft_parser_string(args, total));
	else if (step == 'd' || step == 'i')
		return (ft_parser_integer(args, total));
	else if (step == 'c')
		return (ft_parser_char(args, total));
	else if (step == 'u')
		return (ft_parser_unsigned_int(args, total));
	else if (step == 'x')
		return (ft_parser_hexa(args, total, 0));
	else if (step == 'X')
		return (ft_parser_hexa(args, total, 1));
	else if (step == 'p')
	{
		if (ft_putstr_fd("0x", 1) == -1)
			return (-1);
		(*total) += 2;
		return (ft_parser_pointer(args, total));
	}
	else
	{
		*total += 1;
		return (ft_putchar_fd(step, 1));
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
			if (ft_putchar_fd(*step, 1) == -1)
				return (-1);
			step++;
			total++;
		}
		step++;
		if (ft_parse_arg(*step, args, &total) == -1)
			return (-1);
		step++;
	}
	va_end(args);
	return (total);
}

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