/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:36 by tmejri            #+#    #+#             */
/*   Updated: 2022/05/24 16:47:26 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(const char lettre, va_list list)
{
	int		len;

	len = 0;
	if (lettre == 'c')
		len += ft_putchar(va_arg(list, int));
	if (lettre == 's')
		len += ft_putstr(va_arg(list, char *));
	if (lettre == 'p')
		len += ft_adress(va_arg(list, unsigned long), "0123456789abcdef");
	if (lettre == 'd')
		len += ft_putnbr(va_arg(list, int));
	if (lettre == 'i')
		len += ft_putnbr(va_arg(list, int));
	if (lettre == 'u')
		len += ft_putnbr_unsigned(va_arg(list, unsigned int));
	if (lettre == 'x')
		len += ft_base16(va_arg(list, unsigned int), "0123456789abcdef");
	if (lettre == 'X')
		len += ft_base16(va_arg(list, unsigned int), "0123456789ABCDEF");
	if (lettre == '%')
		len += write(1, &"%", 1);
	return (len);
}

int	ft_printf(const char *lettre, ...)
{
	int		len;
	va_list	list;
	int		i;

	len = 0;
	i = 0;
	va_start(list, lettre);
	while (lettre[i])
	{
		if (lettre[i] == '%')
		{
			i++;
			if (lettre[i] == '%')
				len += write(1, &"%", 1);
			else
				len += ft_print_type(lettre[i], list);
		}
		else
			len += write(1, &lettre[i], 1);
		i++;
	}
	va_end(list);
	return (len);
}

// #include <stdio.h>
// int main()
// {
// 	// int p = 5;
// 	// int *d = &p;

// 	ft_printf("");
// 	// ft_printf("%p\n", NULL);
// 	// ft_printf("%d\n", 84);
// 	// ft_printf("%c\n", 114);
// 	//ft_printf("%s\n", NULL);
// 	// ft_printf("%i\n", 84);
// 	// ft_printf("%u\n", 65);
// 	// ft_printf("%x\n", 42);
// 	// ft_printf("%X\n", 42);
// 	// ft_printf("%%\n", d);
// }