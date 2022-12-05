/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:41:34 by tmejri            #+#    #+#             */
/*   Updated: 2022/05/24 16:40:36 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_pointeur(unsigned long n, char *base);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_base16(unsigned int n, char *base);
int			ft_printf(const char *lettre, ...);
int			ft_adress(unsigned long n, char *base);

#endif