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

#include "libftprintf.h"

void	print_string(const char *value) //Función para imprimir el contenido, con el tamaño strlen.
{
	write(1, value, strlen(value));
}

int	ft_printf(char const *str, ...)
{
	//cuidadin si te paso "asas%"
	va_list	args; //lista de Argumentos variables, funcionará como un iterador o puntero.

	va_start(args, str); //Pasamos nuestros argumentos variables y el argumento fijo de la función
	while (*str) //Mientras que exista nuestra 
	{
		if (*str == '%')
		{
			str++; //Avanzamos para ver el formato tras %.
			if (*str == 's')
				print_string(va_args(args, int));
			else if (*str == 'd')
				print_string(va_args(args, int));
			else if (*str == 'c')
				print_string(va_args(args, int));
			else if (*str == 'f')
				print_string(va_args(args, int));
			else if (*str == 'x')
				print_string(va_args(args, int));
			else if (*str == 'X')
				print_string(va_args(args, int));
			else
			{
				putchar('%');
				putchar(*str);
			}
		}
		else
			putchar(*str); //Imprimes carácteres normales
		str++;
	}
	va_end (args, str); //Realiza una limpieza de la estructura
}