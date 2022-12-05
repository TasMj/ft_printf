/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:29:24 by tmejri            #+#    #+#             */
/*   Updated: 2022/05/24 16:40:08 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	i;
	int		len;

	len = 0;
	i = n;
	if (i < 0)
	{
		len += ft_putchar('-');
		i *= -1;
	}
	if (i > 9)
	{
		len += ft_putnbr(i / 10);
		len += ft_putnbr(i % 10);
	}
	else
	{
		len += ft_putchar(i + '0');
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	long	i;
	int		len;

	len = 0;
	i = n;
	if (i > 9)
	{
		len += ft_putnbr(i / 10);
		len += ft_putnbr(i % 10);
	}
	else
	{
		len += ft_putchar(i + '0');
	}
	return (len);
}

int	ft_base16(unsigned int n, char *base)
{
	unsigned int	len;

	len = 0;
	if (n >= 16)
		len += ft_base16(n / 16, base);
	len += write(1, (base + (n % 16)), 1);
	return (len);
}
