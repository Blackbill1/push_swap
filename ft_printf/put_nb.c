/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 05:59:18 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/18 08:07:01 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		i++;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	i++;
	return (i);
}

int	ft_putnbr_scam(va_list args)
{
	int	n;

	n = va_arg(args, int);
	return (ft_putnbr(n));
}

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putnbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	i++;
	return (i);
}

int	ft_putnbru_scam(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_u(n));
}
