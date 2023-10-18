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

int	ft_putchar_fd(char c, int fd)
{
	int	ret;

	ret = write(fd, &c, 1);
	if (ret == (int)-1)
		return (ret);
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
	static int		ret;

	ret = 1;
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
			ret = -1;
	return (ret);
}

int	ft_putnbr_uns(unsigned int n, int fd)
{
	long			num;
	static int		ret;

	num = n;
	ret = 1;
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
	if (ret == 0)
		ret = -1;
	return (ret);
}
