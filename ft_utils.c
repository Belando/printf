/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:15:46 by fbelando          #+#    #+#             */
/*   Updated: 2023/10/18 15:15:48 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (0);
}

int	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		if (write (fd, s, 1) == -1)
			return (-1);
		s++;
	}
	return (0);
}

int	ft_putnbr_fd(int n, int fd)
{
	long			num;

	num = n;
	if (num < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		num = num * -1;
	}
	if (num >= 10)
	{
		if (ft_putnbr_fd(num / 10, fd) == -1)
			return (-1);
		if (ft_putnbr_fd(num % 10, fd) == -1)
			return (-1);
	}
	else
		if (ft_putchar_fd(num + '0', fd) == -1)
			return (-1);
	return (0);
}

int	ft_putnbr_uns(unsigned int n, int fd)
{
	long			num;

	num = n;
	if (num >= 10)
	{
		if (ft_putnbr_uns(num / 10, fd) == -1)
			return (-1);
		if (ft_putnbr_uns(num % 10, fd) == -1)
			return (-1);
	}
	else
		if (ft_putchar_fd(num + '0', fd) == -1)
			return (-1);
	return (0);
}
