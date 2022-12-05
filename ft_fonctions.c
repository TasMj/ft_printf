/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:42:22 by tmejri            #+#    #+#             */
/*   Updated: 2022/05/24 16:31:40 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
	{
		len += ft_putstr("(null)");
		return (len);
	}
	while (s[i])
	{
		len += write (1, &s[i], 1);
		i++;
	}
	return (len);
}

int	ft_pointeur(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_pointeur(n / 16, base);
	len += write(1, (base + (n % 16)), 1);
	return (len);
}

int	ft_adress(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	else
	{
		len += write(1, "0x", 2);
		len += ft_pointeur(n, base);
		return (len);
	}
}
